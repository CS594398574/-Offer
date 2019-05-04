#include<iostream>
#include<stack>
using namespace std;
template<typename T> class CQueue
{
public:
	//CQueue(void);
	//~CQueue(void);
	void appendTail(const T&node);  //添加
	T deleteHead();   //删除
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T&element) {
	stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead() {
	if (stack2.size() <= 0) {
		while (stack1.size()>0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	if (stack2.size() == 0)throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();
	return head;
}

template<typename T>
T CQueue<T>::Getelement() {
	return stack2.size();
}
void main() {
	CQueue<char> a;
	a.appendTail('v');
	a.appendTail('a');
	a.appendTail('a');
	cout << a.deleteHead() << endl;	
	system("pause");
}
