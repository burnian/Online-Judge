//date: 2019/1/18
//author: burnian
//des: ISBNºÅÂë 0-670-82162-4
#pragma once
#include<iostream>
#include<string>
using namespace std;

void Solution() {
	string str;
	size_t sum = 0;
	cin >> str;
	for (int i = 0, cnt = 1; i < 11; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			sum += (str[i] - '0') * cnt++;
		}
	}
	size_t id = sum % 11;
	if (id < 10) {
		if (str[12] - '0' == id) {
			cout << "right" << endl;
		}
		else {
			str[12] = id + '0';
			cout << str << endl;
		}
	}
	else {
		if (str[12] == 'X') {
			cout << "right" << endl;
		}
		else{
			str[12] = 'X';
			cout << str << endl;
		}
	}
}
