/******************************************
    시간 계산 다른 방법
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
    int lastSecond = 0;
    for(int j = 0; j < personTestCases; j++){
      int startHour,startMinute, startSecond, endHour, endMinute, endSecond;
      cin >> startHour;
      cin >> startMinute;
      cin >> startSecond;
      cin >> endHour;
      cin >> endMinute;
      cin >> endSecond;

      addSecond += (endHour - startHour)*3600;
      addSecond += (endMinute - startMinute)*60;
      addSecond += endSecond - startSecond;

      }
      addDay = (addSecond/3600)/24;
      addHour = (addSecond / 3600)%24;
      addMinute = (addSecond/60)%60;
      lastSecond = (addSecond % 60)% 60;
    cout << addDay << " " << addHour << " " << addMinute << " "<< lastSecond << endl;
  }
  return 0;

}
