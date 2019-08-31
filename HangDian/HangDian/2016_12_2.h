//date: 2019/2/28
//author: burnian
//des: 工资计算
#pragma once
#include<iostream>
using namespace std;

// 阶段税率的补
int rate[] = { 0,3,10,20,25,30,35,45 };
// 阶段税后工资上限
int range[] = { 0,3500,3500 + 1500,3500 + 4500,3500 + 9000,3500 + 35000,3500 + 55000,3500 + 80000 };
// 阶段数
const int STAGES = sizeof(range) / sizeof(int);

void Solution() {
	int n, ret, limit[STAGES] = { 0 };
	cin >> n;
	for (int i = 1; i < STAGES; i++) {
		limit[i] = limit[i - 1] + (range[i] - range[i - 1])*(100 - rate[i - 1]) / 100;
		cout << i<<" "<<limit[i] << endl;
	}
	for (int i = 0; i < STAGES; i++) {
		if (i + 1 >= STAGES || n <= limit[i + 1]) {
			ret = range[i] + (n - limit[i]) * 100 / (100 - rate[i]);
			break;
		}
	}
	cout << ret << endl;
}
