/******************************************
    방의 크기 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int xCheck[4] = { 1,-1,0,0 };
int yCheck[4] = { 0,0,1,-1 };
char square[100][100];//room
int check[100][100] = {1,};//roomcheck
int galo, selo;
int houseSizeCount = 0;


//검사하는 함수
void houseCheck(int i, int j){
  check[i][j] = 1;
  houseSizeCount++;
  for(int k = 0; k < 4; k++){
    int nexti, nextj;
    nexti = i + xCheck[k];
    nextj = j + yCheck[k];
    if(square[nexti][nextj] == '.' && check[nexti][nextj] == 0){
        houseCheck(nexti, nextj);
    }
  }
}

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int a = 0; a < numTestCases; a++){
    int last = 0;
    vector<int> houseSize;
    for(int i = 0; i < 100; i++){//초기화 시키기
      for(int j = 0; j < 100; j++){
        check[i][j] = 1;
      }
    }



    cin >> galo;
    cin >> selo;
    for(int i = 0; i < selo; i++){
      for(int j = 0; j < galo; j++){
        cin >> square[i][j];

      }
    }


    for(int i = 0; i < selo; i++){
      for(int j = 0; j < galo; j++){
        check[i][j] = 0;

      }
    }

    for(int i = 0; i < selo; i++){
      for(int j = 0; j < galo; j++){

        if(square[i][j] == '.' && check[i][j] == 0){
          houseSizeCount = 0;
          last++;
          houseCheck(i,j);
          houseSize.push_back(houseSizeCount);
        }
      }
    }


    cout << last <<endl;
    sort(houseSize.begin(), houseSize.end(), greater<int>());
    for(int i = 0; i < houseSize.size(); i++){
      cout << houseSize[i]<<" ";
    }
    cout <<endl;













  }
  return 0;

}
/*
29 13
+++++++++++++++++++++++++++++
+.......+.......+...........+
++++....+++++...+....++++...+
+..+........+...+....+..+...+
+..+++++....+++++....++++...+
+...........+...+....+..+...+
+..++++++++++...++++++..+...+
+..+.........+++........+...+
+..+.........+.+..+++...+...+
+..+.........+.+..+++...+...+
+...+........+.+..+++...+...+
+....+.......+.+........+...+
+++++++++++++++++++++++++++++


5 3
+++++
+...+
+++++

3 3
+++
+.+
+++









*/
