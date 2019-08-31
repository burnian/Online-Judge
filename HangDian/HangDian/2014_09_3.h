//date: 2019/2/1
//author: burnian
//des: ×Ö·û´®Æ¥Åä
#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define N 100

void ILowerCace(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	}
}

void Solution() {
	string s, content;
	vector<string> v;
	int opt, n;
	cin >> s >> opt >> n;
	string temp1 = s;
	for (int i = 0; i < n; i++) {
		cin >> content;
		if (opt == 0) {
			ILowerCace(temp1);
			string temp2 = content;
			ILowerCace(temp2);
			if (temp2.find(temp1) != string::npos)
				v.push_back(content);
		}
		else {
			if (content.find(s) != string::npos)
				v.push_back(content);
		}
	}
	cout << endl;
	for (auto s : v) {
		cout << s << endl;
	}
}
