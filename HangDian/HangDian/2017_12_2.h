//date: 2019/3/6
//author: burnian
//des: сно╥
#pragma once
#include<iostream>
#include<queue>
using namespace std;

void Solution() {
	int n, k;
	queue<int> q;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int id, cnt = 1;
	while (q.size() > 1) {
		id = q.front();
		q.pop();
		if (cnt % k != 0 && cnt % 10 != k) {
			q.push(id);
		}
		cnt++;
	}
	cout << q.front() << endl;
}
