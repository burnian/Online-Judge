//date: 2019/2/8
//author: burnian
//des: ����
#pragma once
#include<iostream>
using namespace std;

#define START_YEAR 1850
#define START_YEAR_FIRST_WEEKDAY 1//��ĿҪ�����ڴ�1~7��Ϊ�������ȡ0~6
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
		firstWeekday = (START_YEAR_FIRST_WEEKDAY + temp) % 7; //c++ ����ȡģ���Ϊ������0
		day = (count - 1) * 7 + (weekday - 1 - firstWeekday + 7) % 7 + 1; // �û��������������count�γ�����m��1�պ��������+1���m���ڵ�����
		if (day <= mDays[flag][month])
			printf_s("%04d/%02d/%02d\n", i, month, day);
		else
			cout << "none" << endl;
	}
}
