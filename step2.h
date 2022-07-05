#ifndef _STEP2_H
#define _STEP2_H
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stack>
#include "step3.h"
using namespace std;
vector<int> tarr;
string tstr;

int word;//0-3:+ - * / 4:num val 5:( 6:)



string handle(char c, char cha){
  string f;
  
  if(c == 'E'){
    if(cha == 'i' || cha == '('){
      f = "eT";
    } 
    else {
      f = "1";
    } 
    return f;
  }
  else if(c == 'T'){
    if(cha == 'i' || cha == '('){
      f = "tF";
    }
    else {
      f = "1";
    }
    return f;
  }
  else if(c == 'e'){
    if(cha == ')'||cha == '$'){
      f = "0";
    }
    else if(cha == '+'|| cha == '-'){
      f = "eTA";
    }
    else {
      f = "1";
    }
    return f;
  }
  else if(c == 'F'){
    if(cha == 'i'){
      f = "i";
    }
    else if(cha == '('){
      f = ")E(";
    }
    else {
      f = "1";
    }
    return f;
  }
  else if(c == 'A'){
    if(cha == '+'){
      f = "+";
    }
    else if(cha == '-'){
      f = "-";
    }
    else{
      f = "1";
    }
    return f;
  }
  else if(c == 'M'){
    if(cha == '*'){
      f = "*";
    }
    else if(cha == '/'){
      f = "/";
    }
    else{
      f = "1";
    }
    return f;
  }
  else if(c == 't'){
    if(cha == ')' || cha == '+' || cha == '-' || cha == '$'){
      f = "0";
    }
    else if(cha == '*' || cha == '/'){
      f = "tEM";
    }
    return f;
  }
  f = "1";
  return f;
}


bool ll1(){
  if(err == 1){
    cout << "ERROR: INVALID STRING !"<< endl;
    return false;
  }
  stack<char> s;
  string str;
  s.push('$');
  s.push('E');
  for(int i = 0; i < tarr.size(); i++){
    while(s.top() != ch[tarr[i]]){
      tstr = handle(s.top(), ch[tarr[i]]);
      if(tstr == "1") return false;
      s.pop();
      for(int j = 0; j < tstr.size(); j++){
        s.push(tstr[j]);
      }
      if(s.top() == '0') s.pop();
    }
    s.pop();
  }
  return true;
}


#endif