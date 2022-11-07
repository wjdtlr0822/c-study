#include<chrono>
#include<condition_variable>
#include<cstdio>
#include<functional>
#include<mutex>
#include<queue>
#include<thread>
#include<vector>
#include<future>

using namespace std;

namespace ThreadPool {
	class ThreadPool {
		public:
			ThreadPool(size_t num_threads);
			~ThreadPool();

			template <typename F,typename... Args>
			future<typename result_of<F(Args...)>::type> EnqueueJob(F &&f, Args&&... args);
			//불필요한 복사를 야기하므로 완벽한 전달 패턴을 사용
			// 함수의 인자들을 우측값 래퍼런스로 바꾼다.

			void EnqueueJob(function<void()> job);

		private:
			size_t num_threads_;
			vector<thread> worker_threads_;
			queue<function<void()>> jobs_;
			condition_variable cv_job_q_;
			mutex m_job_q_;

			bool stop_all;

			void WorkerThread();
	};

	ThreadPool::ThreadPool(size_t num_threads) : num_threads_(num_threads), stop_all(false) {
		worker_threads_.reserve(num_threads_);
		for (size_t i = 0; i < num_threads_; ++i) {
			worker_threads_.emplace_back([this]() { this->WorkerThread(); });
		}
	}

	void ThreadPool::WorkerThread() {
		while (true) {
			unique_lock<mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this] { return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) {
				return;
			}

			function<void()> job = move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			job();
		}
	}

	ThreadPool::~ThreadPool() {
		stop_all = true;
		cv_job_q_.notify_all();
		for (auto& t : worker_threads_) t.join();
	}

	template <typename F, typename... Args>
	future<typename result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F &&f, Args&&... args) {
		if (stop_all) {
			throw runtime_error("ThreadPool 사용 중지됨");
		}
		using return_type = typename result_of<F(Args...)>::type;

		auto job = make_shared<packaged_task<return_type()>>(bind(forward<F>(f),forward<Args>(args)...));
		//forward로 인자를 전달해준다.

		future<return_type> job_result_future = job->get_future();
		{
			lock_guard<mutex> lock(m_job_q_);
			jobs_.push([job]() { (*job)(); });
		}

		cv_job_q_.notify_one();

		return job_result_future;
	}


	//void ThreadPool::EnqueueJob(function<void()> job) {
	//	if (stop_all) throw runtime_error("ThreadPool 사용 중지됨.");
	//	{
	//		lock_guard<mutex> lock(m_job_q_);
	//		jobs_.push(move(job));
	//	}
	//	cv_job_q_.notify_one();
	//}

} // namespace ThreadPool

void work(int t, int id) {
	printf("%d start \n", id);
	this_thread::sleep_for(chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
}


int main() {
	ThreadPool::ThreadPool pool(3);

	for (int i = 0; i < 10; i++) pool.EnqueueJob([i] {work(i % 3 + 1, i); });
}