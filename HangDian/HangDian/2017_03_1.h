//date: 2019/3/4
//author: burnian
//des: ·Öµ°¸â
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n, k, temp, sum = 0, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if ((sum += temp) >= k) {
			sum = 0;
			cnt++;
		}
	}
	if (sum > 0) cnt++;
	cout << cnt << endl;
}
