//date: 2019/3/5
//author: burnian
//des: ×îÐ¡²îÖµ
#pragma once
#include<iostream>
#include<map>
using namespace std;

#define MAX 10000

void Solution() {
	int n, temp, ret = MAX;
	map<int, int> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m[temp]++;
	}
	int last = 0;
	for (auto &v : m) {
		if (v.second > 1) {
			ret = 0;
			break;
		}
		else if (last > 0) {
			temp = v.first - last;
			if (temp < ret) {
				ret = temp;
			}
		}
		last = v.first;
	}
	cout << ret << endl;
}
