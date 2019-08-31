//date: 2019/2/24
//author: burnian
//des: 火车购票
#pragma once
#include<iostream>
#include<map>
using namespace std;

#define ROW 6
#define SEAT 5

void Solution() {
	int n, cnt, start, end;
	map<int, int> m;
	for (int i = 1; i <= ROW; i++) {
		m[i] = SEAT;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cnt;
		// 优先安排邻座
		for (auto it = m.begin(); it != m.end(); it++) {
			if (it->second >= cnt) {
				start = (it->first - 1) * SEAT + SEAT - it->second + 1;
				end = start + cnt - 1;
				for (int j = start; j <= end; j++) {
					cout << j << " ";
				}
				if (it->second == cnt)
					m.erase(it);
				else
					it->second -= cnt;
				cnt = 0;
				break;
			}
		}
		// 其次安排散座
		while (!m.empty() && cnt > 0) {
			auto it = m.begin();
			start = (it->first - 1) * SEAT + SEAT - it->second + 1;
			if (it->second <= cnt) {
				end = it->first * SEAT;
				cnt -= it->second;
				m.erase(it);
			}
			else {
				end = start + cnt - 1;
				it->second -= cnt;
				cnt = 0;
			}
			for (int j = start; j <= end; j++) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
