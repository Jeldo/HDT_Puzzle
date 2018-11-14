#pragma once

#define MAX 15
#define MIN 5
#define VEC_PAIR vector<pair<int,int>>
#define STK_PAIR stack<pair<int,int>>
#define INT_PAIR pair<int,int>

static int dx[8] = { -1,-1,0,1,1,1,0,-1 };
static int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

//Pos 안쓰고 Pair로 할듯..?
struct Pos
{
	int x;
	int y;
};