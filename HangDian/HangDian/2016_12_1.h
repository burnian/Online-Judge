//date: 2019/2/28
//author: burnian
//des: �м���
#pragma once
#include<iostream>
#include<map>
using namespace std;

void Solution() {
	int n, temp, mid, left, ret, cnt = 0;
	map<int, int> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m[temp]++;
	}
	mid = (n + 1) / 2;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (cnt + it->second >= mid) {
 			ret = it->first; // ��nΪż��������mid��������ʱ�����mid-1�����ұ���mid�����������һ������ڶ��ν���
			left = cnt;
			cnt = 0;
		}
		else {
			cnt += it->second;
		}
	}
	if (left == cnt)
		cout << ret << endl;
	else
		cout << -1 << endl;
}
