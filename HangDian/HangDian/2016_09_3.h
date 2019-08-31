//date: 2019/2/27
//author: burnian
//des: 炉石传说
#pragma once
#include<iostream>
#include<vector>
using namespace std;

#define PLAYER_NUM 2

struct Mon {
	int atk;
	int hp;
	Mon(int a, int b) :atk(a), hp(b) {}
};

struct PlayerInfo {
	int hp = 30;
	vector<Mon> mons;
};

int GetPID(bool flag) {
	return flag ? 0 : 1;
}

void Solution() {
	int n;
	bool flag = true;
	char opt[10];
	PlayerInfo players[PLAYER_NUM] = { PlayerInfo() };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> opt;
		if (opt[0] == 's') {
			int pos, atk, hp;
			cin >> pos >> atk >> hp;
			vector<Mon> *p = &players[GetPID(flag)].mons;
			if (pos > p->size()) {
				p->push_back(Mon(atk, hp));
			}
			else {
				p->insert(p->begin() + pos - 1, Mon(atk, hp));
			}
		}
		else if (opt[0] == 'a') {
			int atkPos, defPos;
			cin >> atkPos >> defPos;
			int atkID = GetPID(flag);
			int defID = GetPID(!flag);
			atkPos--;
			defPos--;
			Mon attacker = players[atkID].mons[atkPos];
			if (defPos >= 0) {
				// 攻击怪
				Mon defender = players[defID].mons[defPos];
				if ((attacker.hp -= defender.atk) > 0) {
					players[atkID].mons[atkPos] = attacker;
				}
				else {
					vector<Mon> *p = &players[atkID].mons;
					p->erase(p->begin() + atkPos);
				}
				if ((defender.hp -= attacker.atk) > 0) {
					players[defID].mons[defPos] = defender;
				}
				else {
					vector<Mon> *p = &players[defID].mons;
					p->erase(p->begin() + defPos);
				}
			}
			else {
				// 攻击玩家
				players[defID].hp -= attacker.atk;
			}
		}
		else {
			flag = !flag;
		}
	}
	// 结算
	if (players[0].hp <= 0)
		cout << -1 << endl;
	else if (players[1].hp <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	cout << players[0].hp << endl;
	cout << players[0].mons.size() << " ";
	for (auto v : players[0].mons) {
		cout << v.hp << " ";
	}
	cout << endl;
	cout << players[1].hp << endl;
	cout << players[1].mons.size() << " ";
	for (auto v : players[1].mons) {
		cout << v.hp << " ";
	}
	cout << endl;
}
