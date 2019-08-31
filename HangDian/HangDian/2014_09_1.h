//date: 2019/2/1
//author: burnian
//des: ÏàÁÚÊı¶Ô
#pragma once
#include<iostream>
using namespace std;

#define N 10000

void Solution() {
	bool flag[N + 1] = { false };
	int n, temp, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		flag[temp] = true;
		if (temp - 1 >= 0 && flag[temp - 1])
			sum++;
		if (temp + 1 <= N && flag[temp + 1])
			sum++;
	}
	cout << sum << endl;
}
