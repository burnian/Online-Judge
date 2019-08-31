//date: 2019/1/16
//author: burnian
//des: ����һ��Ԫ�������и������У���������������У�int�͵������ֵΪ��2^31-1 = 2147483647
#pragma once
#include<iostream>
using namespace std;

//�ۻ������㷨O(n)��ֻ�к�Ϊ�������в����ʸ�������չ����Ϊ��Ϊ����������չ��ֻ�����¼���Ԫ�صĺ��ȣ�����ֱ�Ӱ���Ԫ�ص����������
//����������Ϊ����ԭ���е�����Ԫ�ض�Ϊ�������ԭ����ֻ��һ����Ԫ�أ����Ԫ���Լ�һ�����������У�������г����������1�����ұ߽��Ԫ��һ��Ϊ��
//��Ϊ����߽�Ԫ��Ϊ������ȫ�����޳�֮��ʹ���µ����и���
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
				if (sum < 0) {//��ǰ����һ��С��0�����һ��Ԫ�ص��������е���ʼԪ��
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

//�������O(n^3)
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
