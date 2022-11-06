#include<chrono>
#include<string>
#include<mutex>
#include<queue>
#include<iostream>
#include<thread>
#include<vector>
#include<condition_variable>

using namespace std;


void producer(queue<string> *downloaded_pages, mutex *m, int index, condition_variable *cv) {
	for (int i = 0; i < 5; i++) {
		this_thread::sleep_for(chrono::milliseconds(100 * index));
		string content = "웹사이트 : " + to_string(i) + " from thread ( " + to_string(index) + ")\n";

		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		cv->notify_one(); // consumer에게 content가 준비되었다고 알려준다.
	}
}

void consumer(queue<string>* downloaded_pages, mutex* m, int* num_processed, condition_variable* cv) {
	while (*num_processed < 25) {
		unique_lock<mutex> lk(*m); //lock_guard를 아닌 unique_lock을 쓴 이유는 wait에서 인자값으로 unique_lock을 받는다.

		cv->wait(lk, [&] { return !downloaded_pages->empty() || *num_processed == 25; });
		// wait에 어떤 조건이 참이 될 때 까지 기다릴지 해당 조건을 인자로 전달해야한다.
		//조건이 false일 경우 lk를 unlock한 뒤 sleep하게 된다.
		//조건이 true일 경우 그대로 return한다.

		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();
		cout << content;
		this_thread::sleep_for(chrono::microseconds(80));
	}
}

int main() {
	queue<string> downloaded_pages;
	mutex m;
	condition_variable cv;
	vector<thread> consumers;
	vector<thread> producers;
	int num_processed = 0;

	for (int i = 0; i < 5; i++) {
		producers.push_back(thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	
	for (int i = 0; i < 3; i++){
		consumers.push_back(thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}

	for (int i = 0; i < 5; i++) producers[i].join();
	cv.notify_all(); 
	//producer들이 모두 일을 끝낸 시점에서, 일부 자고있는 consumer쓰레드들이 join되지 않기 때문에 모두 깨워야한다.
	for (int i = 0; i < 3; i++) consumers[i].join();
}