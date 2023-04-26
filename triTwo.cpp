/******************************************
    삼각형의 종류-2
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int x1, y1, x2, y2, x3, y3;
    cin >>x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int first, second, third;
    first = pow(x1 - x2,2) + pow(y1 - y2, 2);
    second = pow(x2 - x3, 2) + pow(y2- y3, 2);
    third = pow(x1 - x3, 2) + pow(y1 - y3, 2);
    int maxLine;
    if(first >= second && first >= third){
      maxLine = first;
    }else if(second >= third){
      maxLine = second;
    }else{
      maxLine = third;
    }

    if( (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1) == 0 ){
      cout << 0;
    }else if(first + second + third - maxLine == maxLine){
      cout << 1;
    }else if(first + second + third - maxLine < maxLine){
      cout << 2;
    }else{
      cout << 3;
    }
    cout << endl;





  }
  return 0;

}
