#include<string>
#include<iostream>
using namespace std;
/*
函数模板就是一个公式，可以用来生成特定类型的函数版本。
下面例子就是利用函数模板对完成不同数据类型数据进行大小比较。
*/

/*

Example1：函数模板

*/
template <typename T>
T compare(const T &v1, const T &v2) {
	 return  v1 > v2 ? v1 :  v2;
}

int main()
{

	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << compare(i, j) << endl;
	
	double f1 = 13.5;
	double f2 = 20.7;
	cout << "max(f1, f2): " << compare(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << compare(s1, s2) << endl;

	system("pause");
	return 0;
}

/*

类模板   //类模板是用来生成类的蓝图与模板函数不同的是，编译器不能为类模板推断模板参数类型。
        //为了使用类模板，我们必须在模板名后面提供额外的信息。

*/
/*
    正如我们定义函数模板一样，我们也可以定义类模板。泛型类声明的一般形式如下所示：
    template <class type> class class-name{

    }

*/

template <class T>
class Stack {
private:
	vector<T> elems;     // 元素 

public:
	void push(T const&);  // 入栈
	void pop();               // 出栈
	T top() const;            // 返回栈顶元素
	bool empty() const {       // 如果为空则返回真。
		return elems.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	// 追加传入元素的副本
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	// 删除最后一个元素
	elems.pop_back();
}


template <class T> T Stack<T>::top() const
{
	if (elems.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	// 返回最后一个元素的副本 
	return elems.back();
}

int main()
{
	try {
		Stack<int>         intStack;  // int 类型的栈 
		Stack<string>      stringStack;    // string 类型的栈 

									  // 操作 int 类型的栈 
		intStack.push(7);
		cout << intStack.top() << endl;
		// 操作 string 类型的栈 
		stringStack.push("hello");
		cout << stringStack.top() << std::endl;
		stringStack.pop();
		stringStack.pop();
		system("pause");
	}
	catch (exception const& ex) {
		cerr << "Exception: " << ex.what() << endl;
		system("pause");
		return -1;
	}
	
}
