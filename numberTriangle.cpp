/******************************************
    숫자로 삼각형 출력하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int triangleSize;
    cin >> triangleSize;

    for(int j = 1; j <= triangleSize; j++){
      int p = triangleSize -1;
      int repeat = j;
      for(int k = 1; k <= j; k++){
        cout << repeat <<" ";
        repeat += p;
        p--;
      }
      cout << endl;

    }

  }
  return 0;

}
