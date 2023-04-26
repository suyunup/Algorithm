/******************************************
    행렬덧셈
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int row, column;
    cin >> row >> column;

    int firstMatrix[row][column];
    for(int i = 0; i < sizeof(firstMatrix)/sizeof(firstMatrix[0]); i++){
      for(int j = 0; j < sizeof(firstMatrix[0])/sizeof(firstMatrix[i][0]); j++){
        cin >> firstMatrix[i][j];
      }
    }

    int secondMatrix[row][column];
    for(int i = 0; i < sizeof(firstMatrix)/sizeof(firstMatrix[0]); i++){
      for(int j = 0; j < sizeof(firstMatrix[0])/sizeof(firstMatrix[i][0]); j++){
        cin >> secondMatrix[i][j];
      }
    }

    for(int i = 0; i < sizeof(firstMatrix)/sizeof(firstMatrix[0]); i++){
      for(int j = 0; j < sizeof(firstMatrix[0])/sizeof(firstMatrix[i][0]); j++){
        cout << firstMatrix[i][j] + secondMatrix[i][j] << " ";
      }
      cout << endl;
    }






  }
  return 0;

}
