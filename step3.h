#ifndef _STEP3_H
#define _STEP3_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
using namespace std;
char ch[8] = {'+', '-', '*', '/','i', '(', ')', '#'};
vector<int> arr;
stack<char> sem;
vector<char> q;
int num = 0;
int err = 0;
char anow_char;
string str;
int position;
ofstream out;
vector<char> function_stack;
void get_word();
void z();
void E(char s);
void T(char s);
void F(char s);
void GEQ(char s);
void init();
char next();

void get_word(){
  int i = 0;
  while(i < str.size()){
    if(str[i] == ' ') {}
    else if(str[i] == '+') arr.push_back(0);
    else if(str[i] == '-') arr.push_back(1);
    else if(str[i] == '*') arr.push_back(2);
    else if(str[i] == '/') arr.push_back(3);
    else if(str[i] == '(') arr.push_back(5);
    else if(str[i] == ')') arr.push_back(6);
    else if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '1' && str[i] <= '9') || str[i] == '_'){ 
     while((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '1' && str[i] <= '9') || str[i] == '_'){
      i++;
      if(i >= str.size()) break;
  }
  arr.push_back(4);
  i--;
   }
   else {
     err = 1;
     return;
   }
   i++;
  }
  arr.push_back(7);
}


void init(){
  position = -1;
}

char next(){
  position++;
  return ch[arr[position]];
}
void a(){
  out.open("out.txt",ios::out);
  out << "add $s1 $s1 3"<<endl;
   out << "add $s2 $s1 4" << endl;
  for(int i = 0; i > q.size();){
    if(q[i] = '+'){
      out << "add ";
    }
    else{
      out << "$s2 $s1 4" << endl;
    }
  }
}
void z(){
  printf("start:\n");
  init();
  anow_char = next();
  E(anow_char);
  if(anow_char == '#'){
    return;
  }
  else{
    printf("z:ERROR!\n");
    return;
  }
}

void E(char s){
  T(s);
  while(anow_char == '+' || anow_char == '-'){
    if(anow_char == '+'){
      anow_char = next();
      T(anow_char);
      GEQ('+');
    }
    else{
      anow_char = next();
      T(anow_char);
      GEQ('-');
    }
  }
  return;
}

void T(char s){
  F(s);
  while(anow_char == '*' || anow_char == '/'){
    if(anow_char == '*'){
     anow_char = next();
      F(anow_char);
      GEQ('*');
    }
    else{
      anow_char = next();
      F(anow_char);
      GEQ('/');
    }
  }
  return;
}
 
void F(char s){
  if(anow_char == 'i'){
    sem.push(anow_char);
  }
  else if(anow_char == '('){
    anow_char = next();
    E(anow_char);
    if(anow_char != ')'){
      printf("F:ERROR!\n");
      return;
    }
  }
  else{
    printf("F:ERROR!\n");
    return;
  }
  anow_char = next();
  return;
}

void GEQ(char s){
  char x = 't' + num;
  char y1,y2;
  y1 = sem.top();
  sem.pop();
  y2 = sem.top();
  sem.pop();
  q.push_back(s);
  q.push_back(y2);
  q.push_back(y1);
  sem.push(x);
  q.push_back(x);
  num++;
  return;
}
#endif