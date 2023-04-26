/******************************************
    시간 계산
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int personTestCases;
    cin >> personTestCases;
    int addDay = 0;
    int addHour = 0;
    int addMinute = 0;
    int addSecond = 0;
    for(int j = 0; j < personTestCases; j++){
      int startHour,startMinute, startSecond, endHour, endMinute, endSecond;
      cin >> startHour;
      cin >> startMinute;
      cin >> startSecond;
      cin >> endHour;
      cin >> endMinute;
      cin >> endSecond;

      if((endSecond - startSecond) < 0){
        addSecond += 60 + (endSecond - startSecond);
        endMinute--;
      }else{
        addSecond += endSecond - startSecond;
      }

      if((endMinute - startHour) < 0){
        addMinute += 60 +(endMinute - startMinute);
        endHour--;
      }else{
        addMinute += endMinute - startMinute;
      }

      addHour += endHour - startHour;

      }
      while(addSecond > 59){
        addMinute += 1;
        addSecond -= 60;
      }
      while(addMinute > 59){
        addHour += 1;
        addMinute -= 60;
      }
      while(addHour > 23){
        addDay += 1;
        addHour -= 24;
      }
    cout << addDay << " " << addHour << " " << addMinute << " "<< addSecond << endl;
  }
  return 0;

}
