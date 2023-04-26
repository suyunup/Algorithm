#include <iostream>
using namespace std;

int main(){
  double d;
  char *cp = (char *)&d;
  int *ip = (int *)&d;
  float *fp = (float *)&d;
  double *dp = &d;

  cout << "d의 주소 : " << &d << endl;

  d = 0.2142;

  cout << "char:" << *cp << endl;
  cout << "int:" << *ip << endl;
  cout << "float:" << *fp << endl;
  cout << "double:" << *dp << endl;


  return 0;
}
