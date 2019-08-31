//date: 2019/1/18
//author: burnian
//des: 出现次数最多的数
#pragma once
#include<iostream>
#include<map>
using namespace std;

void Solution() {
	size_t n, temp, result, max = 0;
	map<size_t, size_t> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m[temp]++;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			result = it->first;
			max = it->second;
		}
	}
	cout << result << endl;
}
