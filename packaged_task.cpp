#include<future>
#include<thread>
#include<iostream>

using namespace std;

int pack_task(int x) { return 10 + x; }

int main() {
	packaged_task<int(int)> task(pack_task);
	future<int> start = task.get_future();

	thread t(move(task), 5); // move를 사용하는 이유는 복사생성자가 없기때문에

	cout << start.get() << endl;
	t.join();
}

//packaged_task는 비동기식으로 함수를 처리하기위해 사용한다.