//date: 2019/2/7
//author: burnian
//des: 图像旋转
#pragma once
#include<iostream>
using namespace std;

#define N 1000

// 堆区对可声明的数组大小无限制，栈区有限制，貌似最大默认4M，可以改，但不建议
int mat[N][N];

void Solution() {
	int n, m, i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	for (j = m - 1; j >= 0; j--) {
		for (i = 0; i < n - 1; i++) {
			cout << mat[i][j] << " ";
		}
		cout << mat[i][j] << endl;
	}
}
