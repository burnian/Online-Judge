//date: 2019/1/16
//author: burnian
//des: ¥”1¿€º”µΩn
#pragma once
#include<iostream>
using namespace std;

void Solution() {
	int n;
	while (cin>>n){
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i;
		}
		cout << sum << endl << endl;
	}
}
