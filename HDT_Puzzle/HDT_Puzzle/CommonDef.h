#pragma once

#define MAX 15
#define MIN 5
#define VEC_PAIR vector<pair<int,int>>
#define STK_PAIR stack<pair<int,int>>
#define INT_PAIR pair<int,int>

//�� ���� �� �ϼ� �� �ϵ� �� ���� �ƴ���
//�� �ϼ� �� ���� �� ���� �� �ϵ�
static int dRow[8] = { -1,-1,0,1,1,1,0,-1 };
static int dCol[8] = { 0,-1,-1,-1,0,1,1,1 };

//Pos �Ⱦ��� Pair�� �ҵ�..?
struct Pos
{
	int x;
	int y;
};