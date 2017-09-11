#pragma once
class Sudo
{
public: 
	int sudoku[9][9];
	int target;
	Sudo();
	void pro_sudoku(int i, int j, int z);
	bool judge(int line, int column, int a);
	void init();
	void use_n(int N);

	~Sudo();
};

