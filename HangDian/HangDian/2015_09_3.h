//date: 2019/2/13
//author: burnian
//des: 模板生成系统
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

const string delimiter = "{{ ";

void Solution() {
	int col, cnt;
	cin >> col >> cnt;
	cin.get();
	string str;
	vector<string> content;
	for (int i = 0; i < col; i++) {
		getline(cin, str);
		content.push_back(str);
	}
	string key, value;
	map<string, string> var;
	for (int i = 0; i < cnt; i++) {
		cin >> key >> value;
		var[key] = value.substr(1, value.length() - 2);
	}
	for (auto it = content.begin(); it != content.end(); it++) {
		size_t pos = (*it).find(delimiter);
		while (pos != string::npos) {
			size_t start = pos + delimiter.length();
			size_t end = (*it).find(" ", start);
			size_t keyLen = end - start;
			key = (*it).substr(start, keyLen);
			(*it).replace(pos, keyLen + delimiter.length() * 2, var[key]);
			pos = (*it).find(delimiter, pos + var[key].length());
		}
		cout << *it << endl;
	}
}
