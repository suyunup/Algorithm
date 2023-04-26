/******************************************
    끝자리 숫자 계산하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int numData, data;
    int last1Digit = 1;
    cin >> numData;

    for(int j = 0; j < numData; j++){
      cin >> data;
      last1Digit *= data ;
      last1Digit %= 10;

    }
    cout << last1Digit << endl;
  }
  return 0;

}
