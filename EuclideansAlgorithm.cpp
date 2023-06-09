#include <iostream>
using namespace std;



int Eucl(int, int); //유클리드 알고리즘을 구현한 함수의 정의



int main(void){

int a, b, big; // a, b는 입력받을 두 정수, big은 두 수를 비교할 때 사용할 변수

int gcm; // 유클리드 알고리즘 함수의 반환값을 받기 위한 변수
 // a, b 두수를 입력 받는다.
cin >> a >> b; 

   

if (a>b){ // a, b를 비교해서 b쪽에 큰 수가 오도록 정렬하는 조건문

big = a;

a = b;

b = big;

}


    cout << gcm = Eucl(a,b);

return 0;

}



int Eucl(int a, int b){

int remain; // 나머지를 받기 저장하기 위한 변수

remain = b%a; // b를 a로 나눈 나머지를 remain에 저장한다.



if (remain == 0) // remain이 0이라는 것은 a가 a, b의  최대공약수라는 것을 의미한다.
    return a;
else

return Eucl(remain, a); // 최대공약수를 찾지 못했으므로 유클리드 알고리즘을 반복한다.

}




