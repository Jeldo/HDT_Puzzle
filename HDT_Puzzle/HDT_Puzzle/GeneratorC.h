#ifndef GENERATOR_C_H
#define GENERATOR_C_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAX_SIZE_MAP 15
#define MAX_VALUE 99
#define START_NUM 1
using namespace std;

// 0: 남, 1: 남서, 2: 서, 3: 북서, 4: 북, 5: 북동, 6: 동, 7: 남동
static int dirRow[8] = {-1, -1,  0,  1,  1,  1,  0, -1};
static int dirCol[8] = { 0, -1, -1, -1,  0,  1,  1,  1};

#endif
