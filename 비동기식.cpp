#include<future>
#include<iostream>
#include<string>
#include<thread>

using namespace std;

void worker(promise<string>* p) {
	p->set_value("data set success!!");
}

int main() {
	promise<string> p;
	future<string> data = p.get_future();

	thread a(worker, &p);

	data.wait();

	cout << "받은 데이터는 : " << data.get() << endl;
	a.join();
}