/******************************************
    삼각형의 종류-1
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
    int first, second, third;
    cin >> third>>second>>first;

    if(third + second <= first){
      cout << 0;
    }else if(first == second&& second == third && first == third){
      cout << 1;
    }else if(pow(third,2) + pow(second,2) == pow(first, 2)){
      cout << 2;
    }else if(second == third|| second == first || third == first){
      cout << 3;
    }else{
      cout << 4;
    }
    cout << endl;


  }
  return 0;

}
