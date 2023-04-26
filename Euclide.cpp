#include <iostream>
using namespace std;

int Euclide(int a, int b){
    int temp;
    int rest; 
    if(a>b){
            temp = a;
            a = b;
            b = temp;
        }
    rest = b%a; 
if (rest == 0){
    return a;

}
else{
    return Euclide(rest, a);
}
}

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int a;
    int b;
    int result;

    cin >> a >> b;
    if( a== 0 && b == 0){
        cout << 0 << endl;
    }else if(a == 0){
        cout << b<<endl;
    }else if(b == 0){
        cout << a<< endl;
    }else{
        result = Euclide(a,b);
        cout << result<< endl;
    }

  }
  return 0;

}