//date: 2019/1/20
//author: burnian
//des: ���ľ���
#pragma once
#include<iostream>
#include<stack>
using namespace std;

void Solution() {
	int n, height[1001], ans = 0, start = 0, end = 0;
	stack<int> s;//���ڴ�ž��������±꣬ջ�ھ��εĸ߶ȶ�Ҫ����ջ������
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		height[n] = 0;
		while (!s.empty()) s.pop();
		for (int i = 0; i <= n; i++) {
			if (s.empty() || height[i] > height[s.top()]) {
				s.push(i);
			}
			else {
				int temp = s.top();
				s.pop();
				int area = height[temp] * (s.empty() ? i : i - s.top() - 1);
				if (area > ans) {
					ans = area;
					start = s.empty() ? 0 : s.top() + 1;
					end = i - 1;
				}
				i--;
			}
		}
		cout << ans << endl;
		cout << start << " " << end << endl;
	}
}
