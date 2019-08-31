//date: 2019/1/29
//author: burnian
//des: 命令行选项
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

const string delimiters = " ";

//@delimiter 把一个字符串作为分隔符
//void SingleSplit(const std::string& s, std::vector<std::string>& v, const std::string& delimiter) {
//	std::string::size_type pos1, pos2;
//	pos2 = s.find(delimiter);
//	pos1 = 0;
//	while (std::string::npos != pos2) {
//		v.push_back(s.substr(pos1, pos2 - pos1));
//		pos1 = pos2 + delimiter.size();
//		pos2 = s.find(delimiter, pos1);
//	}
//	v.push_back(s.substr(pos1));
//}

//@delimiters 把一组字符中的每一个作为分隔符
void MultipleSplit(const std::string& s, std::vector<std::string>& v, const std::string& delimiters) {
	std::string::size_type pos1, pos2;
	pos2 = s.find_first_of(delimiters);
	pos1 = 0;
	while (std::string::npos != pos2) {
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + 1;
		pos2 = s.find_first_of(delimiters, pos1);
	}
	v.push_back(s.substr(pos1));
}

void Solution() {
	string format, s;
	int n;
	cin >> format >> n;
	for (int i = 1; i <= n; i++) {
		vector<string> sv;
		map<string, string> m;
		cin.get();// 消除之前cin遗留下来的'\n'
		getline(cin, s);
		MultipleSplit(s, sv, delimiters);
		for (int j = 1; j < sv.size(); j++) {
			if (sv[j][0] != '-' || sv[j].size() != 2)
				break;
			int pos = format.find(sv[j][1]);
			if (pos == -1)
				break;
			if (format[pos + 1] == ':') {
				j++;
				if (j < sv.size() && sv[j][0] != '-') {
					m[sv[j - 1]] = sv[j];
				}
				else {
					break;
				}
			}
			else {
				m[sv[j]] = "";
			}
		}
		cout << "Case " << i << ":";
		for (auto it = m.begin(); it != m.end(); it++) {
			cout << " " << it->first;
			if (it->second != "")
				cout << " " << it->second;
		}
		cout << endl;
	}
}
