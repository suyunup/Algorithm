/******************************************
    수직 수평 성분의 교차
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int x11,y11,x12,y12;
    int x21,y21,x22,y22;
    int temp = 0;
    cin>> x11 >> y11 >> x12 >> y12;
    cin>> x21 >> y21 >> x22 >> y22;

    if(x11 == x12){//첫선분이 수직
      if(y11 > y12){
      temp = y11;
      y11 = y12;
      y12 = temp;
    }
    if(x21 > x22){
      temp = x21;
      x21 = x22;
      x22 = temp;
    }
      if((x21==x11 || x22==x11)&&(y11<=y21&& y21<=y12)){
        cout << 2;
      }else if((y21 == y11 || y21 == y12)&&(x21 <= x11&& x11 <= x22)){
        cout << 2;
      }else if(((x21<x11&&x11<x22)||(x22<x11&& x11<x21))&&((y11<y21&&y21<y12)||(y12<y21&&y21<y11))){
        cout << 1;
      }else{
        cout << 0;
      }

    }else{
      if(y21 > y22){
        temp = y21;
        y21 = y22;
        y22 = temp;
      }
      if(x11 > x12){
        temp = x11;
        x11 = x12;
        x12 = temp;
      }
      if((x21 == x11 || x21 == x12)&&(y21 <= y11&&y11 <=y22)){
        cout << 2;
      }else if((y12 == y22 || y12 == y21)&&(x11 <=x21 && x21<= x12)){
        cout << 2;
      }else if(((x11<x21&&x21<x12)||(x12<x21&&x21<x11))&&((y21<y11&&y11<y22)||(y22<y11&&y11<y21))){
        cout << 1;
      }else{
        cout << 0;
      }
    }


    cout << endl;





  }
  return 0;

}
