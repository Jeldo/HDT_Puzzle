#pragma once

#define MAX_SIZE_MAP 15
#define MIN_SIZE_MAP 5
#define MAX_VALUE 99
#define START_NUM 1
#define VEC_PAIR vector<pair<int,int> >
#define INT_PAIR pair<int,int>
#define LUCKYNUM 10
#define HINT_RATE 2
#define DIF 20
#define ZERO 6

//북 북서 서 남서 남 남동 동 북동
static int dRow[8] = { -1,-1,0,1,1,1,0,-1 };
static int dCol[8] = { 0,-1,-1,-1,0,1,1,1 };