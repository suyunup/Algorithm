/******************************************
    집합연산
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){//교집합 합집합 차집합 개수 원소 순 오름차순 공백두기
    // int a;
    // cin >>a;
    // unsigned int Aset[132] = {0,};
    // unsigned int Bset[132] = {1,};
    // for(int i = 0; i < a; i++){
    //   int temp;
    //   cin >> temp;
    //   Aset[temp - 1] = 1;
    // }
    // unsigned int Cset[132] = Aset[132] & Bset[132];
    // // for(int i = 0; i < 132; i++){
    // //   if(Aset[i - 1]&&Bset[i - 1]){
    // //     cout << i << " ";
    // //   }
    // // }




    int m,n;
    cin >> m;
    int Aset[132] = {0,};
    for(int i = 0; i < m; i++){
      int temp;
      cin >> temp;
      Aset[temp]++;
    }
    cin >> n;
    int Bset[132] = {0,};
    for(int i = 0; i < n; i++){
      int temp;
      cin >> temp;
      Bset[temp]++;
    }

    int Cset[132] = {0,};
    int c = 0;
    for(int i = 0; i < 132; i++){
      if(Aset[i]& Bset[i]){
        Cset[i]++;
        c++;
      }
    }
    int Dset[132] = {0,};
    int d = 0;
    for(int i = 0; i < 132; i++){
      if(Aset[i]| Bset[i]){
        Dset[i]++;
        d++;
      }
    }

    int Eset[132] = {0,};
    int e = 0;
    for(int i = 0; i < 132; i++){
      if(Aset[i]){
        if(Bset[i]){
          continue;
        }
        Eset[i]++;
        e++;

      }
    }


    cout << c << " ";
    for(int i = 0; i < 132; i++){
      if(Cset[i] != 0){
        cout << i << " ";
      }
    }
    cout << endl;

    cout << d << " ";
    for(int i = 0; i < 132; i++){
      if(Dset[i] != 0){
        cout << i << " ";
      }
    }
    cout << endl;
    cout << e << " ";
    for(int i = 0; i < 132; i++){
      if(Eset[i] != 0){
        cout << i << " ";
      }
    }
    cout <<endl;






  }
  return 0;

}
