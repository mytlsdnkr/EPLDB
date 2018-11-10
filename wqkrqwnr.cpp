#include <iostream>

using namespace std;

int floor1(double num) {
	int temp1;
	if (num == 0)
		return num;
	if (num > 0)
		return num;

	if (num < 0) {
		temp1 = num * 10;
		if ((temp1 % 2) == 0 || (temp1 % 2) == 1)
			return num-1;
		else
			return num - 1;
		

	}
}

int ceiling(double num) {
	int temp;
	if (num == 0)
		return num;

	if (num > 0) {
		temp = num * 10;
		if (temp % 2 == 0)
			return num+1;
		else
			return num + 1;
		
	}

	if (num < 0)
		return num;
}

int main(void) {
	double a;
	cout << "실수 입력:";
	cin >> a;
	cout<<"Floor:" << floor1(a) << endl;

	cout <<"Ceiling:"<< ceiling(a) << endl;
	return 0;
}
