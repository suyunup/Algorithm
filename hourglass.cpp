/******************************************
    모래시계 출력하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int hourglassSize;
    cin >> hourglassSize;
    int blank = 0;
    int hourglass = hourglassSize;
    int mid = hourglassSize / 2;

    for(int j = 0; j < hourglassSize; j++){
      for(int k = 0; k < blank; k++){
        cout<< "-";
      }
      for(int m = 1; m <= hourglass; m++){//모래시계 안쪽

        if(j%2 == 1 && m%2 == 0){
          cout << "+";
        }else if(j%2 == 0 && m%2 == 0){
          cout << "+";
        }else{
          cout << "*";
        }


      }
      for(int n = 0; n < blank; n++){
        cout << "-";
      }
      cout << endl;
      if(j >= mid){
        hourglass += 2;
        blank--;
      }else{
        hourglass -= 2;
        blank++;
      }
    }





  }
    return 0;
  }
