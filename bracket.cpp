/******************************************
    괄호(2)
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
bool pairCheck(char open, char close){
  return (open == '(' && close == ')') ||(open == '[' && close == ']') ||(open == '{' && close == '}');
}



int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    string checkString;
    cin >> checkString;

    stack<char> bracketStack;
    int stringSize = checkString.size();
    bool check = true;
    int idx = 0;
    char nextChar = ' ';


    while(check && (idx < stringSize)){
      nextChar = checkString.at(idx);
      switch(nextChar){
        case '(':
        case '[':
        case '{':
          bracketStack.push(nextChar);
          break;
        case ')':
        case ']':
        case '}':
          if(bracketStack.empty()){
            check = false;
          }else{
            check = pairCheck(bracketStack.top(), nextChar);
            bracketStack.pop();
          }
          break;
        default:
          break;
      }
      idx++;
    }
    if(!bracketStack.empty()){
      check = false;
    }

    if(check == true){
      cout << 1<< endl;
    }else{
      cout << 0 << endl;
    }


  }
  return 0;

}
