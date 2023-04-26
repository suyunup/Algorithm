/******************************************
    소수 판별
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int number;
    cin >> number;
    bool isDecimal = true;

    for(int i = 2; i <= sqrt(number); i++){
      if(number % i == 0){
        isDecimal = false;
      }
    }

    if(isDecimal == true){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }



  }
  return 0;

}
