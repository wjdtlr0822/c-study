#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

//void worker1(mutex& m1, mutex& m2) {
//	for (int i = 0; i < 10000; i++) {
//		lock_guard<mutex> lock(m1);
//		lock_guard<mutex> lock(m2);
//	}
//}
//
//
//void worker2(mutex& m1, mutex& m2) {
//	for (int i = 0; i < 10000; i++) {
//		lock_guard<mutex> lock(m2);
//		lock_guard<mutex> lock(m1);
//	}
//}
//deadlock 발생!!!

void worker1(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        m1.lock();
        m2.lock();
        std::cout << "Worker1 Hi! " << i << std::endl;

        m2.unlock();
        m1.unlock();
    }
}

void worker2(std::mutex& m1, std::mutex& m2) {
    for (int i = 0; i < 10; i++) {
        while (true) {
            m2.lock();

            if (!m1.try_lock()) { // lock()할 수 있으면 lock()을 하고 true를 반환.
                m2.unlock();
                continue;
            }

            std::cout << "Worker2 Hi! " << i << std::endl;
            m1.unlock();
            m2.unlock();
            break;
        }
    }
}


int main() {
	int counter = 0;
	mutex m1, m2;

	thread t1(worker1, ref(m1), ref(m2));
	thread t2(worker2, ref(m1), ref(m2));

	t1.join();
	t2.join();

	cout << "endl" << endl;
}

// 중첩된 Lock 을 사용하는 것을 피해라
// 모든 쓰레드들이 최대 1 개의 Lock 만을 소유한다면 (일반적인 경우에) 데드락 상황이 발생하는 것을 피할 수 있습니다. 또한 대부분의 디자인에서는 1 개의 Lock 으로도 충분합니다. 만일 여러개의 Lock 을 필요로 한다면 정말 필요로 하는지 를 되물어보는 것이 좋습니다.

// Lock 을 소유하고 있을 때 유저 코드를 호출하는 것을 피해라
// 사실 이 가이드라인 역시 위에서 말한 내용과 자연스럽게 따라오는 것이긴 한데, 유저 코드에서 Lock 을 소유할 수 도 있기에 중첩된 Lock 을 얻는 것을 피하려면 Lock 소유시 유저 코드를 호출하는 것을 지양해야 합니다.

// Lock 들을 언제나 정해진 순서로 획득해라
// 만일 여러개의 Lock 들을 획득해야 할 상황이 온다면, 반드시 이 Lock 들을 정해진 순서로 획득해야 합니다. 우리가 앞선 예제에서 데드락이 발생했던 이유 역시, worker1 에서는 m1, m2 순으로 lock 을 하였지만 worker2 에서는 m2, m1 순으로 lock 을 하였기 때문이지요. 만일 worker2 에서 역시 m1, m2 순으로 lock 을 하였다면 데드락은 발생하지 않았을 것입니다.