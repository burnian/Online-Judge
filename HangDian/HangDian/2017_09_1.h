//date: 2019/3/5
//author: burnian
//des: ¥ÚΩ¥”Õ
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n;
	cin >> n;
	n /= 10;
	cout << n + n / 5 * 2 + n % 5 / 3 << endl;
}
