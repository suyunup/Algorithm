#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
  if(argc != 2){
    cout << "usage: ./args n\n";
    return -1;
  }
  int n = atoi(argv[1]);
  srand(n);
  for(int i = 0; i < 10; i++){
    int dice = rand()%6 + 1;
    cout << dice << " ";
  }
  cout << endl;
  return 0;
}
