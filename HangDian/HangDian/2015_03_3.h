//date: 2019/2/8
//author: burnian
//des: 节日
#pragma once
#include<iostream>
using namespace std;

#define START_YEAR 1850
#define START_YEAR_FIRST_WEEKDAY 1//题目要求星期从1~7，为方便计算取0~6
#define LEAP_DAYS 366
#define NONLEAP_DAYS 365

int mDays[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31} };

bool IsLeapYear(int year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

void Solution() {
	int month, day, count, weekday, y1, y2, flag, temp, firstWeekday, deltaDays = 0;
	cin >> month >> count >> weekday >> y1 >> y2;
	for (int i = START_YEAR; i < y1; i++) {
		deltaDays += IsLeapYear(i) ? LEAP_DAYS : NONLEAP_DAYS;
	}
	for (int i = y1; i <= y2; i++) {
		temp = deltaDays;
		if (IsLeapYear(i)) {
			deltaDays += LEAP_DAYS;
			flag = 1;
		}
		else {
			deltaDays += NONLEAP_DAYS;
			flag = 0;
		}
		for (int j = 1; j < month; j++) {
			temp += mDays[flag][j];
		}
		firstWeekday = (START_YEAR_FIRST_WEEKDAY + temp) % 7; //c++ 负数取模结果为负数或0
		day = (count - 1) * 7 + (weekday - 1 - firstWeekday + 7) % 7 + 1; // 用户输入的星期数第count次出现在m月1日后的天数，+1变成m月内的日期
		if (day <= mDays[flag][month])
			printf_s("%04d/%02d/%02d\n", i, month, day);
		else
			cout << "none" << endl;
	}
}
