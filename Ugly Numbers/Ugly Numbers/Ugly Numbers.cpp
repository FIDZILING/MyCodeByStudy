// Ugly Numbers.cpp: 定义控制台应用程序的入口点。
//
//Caculate the 1500th ugly number

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <functional>
using namespace std;
typedef long long LL;
const int coeff[3] = { 2,3,5 };


int main()
{
	priority_queue<LL, vector<LL>, greater<LL>>pq;//The greater means that output small data at first
	set<LL>s;
	pq.push(1);
	s.insert(1);
	for (int i = 1;; i++) {
		LL x = pq.top();
		pq.pop();
		if (i == 1500) {
			cout << "The 1500th ugly number is " << x << endl;
			break;
		}
		for (int j = 0; j < 3; j++) {
			LL x2 = x * coeff[j];
			if (!s.count(x2)) {
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	getchar();
    return 0;
}

