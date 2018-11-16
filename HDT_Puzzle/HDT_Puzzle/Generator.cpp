#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAX_SIZE_MAP 16
#define MAX_VALUE 99
using namespace std;

int maxMap[MAX_SIZE_MAP][MAX_SIZE_MAP];
int maxMap_Solution[MAX_SIZE_MAP][MAX_SIZE_MAP];
int curValue;
// 0: 남, 1: 남서, 2: 서, 3: 북서, 4: 북, 5: 북동, 6: 동, 7: 남동
int dirRow[8] = {-1, -1,  0,  1,  1,  1,  0, -1};
int dirCol[8] = { 0, -1, -1, -1,  0,  1,  1,  1};

//HINT POINT
int hintRow[MAX_VALUE] = {0};
int hintCol[MAX_VALUE] = {0};

//add
vector<int> hintVecRow;
vector<int> hintVecCol;
vector<int> hintNum;

//시작x, 시작y, 바꿀 숫자
void GenPuzzle(int x, int y, int value){
    maxMap_Solution[x][y] = value;

    if(rand()%10 < 3 || value == 13 || value == 1){
        maxMap[x][y] = value;
        hintVecRow.push_back(x);
        hintVecCol.push_back(y);
        hintNum.push_back(value);
    }
    else{
        maxMap[x][y] = 0;  
    }

    hintRow[value] = x;
    hintCol[value] = y;

    curValue = value;

    //최대치 도달
    if(value == MAX_VALUE){
        return;
    }

    value++;
    //break point는 다음과 같이 설정한다.
    //움직이려는 방향이 maxMap에서 벗어나려 한다면
    //dir배열 index를 1 올리고 움직일 수 있는지 확인한다.
    //이 때 움직이지 않는 횟수에 대한 변수를 선언 후
    //한 지점에서 움직이지 못할 때 마다 ++한다.
    //만약 움직일수 있다면 0으로 초기화
    //만약 모든 방향에서 움직이지 못한다면 ==8이므로 break
    int stopCount = 0;

    int ran;
    ran = rand() % 8;
    //cout<<ran;

    for(int i = 0; i < 8; i++){
        int idx = (ran + i)%8;
        //만약 maxMap을 벗어난다면
        if(x + dirRow[idx] < 0 || x + dirRow[idx] > 15 
            || y + dirCol[idx] < 0 || y + dirCol[idx] > 15 
            || maxMap[x + dirRow[idx]][y + dirCol[idx]] != -1){
                stopCount++;
        }
        else{
            GenPuzzle(x + dirRow[idx], y + dirCol[idx], value);
            break;
        }
    }
    

    //모든 방향 이동 불가능
    if(stopCount == 7){
        //return;
    }
}

//퍼즐에 구멍뚫기
// void EraseValue(){
//     int hintCount = 1;

//     for(int row = 0; row < MAX_SIZE_MAP; row++){
//         for(int col = 0; col < MAX_SIZE_MAP; col++){
//             //-1 또는 1이면 넘어가고
//             if(maxMap[row][col] == -1 || maxMap[row][col] == 1){
//                 continue;
//             }
//             //13에서는 무조건 뚫어준다
//             if(maxMap[row][col] % 13 == 1){
//                 maxMap[row][col] = 0;
//             }
//             //그 외에는 일정확률로 뚫는다(Default : 50%)
//             else{
//                 if(rand()%10 < 3){
                    
//                     hintRow[maxMap[row][col]] = -1;
//                     hintCol[maxMap[row][col]] = -1;
//                     maxMap[row][col] = 0;
//                 }
//                 else{
//                     hintCount++;
//                 }
//             }
//         }
//     }
// }

int main(){

    //초기화 변수들
    //시작 지점
    int stRow, stCol;
    //임시로 3으로 지정
    stRow = MAX_SIZE_MAP/2;
    stCol = MAX_SIZE_MAP/2;

    //Random seed 초기화
    srand((unsigned int) time(NULL));

    //First Step : maxMap 초기화 -1
    for(int row = 0; row < MAX_SIZE_MAP; row++){
        for(int col = 0; col < MAX_SIZE_MAP; col++){
            maxMap[row][col] = -1;
            maxMap_Solution[row][col] = -1;
        }
    }
    GenPuzzle(stRow, stCol, 1);
    cout<<endl<<"----------------------------------------------------"<<endl;
    //맵 확인 변수(제거 전)
    for(int row = 0; row < MAX_SIZE_MAP; row++){
        for(int col = 0; col < MAX_SIZE_MAP; col++){
            if(maxMap_Solution[row][col] >= 0 && maxMap_Solution[row][col] < 10)
                cout<<" ";
            cout<<maxMap_Solution[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
    //EraseValue();
    //맵 확인 변수(제거 후)
    for(int row = 0; row < MAX_SIZE_MAP; row++){
        for(int col = 0; col < MAX_SIZE_MAP; col++){
            if(maxMap[row][col] >= 0 && maxMap[row][col] < 10)
                cout<<" ";
            cout<<maxMap[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
    cout<<"END NUMBER : "<<curValue<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"HINT (count: "<< hintVecRow.size()<<") : ";
    for(int i = 0; i < hintVecRow.size(); i++){
        cout<<hintNum[i]<<"("<<hintVecRow[i]<<","<<hintVecCol[i]<<") ";
    }

    cout<<endl;

    return 0;
}