//date: 2019/2/5
//author: burnian
//des: z����ɨ��
// ����Խ�����̽����̽�ң�����Խ�����̽����̽�£�����·���ߣ�����
#pragma once
#include<iostream>
using namespace std;

#define N 500

void Solution() {
	int n, arr[N][N];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	// x����������y����������dir = 1��ʾ���ϣ�-1��ʾ����
	int x = 0, y = 0, dir = 1, offset = 1;
	while (true) {
		cout << arr[x][y] << " ";
		if (0 <= x - dir && x - dir < n && 0 <= y + dir && y + dir < n) {
			x -= dir;
			y += dir;
		}
		else{
			if (dir == 1) {
				if (y + offset < n) {
					y += offset;
				}
				else if (x + offset < n) {
					x += offset;
				}
				else break;
			}
			else {
				if (x + offset < n) {
					x += offset;
				}
				else if (y + offset < n) {
					y += offset;
				}
				else break;
			}
			dir = -dir;
		}
	}
	cout << endl;
}
