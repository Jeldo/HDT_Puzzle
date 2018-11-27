#include "GeneratorC.h"


Generator::Generator() {
	//First Step : maxMap 초기화 -1

	maxMap = new int*[MAX_SIZE_MAP];
	maxMap_Solution = new int*[MAX_SIZE_MAP];
	for (int row = 0; row < MAX_SIZE_MAP; row++) {
		maxMap[row] = new int[MAX_SIZE_MAP];
		maxMap_Solution[row] = new int[MAX_SIZE_MAP];
		for (int col = 0; col < MAX_SIZE_MAP; col++) {
			maxMap[row][col] = -1;
			maxMap_Solution[row][col] = -1;
		}
	}
	//value = 0;

	this->stRow = MAX_SIZE_MAP / 2;
	this->stCol = MAX_SIZE_MAP / 2;
}

int Generator::getStartRow() {
	return this->stRow;
}
int Generator::getStartCol() {
	return this->stCol;
}

//시작x, 시작y, 바꿀 숫자
void Generator::GeneratorPuzzle(int x, int y, int value){
    maxMap_Solution[x][y] = value;
    
    if(rand()%10 < HINT_RATE || value % LUCKYNUM == 0 || value == 1 || value == MAX_VALUE){
        maxMap[x][y] = value;
        hintVecRow.push_back(x);
        hintVecCol.push_back(y);
        hintNum.push_back(value);
    }
    else{
        maxMap[x][y] = 0;
    }
	
	int zeroCount = 0;
	for(int i = 0; i < 8; i++){
		if(x + dRow[i] < 0 || x + dRow[i] >= MAX_SIZE_MAP || y + dCol[i] < 0 || y + dCol[i] >= MAX_SIZE_MAP){
			continue;
		}
		if(maxMap[x + dRow[i]][y + dCol[i]] == 0){
			zeroCount++;
		}
		// else{
		// 	//break;
		// }
    }

	if(zeroCount >= 8){
		maxMap[x][y] = value;
		hintVecRow.push_back(x);
        hintVecCol.push_back(y);
        hintNum.push_back(value);
		zeroCount = 0;
	}
    
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
        if(x + dRow[idx] < 0 || x + dRow[idx] > MAX_SIZE_MAP-1
            || y + dCol[idx] < 0 || y + dCol[idx] > MAX_SIZE_MAP-1
            || maxMap[x + dRow[idx]][y + dCol[idx]] != -1){
            stopCount++;
        }
        //막힌 곳이 없다면
		else if ((value - maxMap[x + dRow[idx]][y + dCol[idx]]) > DIF && maxMap[x + dRow[idx]][y + dCol[idx]]!=-1) {
			stopCount = 8;
			break;
		}
        else{
            GeneratorPuzzle(x + dRow[idx], y + dCol[idx], value);
            break;
        }
    }
    
    //모든 방향 이동 불가능
    if(stopCount >= 8){
        maxMap[x][y] = value-1;
    }
}

//풀어야할 퍼즐 출력
void Generator::ShowPuzzle() {

	//맵 확인 변수(제거 후)
	cout << "----------------------------------------------------" << endl;

	for (int row = 0; row < MAX_SIZE_MAP; row++) {
		for (int col = 0; col < MAX_SIZE_MAP; col++) {
			//if(maxMap[row][col] == -1){
			//    cout<<"   ";
			//}
			//else{
			if (maxMap[row][col] >= 0 && maxMap[row][col] < 10)
				cout << " ";
			cout << maxMap[row][col] << " ";
			//}

		}
		cout << endl;
	}
	cout << "----------------------------------------------------" << endl;
}

//정답 퍼즐 출력
void Generator::ShowCompletePuzzle() {
	cout << endl << "----------------------------------------------------" << endl;
	//맵 확인 변수(제거 전)
	for (int row = 0; row < MAX_SIZE_MAP; row++) {
		for (int col = 0; col < MAX_SIZE_MAP; col++) {

			if (maxMap_Solution[row][col] >= 0 && maxMap_Solution[row][col] < 10)
				cout << " ";
			cout << maxMap_Solution[row][col] << " ";
		}
		cout << endl;
	}
	cout << "----------------------------------------------------" << endl;
}

//최종 숫자 출력
void Generator::ShowEndNumber() {
	cout << "----------------------------------------------------" << endl;
	cout << "END NUMBER : " << curValue << endl;
	cout << "----------------------------------------------------" << endl;
}

//최종 숫자 출력
int Generator::getEndNumber() {
	cout << "----------------------------------------------------" << endl;
	cout << "END NUMBER : " << curValue << endl;
	cout << "----------------------------------------------------" << endl;
	return curValue;
}

//힌트 출력
void Generator::ShowHint() {
	cout << "----------------------------------------------------" << endl;
	cout << "HINT (count: " << hintVecRow.size() << ") : ";
	for (int i = 0; i < hintVecRow.size(); i++) {
		cout << hintNum[i] << "(" << hintVecRow[i] << "," << hintVecCol[i] << ") ";
	}
	cout << "----------------------------------------------------" << endl;
}

int ** Generator::getPuzzle()
{
	return maxMap;
}

int** Generator::getCompletePuzzle()
{
	return maxMap_Solution;
}

//int(*Generator::getPuzzle() )[MAX_SIZE_MAP]{
//    return this->maxMap;
//}
//
//int(*Generator::getCompletePuzzle() )[MAX_SIZE_MAP]{
//    return this->maxMap_Solution;
//}

vector<vector<int> > Generator::getHint() {
	vector<vector<int> > temp;

	temp.push_back(this->hintVecRow);
	temp.push_back(this->hintVecCol);
	temp.push_back(this->hintNum);
	return vector<vector<int> >(temp);
}

// int** Generator::getPuzzleTemp(){
//     return this->mapTemp;
// }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2
//main 함수(주석 해제해서 사용)
//int main(){
//    
//    //Random seed 초기화
//    //진짜로 Random을 하려면 seed값을 매번 바꿔주어야하기 때문에
//    //실행 시 최초로 한번은 실행이 되어야 한다.
//    srand((unsigned int) time(NULL));
//    
//    Generator Gen;
//    
//    int startX = Gen.getStartRow();
//    int startY = Gen.getStartCol();
//    
//    Gen.GeneratorPuzzle(startX,startY,START_NUM);
//    Gen.ShowPuzzle();
//    //Gen.ShowCompletePuzzle();
//    Gen.ShowEndNumber();
//    //Gen.ShowHint();
//    
//    return 0;
//}
