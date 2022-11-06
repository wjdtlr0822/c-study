#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
using namespace std;

void worker(int& counter,mutex &m) {
	for (int i = 0; i < 10000; i++) {
        lock_guard<mutex> lock(m);
		// m.lock();
		counter += 1;
		// m.unlock();
	}
}


int main() {
	int counter = 0;
	mutex m;

	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.push_back(thread(worker, ref(counter),ref(m)));
	}

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}

	cout << "COUNTER : " << counter << endl;
}

//뮤텍스를 사용하면 lock을 걸었을 때 m을 소유한 쓰레드가 m.unlock()을 통해 m을 반환할 때 까지 다른 쓰레드가 기다린다.
//뮤텍스를 쓰지 않으면 counter+=1과정에서 쓰레드가 동시에 사용을 하다보면 결과가 다르게 나올수 있다.

//m.lock(), m.unlock() 사이에 한 쓰레드만이 유일하게 실행할수 있는 코드 부분을 임계영역이라고 한다.