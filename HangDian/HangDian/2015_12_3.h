//date: 2019/2/17
//author: burnian
//des: »­Í¼
#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define N 100

char canvas[N][N];

struct Point {
	int x;
	int y;
	Point(int a, int b):x(a),y(b){}
};

bool IsLine(int x, int y) {
	return canvas[x][y] == '+' || canvas[x][y] == '-' || canvas[x][y] == '|';
}

void Solution() {
	memset(canvas, '.', N * N);
	int width, height, n, type;
	stack<Point> st;
	cin >> width >> height >> n;
	for (int i = 0; i < n; i++) {
		cin >> type;
		if (type == 0) {
			// draw line
			int x1, y1, x2, y2, start, end;
			cin >> x1 >> y1 >> x2>> y2;
			if (x1 == x2) {
				// vertical
				start = y1 < y2 ? y1 : y2;
				end = y1 > y2 ? y1 : y2;
				for (int k = start; k <= end; k++) {
					if(canvas[x1][k] != '+')
						canvas[x1][k] = canvas[x1][k] == '-' ? '+' : '|';
				}
			}
			else {
				// horizontal
				start = x1 < x2 ? x1 : x2;
				end = x1 > x2 ? x1 : x2;
				for (int k = start; k <= end; k++)
					if (canvas[k][y1] != '+')
						canvas[k][y1] = canvas[k][y1] == '|' ? '+' : '-';
			}
		}
		else {
			// fill with character
			int x, y;
			char c;
			Point temp(0, 0);
			cin >> x >> y >> c;
			st.push(Point(x, y));
			while (!st.empty()) {
				temp = st.top();
				st.pop();
				x = temp.x;
				y = temp.y;
				if (0 <= x && x < width && 0 <= y && y < height && !IsLine(x, y) && canvas[x][y] != c) {
					canvas[x][y] = c;
					st.push(Point(x - 1, y));
					st.push(Point(x + 1, y));
					st.push(Point(x, y - 1));
					st.push(Point(x, y + 1));
				}
			}
		}
	}
	for (int y = height - 1; y >= 0; y--) {
		for (int x = 0; x < width; x++) {
			cout << canvas[x][y];
		}
		cout << endl;
	}
}
