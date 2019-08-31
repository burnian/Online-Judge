//date: 2019/3/5
//author: burnian
//des: 公共钥匙盒
#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

// 另一种方法，优先队列把所有优先级都排好，每次取一个操作进行模拟，从而得出结果
//struct Node {
//	int keyID;
//	char type; // 'g'-取操作，'r'-还操作
//	int time;
//	bool operator < (const Node node) const {
//		if (time != node.time)
//			return time > node.time;
//		else if (type != node.type)
//			return type < node.type;
//		else
//			return keyID > node.keyID;
//	}
//};

struct Key {
	int id;
	Key(int a) :id(a) {}
	// 优先队列同号大根，异号小根
	bool operator < (const Key& k) const {
		return id > k.id;
	}
};

void Solution() {
	int n, m, id, ts, td;
	vector<int> keyBox; // 钥匙空位-钥匙编号
	map<int, priority_queue<Key>[2]> moves; // 0是取钥匙，1是还钥匙
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		keyBox.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> ts >> td;
		moves[ts][0].push(id);
		moves[ts + td][1].push(id);
	}
	for (auto &v : moves) {
		auto ret = v.second[1];
		int i = 0;
		while (!ret.empty()) { // ret不为空则box一定有空位
			while (keyBox[i] != 0)
				i++;
			keyBox[i] = ret.top().id;
			ret.pop();
		}
		auto take = v.second[0];
		while (!take.empty()) {
			int temp = take.top().id;
			for (int &vv : keyBox) {
				if (vv == temp) {
					vv = 0;
					break;
				}
			}
			take.pop();
		}
	}
	for (int v : keyBox) {
		cout << v << " ";
	}
	cout << endl;
}
