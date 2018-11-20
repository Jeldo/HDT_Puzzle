#pragma once

#define MAX 15
#define MIN 5
#define VEC_PAIR vector<pair<int,int> >
#define STK_PAIR stack<pair<int,int> >
#define INT_PAIR pair<int,int>

//남 남서 서 북서 북 북동 동 남동 아니죠
//북 북서 서 남서 남 남동 동 북동
static int dRow[8] = { -1,-1,0,1,1,1,0,-1 };
static int dCol[8] = { 0,-1,-1,-1,0,1,1,1 };

//Pos 안쓰고 Pair로 할듯..?
struct Pos
{
   int x;
   int y;
};