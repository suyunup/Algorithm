#include<iostream>
using namespace std;
const int INFINITE = 1000000000;

int rodcuttingNaive(int n, int* price,int* r) {
	if (n <1) { return 0; }
	int temp = price[n];
	for (int i = 1; i < n; i++) {
		if (temp < rodcuttingNaive(i, price, r) + rodcuttingNaive(n - i, price, r)) 
			temp = rodcuttingNaive(i, price, r) + rodcuttingNaive(n - i, price, r);
	}
	r[n] = temp;
	return temp;
}

int* BottomUpFashion(int n, int* price) { 
	int* r = new int[n + 1];
	r[0] = 0; //too obvious
	int temp;
	for (int i = 1; i <= n; i++) {
		temp = -INFINITE;
		for (int j = 0; j <= i; j++) {
			if (temp < price[j] + r[i - j]) temp = price[j] + r[i - j];
		}
		r[i] = temp;
	}
	return r;
}

int main() {
	int p[] = {0, 1,5,8,9,10,17,17,20,24,30 };
	int* r = new int[11];
	//(1) Test Naive Solution
	rodcuttingNaive(10, p, r);
	for (int i = 1; i < 11; i++) {
		cout << "r[" << i << "]: " << r[i] << endl;
	}
	//(2) Test Bottom Up Fashion
	int* k = BottomUpFashion(10, p);
	for (int i = 1; i < 11; i++) {
		cout << "k[" << i << "]: " << k[i] << endl;
	}
	delete k;
}