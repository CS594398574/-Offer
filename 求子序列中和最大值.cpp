#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

template<typename T> 
class DynamicArray {
public:
	void Insert(T num) {   //如果数据流是偶数，新数据插入最小堆，奇数时插入最大堆。
		if (((min.size() + max.size()) & 1) == 0) {   //当总数为偶数，新数据插入最小堆，可能该数据比最大堆一些数字要小。
													  //那么取出来放到最大堆，且最大堆数据最大放到最小堆
			if (max.size() > 0 && num < max[0]) {   
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());  //less是最大堆

				num = max[0];
				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());  //greater是最小堆
		}
		else {
			if (min.size() > 0 && min[0] < num) {
				min.push_back(num);
				push_heap(min.begin(), min.end(),greater<T>());

				num = min[0];
				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian() {
	
		int size = min.size() + max.size();
		if (size == 0) {
			throw exception("No numbers are available");
		}
		T median = 0;
		if ((size & 1) == 1)  //如果总数是奇数
			median = min[0];
		else
			median = (min[0] + max[0]) / 2; //如果总数是偶数
		return median;
	}
private:
	vector<T> min;   //做成一个最小堆
	vector<T> max;   //做成一个最大堆
};

void Test(char* testName, DynamicArray<double> &numbers, double expected) {
	if (testName != nullptr) cout << testName << "begins:";
	if (abs(numbers.GetMedian() - expected) < 0.000001)
		cout << "Passed" <<"..........."<<numbers.GetMedian()<<endl;
	else
		cout << "FAILED" << endl;
}
int main(int argc, char* argv[]) {
	DynamicArray<double> numbers;
	cout << "Test1 begins:" << endl;
	try{
		numbers.GetMedian();
		cout << "Failed" << endl;
	}
	catch (const exception&) {
		cout << "passed" <<"    "<<endl;
	}

	numbers.Insert(5);
	Test("Test2", numbers, 5);

	numbers.Insert(2);
	Test("Test3", numbers, 3.5);

	numbers.Insert(3);
	Test("Test4", numbers, 3);

	numbers.Insert(4);
	Test("Test6", numbers, 3.5);

	numbers.Insert(1);
	Test("Test5", numbers, 3);

	numbers.Insert(6);
	Test("Test7", numbers, 3.5);

	numbers.Insert(7);
	Test("Test8", numbers, 4);

	numbers.Insert(0);
	Test("Test9", numbers, 3.5);

	numbers.Insert(8);
	Test("Test10", numbers, 4);

	return 0;
}