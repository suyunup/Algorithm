/******************************************
    다각형 면적
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
    int vertex;
    cin >> vertex;
    int polygonArea = 0;
    int preX, preY, firstX, firstY;
    cin >> preX >> preY;
    firstX = preX;
    firstY = preY;


    for(int j = 0; j< vertex-1; j++){
      int x, y;
      cin >> x >> y;
      polygonArea += (preX + x)*(y - preY);
      preX = x;
      preY = y;
    }
    polygonArea += (preX + firstX)*(firstY - preY);


    if(polygonArea < 0){//시계
      cout << -1*polygonArea <<" "<< -1<<endl;
    }else{
      cout << polygonArea << " "<< 1 << endl;
    }



  }
  return 0;

}
