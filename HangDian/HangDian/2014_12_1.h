//date: 2019/2/5
//author: burnian
//des: ÃÅ½ûÏµÍ³
#pragma once
#include<iostream>
#include<vector>
using namespace std;

#define N 1000

void Solution() {
	int n, temp, arr[N] = { 0 };
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
		v.push_back(arr[temp]);
	}
	for (auto a : v) {
		cout << a << " ";
	}
	cout << endl;
}
