/******************************************
    사각형과 점과의 거리
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cmath>
using namespace std;
int cul_1(int x1,int y1,int x2,int y2){
  return (x1-x2)*(x1-x2) +(y1 - y2)*(y1 -y2);
}

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int x1, y1, x2, y2;
    cin >> x1 >>y1 >> x2>> y2;
    int x3, y3;
    cin >>x3 >>y3;
    if(x1<=x3 && x3 <= x2 && y1 <=y3 && y3 <= y2){
      cout << 0 <<" " << 0;
    }else if(y3 < y1){
      if(x3 < x1){
        cout << pow(x1-x3,2) + pow(y1- y3,2)<< " "<< x1-x3 + y1- y3;
      }else if(x1 <= x3 && x3 <= x2){
        cout << pow(y1 - y3,2) << " " << y1 - y3;
      }else{
        cout <<  pow(x3-x2,2) + pow(y1-y3,2)<<" "<< x3-x2 + y1-y3;
      }
    }else if(y1 <= y3 && y3 <=y2){
      if(x2 <= x3){
        cout << pow(x3-x2,2) <<" "<< x3- x2;
      }else{
        cout << pow(x1-x3,2) <<" "<< x1 - x3;
      }
    }else{
      if(x2 <= x3){
        cout << pow(x3- x2,2)+ pow(y3 - y2,2)<<" "<< x3- x2+ y3 - y2;
      }else if(x1 <= x3 && x3<= x2){
        cout << pow(y3-y2,2) <<" "<< y3 - y2;
      }else{
        cout << pow(y3- y2,2) + pow(x1 - x3,2)<<" "<< y3- y2 + x1 - x3;
      }
    }
    cout << endl;



  }
  return 0;

}
