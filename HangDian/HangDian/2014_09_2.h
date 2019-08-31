//date: 2019/2/1
//author: burnian
//des: »­Í¼
#pragma once
#include<iostream>
using namespace std;

#define N 100

void Solution() {
	int n, x1, x2, y1, y2, sum = 0;
	bool flag[N][N] = { false };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				if (!flag[j][k]) {
					flag[j][k] = true;
					sum++;
				}
			}
		}
	}
	cout << sum << endl;
}
