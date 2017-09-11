#include"Sudo.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<stdio.h>
#include<string>
#include "fstream"
using namespace std;

int main(int argv, char *argc[])
{
	string s = argc[2];
	int N=0;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		if (s[i] > '9' || s[i] < '0') {
			cout << "输入格式不正确,请输入整数\n";
			return 0;
		}else {
			N = N * 10 + s[i] - '0';
		}
	}
	Sudo sd;
	freopen("sudoku.txt", "w", stdout);
	sd.use_n(N);

}