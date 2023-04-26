/******************************************
    해밍 코드
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int type, decimalNumber;
    cin >> type;
    cin >> decimalNumber;
    if(type == 0){//입력 데이터는 실제 데이터
      int first, second, fourth, eighth, sixteenth;

      int binaryNumber[31] = {0,};
      for(int j = 31; j > 0;j--){//2진수 변환
        int binary = decimalNumber % 2;
        binaryNumber[j] = binary;
        decimalNumber /= 2;
      }
    }else{//입력 데이터는 해밍 코드

    }





  }
  return 0;

}
