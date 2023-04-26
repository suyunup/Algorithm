/******************************************
     주어진 정수의 최대최소 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int numData;
    int data;
    int Max = -999;
    int Min = 100;

    cin >> numData;
    for (int j = 0; j < numData; j++){
      cin >> data;

      if(data > Max){
        Max = data;
      }
      if(data < Min){
        Min = data;
      }
    }

    cout << Max<<" "<<Min << endl;
  }
  return 0;

}
