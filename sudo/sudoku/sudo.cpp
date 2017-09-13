#include"Sudo.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<stdio.h>
#include "fstream"
using namespace std;


Sudo::Sudo()
{

}

void Sudo::pro_sudoku(int i, int j, int t)
{
	if (j < 0)
	{
		i--;
		j = 0;
	}
	if (j>8)
	{
		i++;
		j = 0;
	}
	if (i == 9 && j == 0)
	{

		for (int k = 0; k<9; k++)
		{
			for (int l = 0; l<9; l++)
			{
				putchar(sudoku[k][l]+'0');
				putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
		if (--target<= 0)
		{
			exit(0);
		}
	}
	else if (i < 9)
	{
		for (int k = 1; k<9; k++) 
		{
			int n = (t++) % 9 + 1;
			if (judge(i, j, n))
			{
				sudoku[i][j] = n;
				pro_sudoku(i, j + 1, t);
				sudoku[i][j] = 0;
			}
		}
	}
}

bool Sudo::judge(int line, int column, int a)
{
	int x, y;
	for (int i = 0; i<9; i++)
	{
		if (sudoku[line][i] == a)
		{
			return false;
		}
	}
	for (int i = 0; i<9; i++)
	{
		if (sudoku[i][column] == a)
		{
			return false;
		}
	}
	x = (line / 3) * 3;
	y = (column / 3) * 3;
	for (int i = x; i<x + 3; i++)
	{
		for (int j = y; j<y + 3; j++)
		{
			if (sudoku[i][j] == a)
			{
				return false;
			}
		}
	}
	return true;

}

void Sudo::init()
{
	srand((unsigned)time(NULL));
	sudoku[0][0] = 2;
	sudoku[0][1] = 1;
	for (int i = 2; i<9; i++)
	{
		sudoku[0][i] = i+1;
	}
	random_shuffle(&(sudoku[0][1]), &(sudoku[0][8]));
}

void Sudo::use_n(int N)
{
	target = N;
	init();
	pro_sudoku(1, 0, 1);

}


Sudo::~Sudo()
{
}
