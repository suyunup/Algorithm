/******************************************
    배열의 곱
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int first, second, third;
    cin >> first;
    cin >> second;
    cin >> third;
    int A[first][second];
    for(int i = 0; i < first; i++){
      for(int j = 0; j < second; j++){
        cin >> A[i][j];
      }
    }
    int B[second][third];
    for(int i = 0; i < second; i++){
      for(int j = 0; j < third; j++){
        cin >> B[i][j];
      }
    }
    int answer[first][third];

    int number = 0;
    for(int k = 0; k < third;k++){
      for(int i = 0; i < first; i++){
        for(int j = 0; j < second; j++){
          number += A[i][j]*B[j][k];
        }
        answer[i][k] = number;
        number = 0;
      }
    }
    for(int i = 0; i < first; i++){
      for(int j = 0; j < third; j++){
        cout << answer[i][j] << " ";
      }
      cout << endl;
    }




  }
  return 0;

}
