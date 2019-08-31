//date: 2019/2/9
//author: burnian
//des: ÊýÁÐ·Ö¶Î
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n, temp, seg = -1, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (seg != temp) {
			seg = temp;
			result++;
		}
	}
	cout << result << endl;
}
