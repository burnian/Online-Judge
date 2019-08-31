//date: 2019/2/17
//author: burnian
//des: 数位之和
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	size_t n, sum = 0;
	cin >> n;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	cout << sum << endl;
}
