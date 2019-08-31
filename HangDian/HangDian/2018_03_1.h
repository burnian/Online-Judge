//date: 2019/3/6
//author: burnian
//des: ÌøÒ»Ìø
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n, sum = 0, last = 1;
	while (cin >> n) {
		if (n <= 0)
			break;
		if (n >= 2 && last >= 2) {
			n += last;
		}
		last = n;
		sum += n;
	}
	cout << sum << endl;
}
