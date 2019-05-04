#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class CQStack {
public:
	void appendTail(const T&node);
	T deleteTop();	
private:
	queue<T> queue1;
	queue<T> queue2;
};

template<typename T>
void CQStack<T>::appendTail(const T&node) {  //往不为空的队列中加入元素。
	if (!queue1.empty())
		queue1.push(node);
	else
		queue2.push(node);
}
template<typename T>
T CQStack<T>::deleteTop() {
	T ret;
	if (!queue1.empty()) {
		int num = queue1.size();
		while (num > 1) {
			T &data = queue1.front();
			queue2.push(data);
			queue1.pop();
			--num;
		}
		 ret = queue1.front();
		queue1.pop();
	}
	else {
		int num = queue2.size();
		while (num > 1) {
			T &data = queue2.front();
			queue1.push(data);
			queue2.pop();
			--num;
		}
		 ret = queue2.front();  //得到最后一个元素。
		queue2.pop();
	}
	return ret;
}

void main() {
	CQStack<char> a;
	a.appendTail('v');
	a.appendTail('a');
	cout << a.deleteTop() << endl;
	system("pause");
}