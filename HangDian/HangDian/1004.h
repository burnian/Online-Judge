//date: 2019/1/17
//author: burnian
//des: 对于给定的一组气球颜色字符串，求其中数量最多的那种颜色
#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;

void Solution() {
	size_t cnt, max;
	string str, popular;
	map<string, size_t> m;
	map<string, size_t>::iterator it;
	while (cin >> cnt && cnt > 0) {
		m.clear();
		for (int i = 0; i < cnt; i++) {
			cin >> str;
			m[str]++;
		}
		max = 0;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second > max) {
				max = it->second;
				popular = it->first;
			}
		}
		cout << popular << endl;
	}
}
