/******************************************
    PI 찾기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cmath>
using namespace std;



int main(){
  int variableCount;
  cout << "minterm의 개수는?: ";
  cin >> variableCount;

  int PIarray[variableCount];

  for(int i = 0; i < variableCount; i++){
    cout <<"minterm을 입력:";
    cin >> PIarray[i];
  }

  // int newArray[PIarray.length()] = NULL;
  // do{


  for(int i = 0; i < sizeof(PIarray)/sizeof(PIarray[0]); i++){
    int firstCount, temp;
    temp = PIarray[i];
    for(int j = 0; j < sizeof(PIarray)/sizeof(PIarray[0]); j++){
      if(temp % 10 == 1){//1개수 세기
        firstCount++;
      }
      temp /= 10;
    }

    for(int j = i; j < sizeof(PIarray)/sizeof(PIarray[0]); j++){
      int secondCount, temp;
      temp = PIarray[i];
      for(int j = 0; j < sizeof(PIarray)/sizeof(PIarray[0]); j++){
        if(temp % 10 == 1){//1개수 세기
          secondCount++;
        }
        temp /= 10;
      }

      if((firstCount - secondCount == 1) || (firstCount -secondCount == -1)){

        cout << PIarray[i]<< endl;
      }



    // }while(newArray != NULL);




    }
  }








  return 0;

}
