//date: 2019/2/23
//author: burnian
//des: 俄罗斯方块
#pragma once
#include<iostream>
using namespace std;

#define WIDTH 10
#define HEIGHT 15
#define BLOCKL 4

int canvas[WIDTH][HEIGHT] = { 0 };
int block[BLOCKL][BLOCKL] = { 0 };
// 新加入板块格子偏移坐标
struct {
	int x;
	int y;
}bOffset[BLOCKL];

bool IsCollide(int offsetX, int offsetY) {	
	for (int i = 0; i < BLOCKL; i++) {
		if (offsetY + bOffset[i].y >= HEIGHT || canvas[offsetX + bOffset[i].x][offsetY + bOffset[i].y])
			return true;
	}
	return false;
}

void Solution() {
	int offsetX, offsetY = 1;
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			cin >> canvas[x][y];
		}
	}
	for (int y = 0; y < BLOCKL; y++) {
		for (int x = 0; x < BLOCKL; x++) {
			cin >> block[x][y];
		}
	}
	cin >> offsetX;
	// 提取小方块
	int cnt = 0;
	for (int y = 0; y < BLOCKL; y++) {
		for (int x = 0; x < BLOCKL; x++) {
			if (block[x][y] == 1) {
				bOffset[cnt].x = x;
				bOffset[cnt].y = y;
				cnt++;
			}
		}
	}

	offsetX--;
	while (!IsCollide(offsetX, offsetY))
		offsetY++;
	offsetY--;
	for (int i = 0; i < BLOCKL; i++)
		canvas[offsetX + bOffset[i].x][offsetY + bOffset[i].y] = 1;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++)
			cout << canvas[x][y] << " ";
		cout << endl;
	}
}

// test canvas
//canvas[7][10] = 1;
//canvas[6][11] = 1;
//canvas[6][12] = 1;
//canvas[0][13] = 1;
//canvas[1][13] = 1;
//canvas[2][13] = 1;
//canvas[6][13] = 1;
//canvas[7][13] = 1;
//canvas[8][13] = 1;
//canvas[9][13] = 1;
//canvas[4][14] = 1;
//block[1][1] = 1;
//block[2][1] = 1;
//block[3][1] = 1;
//block[3][2] = 1;
