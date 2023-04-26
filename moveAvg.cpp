/******************************************
    이동평균
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int arrayNumber;
    cin >> arrayNumber;
    int array[arrayNumber];
    for(int i = 0; i < arrayNumber; i++){
      cin >> array[i];
    }
    int movingavg;
    cin >> movingavg;

    int k = arrayNumber - movingavg + 1;

    cout << k << " ";
    for(int i = 0; i < k; i++){
      int temp = 0;
      int a = i;
      for(int j = 0; j < movingavg; j++){
        temp += array[a];
        a++;
      }
      cout << temp/movingavg << " ";
    }
    cout << endl;



  }
  return 0;

}
