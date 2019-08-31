//date: 2019/1/23
//author: burnian
//des: Ïà·´Êý
#pragma once
#include<iostream>
#include<map>
using namespace std;

void Solution() {
	int n, temp, r = 0;
	map<int, int> m;
	while (cin >> n){
		for (int i = 0; i < n; i++) {
			cin >> temp;
			m[-temp] > 0 ? r += 1 : m[temp] += 1;
		}
		cout << r << endl;
	}
}
