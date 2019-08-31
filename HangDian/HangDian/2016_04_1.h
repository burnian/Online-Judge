//date: 2019/2/23
//author: burnian
//des: ÕÛµã¼ÆÊı
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n, a[3], start, middle, end, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i % 3];
		if (i > 1) {
			start = (i - 2) % 3;
			middle = (i - 1) % 3;
			end = i % 3;
			if ((a[start]<a[middle] && a[middle]>a[end]) || (a[start]>a[middle] && a[middle]<a[end])) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}
