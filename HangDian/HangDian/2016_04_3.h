//date: 2019/2/24
//author: burnian
//des: 路径解析
#pragma once
#include<iostream>
#include<string>
using namespace std;

void Solution() {
	int n;
	string cd, dir, temp;
	cin >> n >> cd;
	for (int i = 0; i < n; i++) {
		cin >> dir;
		if (dir[0] != '/')
			dir = cd + "/" + dir;
		// 去掉多余/
		size_t pos = 0;
		while ((pos = dir.find("//", pos)) != string::npos) {
			dir.erase(pos, 1);
		}
		// 去掉/./
		pos = 0;
		while ((pos = dir.find("/./", pos)) != string::npos) {
			dir.erase(pos, 2);
		}
		// 去掉/../
		pos = 0;
		while ((pos = dir.find("/../", pos)) != string::npos) {
			if (pos > 0) {
				size_t end = pos;
				pos = dir.rfind("/", pos - 1);
				dir.erase(pos, end - pos + 3);
			}
			else {
				dir.erase(pos, 3);
			}
		}
		// 去掉最后的/
		pos = dir.length();
		if (pos > 1 && dir[pos - 1] == '/') {
			dir.erase(pos - 1, 1);
		}

		cout << dir << endl;
	}
}
