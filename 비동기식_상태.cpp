#include<chrono>
#include<exception>
#include<future>
#include<iostream>
#include<string>
#include<thread>

using namespace std;

void worker(promise<void>* p) {
	this_thread::sleep_for(chrono::seconds(10));
	p->set_value();
}


int main() {
	promise<void> p;
	future<void> data = p.get_future();

	thread t(worker, &p);

	while (true) {
		future_status status = data.wait_for(chrono::seconds(1));

		if (status == future_status::timeout) cout << ">";
		if (status == future_status::ready) {
			cout << " SUCCESS!!!!" << endl; break;
		}
	}
	t.join();
}