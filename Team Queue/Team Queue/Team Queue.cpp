// Team Queue.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

void Coutt(map<int, int>team) {
	ofstream fout("result.txt");
	for (map<int, int>::iterator iter = team.begin(); iter != team.end(); iter++)
		fout << iter->first << ' ' << iter->second << endl;
}

int main() 
{
	ifstream fin("data.txt");
	ofstream fout("result.txt");
	//Check the team
	int t, kase = 0;//The t is the team num
	map<int, int>team;
	fin >> t;
	for (int i = 1; i <= t; i++) {
		int n, x;
		fin >> n;//The n is the number of the team which is the team num is ++kase
		while (n--) {
			fin >> x;//The x is the team ++kase member
			team[x] = i;
		}
	}

	//Print the team
	//Coutt(team);

	//Simulation the queue
	queue<int> q, q2[1000];
	for (;;) {
		int x;
		char *cmd = new char[10];
		fin >> cmd;
		if (cmd[0] == 'S')break;
		else if (cmd[0] == 'D') {
			int t = q.front();
			fout << q2[t].front() << endl;
			q2[t].pop();
			if (q2[t].empty())q.pop();
		}
		else if (cmd[0] == 'E') {
			fin >> x;
			int t =team[x];
			if (q2[t].empty())q.push(t);
			q2[t].push(x);
		}
	}
	return 0;
}

