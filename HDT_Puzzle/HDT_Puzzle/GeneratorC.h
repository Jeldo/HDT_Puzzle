#ifndef GENERATOR_C_H
#define GENERATOR_C_H

#include <iostream>
#include <vector>
#include "CommonDef.h"

using namespace std;

class Generator {
private:

	//초기화 변수들
	//시작 지점
	int stRow, stCol;

	//Hidato puzzle 배열
	//int** maxMap[MAX_SIZE_MAP][MAX_SIZE_MAP];
	vector<vector<int> > maxVecMap;
	//완성된 퍼즐 출력
	//int maxMap_Solution[MAX_SIZE_MAP][MAX_SIZE_MAP];
	vector<vector<int> > maxVecMap_Solution;
	//End Number
	int curValue;

	vector<int> hintVecRow;
	vector<int> hintVecCol;
	vector<int> hintNum;

	//동적
	int** maxMap;
	int** maxMap_Solution;

public:
	Generator();
	~Generator();

	int getStartRow();
	int getStartCol();

	//시작x, 시작y, 바꿀 숫자
	void GeneratorPuzzle(int x, int y, int value, bool pass);

	//풀어야할 퍼즐 출력
	void ShowPuzzle();

	//정답 퍼즐 출력
	void ShowCompletePuzzle();

	//최종 숫자 출력
	void ShowEndNumber();

	//힌트 출력
	void ShowHint();

	int** getPuzzle();
	int** getCompletePuzzle();
	//int (*getPuzzle(void))[MAX_SIZE_MAP];
	//int (*getCompletePuzzle(void))[MAX_SIZE_MAP];

	//최종 숫자 리턴
	int getEndNumber();

	//힌트 배열 리턴
	vector<vector<int> > getHint();

	void ReduceZero();
};

#endif
