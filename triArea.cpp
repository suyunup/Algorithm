/******************************************
    삼각형의 면적
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >>x2 >> y2 >> x3 >> y3;
    int result = (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);

    if(result == 0){
      cout << result <<" "<< 0;
    }else if(result < 0){
      cout << result*-1 <<" "<< -1;
    }else{
      cout <<result << " " << 1;
    }

    cout << endl;





  }
  return 0;

}
