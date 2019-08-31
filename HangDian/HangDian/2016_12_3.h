//date: 2019/3/4
//author: burnian
//des: »®œﬁ≤È—Ø
#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

void Solution() {
	int m, n, level;
	string name, temp;
	vector<string> privileges;
	map<string, vector<string> > roles;
	map<string, vector<string> > users;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		privileges.push_back(name);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			roles[name].push_back(temp);
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> m;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			users[name].push_back(temp);
		}
	}

	cin >> n;
	string prName;
	int pos, prLv;
	for (int i = 0; i < n; i++) {
		cin >> name >> temp;
		if (users.find(name) != users.end()) {
			pos = temp.find(":");
			if (pos != string::npos) {
				prName = temp.substr(0, pos);
				prLv = temp[pos + 1] - '0';
			}
			else {
				prName = temp;
				prLv = -1;
			}
			int maxLv = -1;
			bool flag = false;
			auto userRoles = users[name];
			for (auto it = userRoles.begin(); !flag && it != userRoles.end(); it++) {
				auto rolePr = roles[*it];
				for (auto itt = rolePr.begin(); !flag && itt != rolePr.end(); itt++) {
					string pr = *itt;
					if (pr.find(prName) != string::npos) {
						pos = pr.find(":");
						if (pos != string::npos) {
							int temp = pr[pos + 1] - '0';
							if (maxLv < temp)
								maxLv = temp;
						}
						else {
							cout << (prLv < 0 ? "true" : "false") << endl;
							flag = true;
						}
					}
				}
			}
			if (!flag) {
				if (maxLv >= 0) {
					if (prLv < 0)
						cout << maxLv << endl;
					else
						cout << (prLv <= maxLv ? "true" : "false") << endl;
				}
				else {
					cout << "false" << endl;
				}
			}
		}
		else {
			cout << "false" << endl;
		}
	}
}
