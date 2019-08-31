//date: 2019/2/7
//author: burnian
//des: ¼¯ºÏ¾º¼Û
#pragma once
#include<iostream>
#include<queue>
#include<string>
using namespace std;

#define N 5000

struct Trade {
	size_t id;
	char type;//b, s
	float price;
	size_t quantity;
	bool operator < (const Trade& t) const {
		if (type == 'b')
			return price < t.price;
		else
			return price > t.price;
	}
};

void Solution() {
	priority_queue<Trade> buy, sell;
	bool cancel[N] = { false };
	string req;
	Trade t;
	float price = 0;
	size_t id = 0, no = 0, quantity = 0;
	while (cin >> req) {
		no++;
		if (req[0] == 'b' || req[0] == 's') {
			t.id = no;
			t.type = req[0];
			cin >> price >> quantity;
			t.price = price;
			t.quantity = quantity;
			if (t.type == 'b')
				buy.push(t);
			else
				sell.push(t);
		}
		else if (req[0] == 'c') {
			cin >> id;
			cancel[id] = true;
		}
		else
			break;
	}
	Trade b, s;
	price = 0;
	quantity = 0;
	while (true) {
		while (!buy.empty()) {
			b = buy.top();
			if (cancel[b.id])
				buy.pop();
			else
				break;
		}
		while (!sell.empty()) {
			s = sell.top();
			if (cancel[s.id])
				sell.pop();
			else
				break;
		}
		if (buy.empty() || sell.empty())
			break;
		if (b.price >= s.price) {
			price = b.price;
			quantity += min(b.quantity, s.quantity);
			if (b.quantity > s.quantity) {
				b.quantity -= s.quantity;
				buy.pop();
				buy.push(b);
				sell.pop();
			}
			else if (b.quantity < s.quantity) {
				s.quantity -= b.quantity;
				sell.pop();
				sell.push(s);
				buy.pop();
			}
			else {
				buy.pop();
				sell.pop();
			}
		}
		else
			break;
	}
	printf_s("%.2f", price);
	cout << " " << quantity << endl;
}