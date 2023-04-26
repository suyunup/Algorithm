/******************************************
    두 정수 사이의 모든 정수의 합
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int startNumber;
    int endNumber;
    int sum = 0;
    cin >> startNumber;
    cin >> endNumber;

    for(int j = startNumber; j <= endNumber; j++){
      sum += j;

    }

    cout << sum<< endl;
  }
  return 0;

}
