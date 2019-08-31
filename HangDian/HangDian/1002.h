//date: 2019/1/16
//author: burnian
//des: 大数字求和，无符号整型最大值为：2^32-1 = 4294967295   '0' = 48
#pragma once
#include<iostream>
using namespace std;

#define LENGTH 1000

void Solution() {
	int cnt;
	char a[LENGTH], b[LENGTH], c[LENGTH];
	char x, y;
	while (cin >> cnt) {
		for (size_t i = 0; i < cnt; i++) {
			cin >> a >> b;
			int la = strlen(a) - 1;
			int lb = strlen(b) - 1;
			int lc = la > lb ? la : lb;
			c[lc + 1] = '\0';
			size_t carry = 0;
			while (la >= 0 || lb >= 0) {
				x = la >= 0 ? a[la] : '0';
				y = lb >= 0 ? b[lb] : '0';
				size_t temp = x + y - 96 + carry;
				carry = temp / 10;
				c[lc] = temp % 10 + 48;
				la--, lb--, lc--;
			}
			cout << "Case " << i + 1 << ":\n" << a << " + " << b << " = " << (carry > 0 ? "1" : "") << c << endl;
			if (i < cnt - 1) {
				cout << endl;
			}
		}
	}
}
