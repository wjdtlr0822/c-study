//atomic 원자성!
#include<atomic>
#include<iostream>
#include<thread>
#include<vector>

using namespace std;

void worker(atomic<int>& counter) {
	for (int i = 0; i < 10000; i++) counter++;
}

int main() {
	atomic<int> counter(0);

	vector<thread> vec;
	for (int i = 0; i < 4; i++)
	{
		vec.push_back(thread(worker, ref(counter)));
	}

	for (int i = 0; i < 4; i++) vec[i].join();

	cout << "counter 최종값 : " << counter << endl;
}