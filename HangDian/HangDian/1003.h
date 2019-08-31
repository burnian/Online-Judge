//date: 2019/1/16
//author: burnian
//des: 给定一个元素有正有负的数列，求和最大的连续子列，int型的最大正值为：2^31-1 = 2147483647
#pragma once
#include<iostream>
using namespace std;

//累积遍历算法O(n)，只有和为正的子列才有资格向右扩展，因为和为负的子列扩展后只会拖新加入元素的后腿，不如直接把新元素当做最大子列
//最大子列如果为负则原数列的所有元素都为负，如果原数列只有一个正元素，则该元素自己一个组成最大子列，最大子列长度如果大于1则左右边界的元素一定为正
//因为如果边界元素为负则完全可以剔除之，使得新的子列更大
void Solution() {
	size_t cnt, len, start, s, e;
	int max, sum, a;
	while (cin >> cnt)
	{
		for (size_t i = 0; i < cnt; i++) {
			cin >> len;
			max = -1001;
			sum = -1;
			for (int i = 0; i < len; i++) {
				cin >> a;
				if (sum < 0) {//当前子列一旦小于0则把下一个元素当做新子列的起始元素
					start = i;
					sum = a;
				}
				else {
					sum += a;
				}
				if (sum > max) {
					max = sum;
					s = start + 1;
					e = i + 1;
				}
			}
			cout << "Case " << i + 1 << ":\n" << max << " " << s << " " << e << endl;
			if (i < cnt - 1) {
				cout << endl;
			}
		}
	}
}

//暴力求解O(n^3)
//void Solution() {
//	size_t cnt, len, s, e;
//	int max, a[100000];
//	while (cin>>cnt)
//	{
//		for (size_t i = 0; i < cnt; i++) {
//			cin >> len;
//			s = 0;
//			e = len - 1;
//			max = 0;
//			for (int i = 0; i < len; i++) {
//				cin >> a[i];
//				max += a[i];
//			}
//			for (int subLen = len; subLen > 0; subLen--)
//				for (int start = 0; start + subLen <= len; start++) {
//					int sum = 0;
//					for (int k = 0; k < subLen; k++) {
//						sum += a[start + k];
//					}
//					if (sum > max) {
//						max = sum;
//						s = start + 1;
//						e = start + subLen;
//					}
//				}
//			cout << "Case " << i + 1 << ":\n" << max << " " << s << " " << e << endl;
//			if (i < cnt - 1) {
//				cout << endl;
//			}
//		}
//	}
//}
