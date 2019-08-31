//date: 2019/1/25
//author: burnian
//des: ´°¿Ú
#pragma once
#include<iostream>
#include<list>
using namespace std;

struct Point
{
	int x;
	int y;
};

typedef struct Node
{
	int ID;
	Point pLT;
	Point pRB;
	Node* next;
}*Window;

void Solution() {
	int winCnt, clickCnt, x, y;
	int ret[10] = { 0 };
	cin >> winCnt >> clickCnt;
	Window list = nullptr;
	Window p, q;
	for (int i = 1; i <= winCnt; i++) {
		Window temp = new Node();
		temp->ID = i;
		cin >> x >> y;
		temp->pLT.x = x;
		temp->pLT.y = y;
		cin >> x >> y;
		temp->pRB.x = x;
		temp->pRB.y = y;
		if (i == 1) {
			list = temp;
			list->next = nullptr;
		}
		else {
			temp->next = list;
			list = temp;
		}
	}
	for (int i = 0; i < clickCnt; i++) {
		cin >> x >> y;
		p = q = list;
		while (p) {
			if (x >= p->pLT.x && x <= p->pRB.x && y >= p->pLT.y && y <= p->pRB.y) {
				if (p != q) {
					q->next = p->next;
					p->next = list;
					list = p;
				}
				ret[i] = list->ID;
				break;
			}
			q = p;
			p = p->next;
		}
	}
	cout << endl;
	for (int i = 0; i < clickCnt; i++) {
		if (ret[i] == 0)
			cout << "IGNORED" << endl;
		else
			cout << ret[i] << endl;
	}
}
