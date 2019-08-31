//date: 2019/2/24
//author: burnian
//des: ×î´ó²¨¶¯
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n, last, cur, wave, max = 0;
	cin >> n;
	cin >> last;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		wave = abs(cur - last);
		if(wave > max)
			max = wave;
		last = cur;
	}
	cout << max << endl;
}
