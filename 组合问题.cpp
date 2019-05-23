#include<iostream>
#include<string>
//using namespace std;   //static静态变量count会引发冲突。

static int c = 0;
void swap(char *str, int a, int b) {
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
	
}

int is_swap(char *str, int begin, int k) {   //判断字串的第一个字符串开始，一直到k-1位置，看是否有重复字符
	int i, flag;
	for (i = begin, flag = 1; i < k; i++) {
		if (str[i] == str[k]) {
			flag = 0;
			break;
		}		
	}
	return flag;
}

void full_permutation(char* str, int begin, int end) {  //利用字符串输出流，输出的是字符串。
	if (begin == end) {
		std::cout << str << std::endl;
		c = c + 1;
		return;
	}
	else {
		int i;
		for (i = begin; i <= end; i++) {
			if (is_swap(str, begin, i)) {
				swap(str,begin,i);
				full_permutation(str,begin+1,end);
				swap(str, begin, i);
			}
		}
	}
}
int main() {
	char str[7] = { 'a','l','i','b','a','b','a' };
	full_permutation(str, 0, 6);
	printf("count%d", c);
	return 0;
}