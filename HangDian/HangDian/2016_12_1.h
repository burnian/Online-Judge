//date: 2019/2/28
//author: burnian
//des: 中间数
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
 			ret = it->first; // 当n为偶数个，第mid个数进来时左边有mid-1个，右边有mid个，所以最后一个数会第二次进来
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
