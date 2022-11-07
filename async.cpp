#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int sum(const vector<int>& v, int start, int end) {
	int total = 0;
	for (int i = start; i < end; i++) {
		total += v[i];
	}
	return total;
}


int parallel_sum(vector<int>& v) {
	future<int> lower_half_future = async(launch::async, sum, cref(v), 0, v.size() / 2);
	//launch::async : 쓰레드를 생성해서 인자로 전달된 함수를 실행한다.
	//launch::deferred : future의 get 함수가 호출되었을 때 실행한다.(새로운 쓰레드를 생성하지 않음) (동기식)
	int upper_half = sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half;
}


int main() {
	vector<int> vec;
	vec.reserve(1000);

	for (int i = 0; i < 1000; i++) vec.push_back(i + 1);

	cout << "합은 : " << parallel_sum(vec) << endl;
}

//async를 사용하면 쓰레드를 명시적으로 생성해서 실행하지 않아도 알아서 쓰레드를 만들어서 해당 함수를 비동기적으로 실행한다.