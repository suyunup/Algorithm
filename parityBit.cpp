/******************************************
    패리티비트
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
    int decimalNumber, firstnumber;
    cin >> decimalNumber;
    firstnumber = decimalNumber;

    int binaryNumber[32] = {0,};
    for(int j = 31; j > 0;j--){
      int binary = decimalNumber % 2;
      binaryNumber[j] = binary;
      decimalNumber /= 2;
    }

    int searchOne = 0;
    for(int l = 0; l < 32; l++){
      if(binaryNumber[l] == 0){
        searchOne++;
      }
    }
    if(searchOne % 2 == 1){
      if(binaryNumber[0] == 0){
        binaryNumber[0] = 1;
      }else{
        binaryNumber[0] = 0;
      }

      long result = 0;
      for(int k = 0; k < 32; k++){
        result += binaryNumber[31 - k]*pow(2, k);
      }
      if(result < 0){
        cout << result * -1 << endl;
      }else{
      cout << result << endl;
      }

    }else{
      cout << firstnumber<<endl;
    }






  }
  return 0;

}
