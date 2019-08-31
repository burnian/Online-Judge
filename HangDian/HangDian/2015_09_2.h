//date: 2019/2/13
//author: burnian
//des: ÈÕÆÚ¼ÆËã
#pragma once
#include<iostream>
using namespace std;

int mDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

void Solution() {
	int y, d, month, day;
	while (cin >> y >> d) {
		mDays[1] = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0 ? 29 : 28;
		for (int i = 0; i < 12; i++) {
			if (d <= mDays[i]) {
				month = i + 1;
				day = d;
				break;
			}
			d -= mDays[i];
		}
		cout << month << endl;
		cout << day << endl;
	}
}
