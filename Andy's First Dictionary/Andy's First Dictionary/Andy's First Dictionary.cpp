// Andy's First Dictionary.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

set<string> dict;//dictionary


int main()
{
	ifstream fin("data.txt");
	ofstream fout("result.txt");
	string s, buf;
	while (fin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) s[i] = tolower(s[i]); //All of the alpha change to the lower
			else s[i] = ' ';//The num or others change to blank
		}
		stringstream ss(s);
		while (ss >> buf) dict.insert(buf);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
		fout << *it << endl;
	}
    return 0;
}

