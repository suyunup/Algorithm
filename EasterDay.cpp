/******************************************
     부활절날짜계산
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int re = 0; re < numTestCases; re++){
    int year;
    cin >> year;
    int century = year/100;
    int n = year - (year/19)*19;
    int t = (century -17) / 25;
    int i = century -(century/4 + (century-t)/3) + n*19 + 15;
    int j = i - (i/30)*30;
    int k = j -( j/28 *(1 - j/28) * (29/(j + 1)) * ((21-n)/11));
    int l = year+ year/4 +j +2 -century+ century/4;
    int p = l - (l/7)*7;
    int q = k - p;
    int month = (q + 40)/44 + 3;
    int day = q + 28 - month/4*31;
    // cout << n<< endl;
    // cout << t << endl;
    // cout << i << endl;
    // cout << j << endl;
    // cout << k << endl;
    // cout << l << endl;
    // cout << p << endl;
    // cout << q << endl;
    cout << month<<" "<< day << endl;
  }
  return 0;

}
