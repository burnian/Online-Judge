//date: 2019/2/17
//author: burnian
//des: Ïû³ıÀàÓÎÏ·
#pragma once
#include<iostream>
using namespace std;

#define N 30

int mat[N][N] = { 0 }, flag[N][N] = { 0 };

void Solution() {
	int n, m, cnt;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	// horizontal
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt = 1;
			while (j + 1 < m && mat[i][j] == mat[i][j + 1]) {
				cnt++;
				j++;
			}
			if (cnt >= 3) {
				for (int k = 0; k < cnt; k++) {
					flag[i][j - k] = 1;
				}
			}
		}
	}
	// vertical
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			cnt = 1;
			while (i + 1 < n && mat[i][j] == mat[i + 1][j]) {
				cnt++;
				i++;
			}
			if (cnt >= 3) {
				for (int k = 0; k < cnt; k++) {
					flag[i - k][j] = 1;
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << (flag[i][j] ? 0 : mat[i][j]) << " ";
		}
		cout << endl;
	}
}
