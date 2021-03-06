// The Blocks Problem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//vector definition
vector<int> pile[50];

void find_block(int Block, int Num, int& i, int& j) {
	for (i = 0; i < Num; i++) {
		for (j = 0; j < pile[i].size(); j++)
			if (pile[i][j] == Block)return;
	}
}

//Up of the p come back
void clear_above(int p, int h) {
	for (int i = h + 1; i < pile[p].size(); i++) {
		int b = pile[p][i];
		pile[b].push_back(b);//Go back
	}
	pile[p].resize(h + 1);
}

//The block ph goto the top of p2
void pile_onto(int p, int h, int p2) {
	for (int i = h; i < pile[p].size(); i++) {
		pile[p2].push_back(pile[p][i]);
	}
	pile[p].resize(h);
}

//print the blocks
void print(int n) {
	ofstream fout("result.txt");
	for (int i = 0; i < n; i++) {
		fout << i << ":";
		for (int j = 0; j < pile[i].size(); j++) {
			fout << pile[i][j];
		}
		fout << endl;
	}
}

int main()
{
	ifstream fin("data.txt");
	int All_N;//The blocks num
	fin >> All_N;
	int a, b;//The move of the blocks a and b
	string str_one, str_two;//The two command
	for (int i = 0; i < All_N; i++)
		pile[i].push_back(i);//Init
	int Ope_N;
	fin >> Ope_N;
	while (Ope_N) {
		fin >> str_one;
		fin >> a;
		fin >> str_two;
		fin >> b;
		int I_ia, J_ja, I_ib, J_jb;
		find_block(a, All_N, I_ia, J_ja);
		find_block(b, All_N, I_ib, J_jb);
		if (I_ia == I_ib) continue;
		if (str_two == "onto")//Up the block b come back
			clear_above(I_ib, J_jb);
		if (str_one == "move")//Up the block a come back
			clear_above(I_ia, J_ja);
		pile_onto(I_ia, J_ja, I_ib);
		Ope_N--;
	}
	print(All_N);
	return 0;
}

