//date: 2019/3/4
//author: burnian
//des: —ß…˙≈≈∂”
#pragma once
#include<iostream>
#include<list>
using namespace std;

void Solution() {
	int n, m;
	list<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push_back(i);
	cin >> m;
	int id, move;
	for (int i = 0; i < m; i++) {
		cin >> id >> move;
		for (auto it = q.begin(); it != q.end(); it++) {
			if (*it == id) {
				auto temp = it++;
				q.erase(temp);
				if (move > 0) {
					while (move != 0) {
						move--;
						it++;
					}
				}
				else {
					while (move != 0) {
						move++;
						it--;
					}
				}
				q.insert(it, id);
				break;
			}
		}
#ifdef _DEBUG
		for (auto v : q) {
			cout << v << " ";
		}
		cout << endl;
#endif _DEBUG
	}
	for (auto v : q) {
		cout << v << " ";
	}
	cout << endl;
}
