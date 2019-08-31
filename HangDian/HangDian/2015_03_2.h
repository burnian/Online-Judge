//date: 2019/2/7
//author: burnian
//des: Êý×ÖÅÅÐò
#pragma once
#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct Node {
	int key;
	int value;
	bool operator <(const Node& n) const {
		if (value == n.value)
			return key > n.key;
		else
			return value < n.value;
	}
};

void Solution() {
	int n, temp;
	map<int, int> m;
	priority_queue<Node> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		m[temp]++;
	}
	Node node;
	for (auto it = m.begin(); it != m.end(); it++) {
		node.key = it->first;
		node.value = it->second;
		q.push(node);
	}
	while (!q.empty()) {
		node = q.top();
		cout << node.key << " " << node.value << endl;
		q.pop();
	}
}
