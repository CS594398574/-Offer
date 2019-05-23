#include<iostream>
#include<string>
//using namespace std;   //static��̬����count��������ͻ��

static int c = 0;
void swap(char *str, int a, int b) {
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
	
}

int is_swap(char *str, int begin, int k) {   //�ж��ִ��ĵ�һ���ַ�����ʼ��һֱ��k-1λ�ã����Ƿ����ظ��ַ�
	int i, flag;
	for (i = begin, flag = 1; i < k; i++) {
		if (str[i] == str[k]) {
			flag = 0;
			break;
		}		
	}
	return flag;
}

void full_permutation(char* str, int begin, int end) {  //�����ַ������������������ַ�����
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