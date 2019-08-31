//date: 2019/1/17
//author: burnian
//des: 对于给定函数f，求f(n)
#pragma once
#include<iostream>
using namespace std;

size_t A, B;

size_t f(size_t n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return (A * f(n - 1) + B * f(n - 2)) % 7;
}

void Solution() {
	size_t n;
	while (cin >> A >> B >> n && (A != 0 || B != 0 || n != 0)) {
		cout << f(n % 49) <<endl;
	}
}
