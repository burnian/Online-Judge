//date: 2019/2/7
//author: burnian
//des: ͼ����ת
#pragma once
#include<iostream>
using namespace std;

#define N 1000

// �����Կ������������С�����ƣ�ջ�������ƣ�ò�����Ĭ��4M�����Ըģ���������
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
