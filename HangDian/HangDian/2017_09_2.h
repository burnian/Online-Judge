//date: 2019/3/5
//author: burnian
//des: ����Կ�׺�
#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

// ��һ�ַ��������ȶ��а��������ȼ����źã�ÿ��ȡһ����������ģ�⣬�Ӷ��ó����
//struct Node {
//	int keyID;
//	char type; // 'g'-ȡ������'r'-������
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
	// ���ȶ���ͬ�Ŵ�������С��
	bool operator < (const Key& k) const {
		return id > k.id;
	}
};

void Solution() {
	int n, m, id, ts, td;
	vector<int> keyBox; // Կ�׿�λ-Կ�ױ��
	map<int, priority_queue<Key>[2]> moves; // 0��ȡԿ�ף�1�ǻ�Կ��
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
		while (!ret.empty()) { // ret��Ϊ����boxһ���п�λ
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
