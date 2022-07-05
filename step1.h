#ifndef _STEP1_H
#define _STEP1_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;

vector<int> program;
struct valtable{
  char val[20];
  int num;
}table[100];
char token[20];
int t = 0;
ifstream infile;
ofstream outfile;
char now_char;
char key_word[16][20] = {"main","int","return","double","long","float","void","include","char","if","else","switch","case","printf","break","continue"};
char c[11] = {'=','#','(',')','{','}','[',']',',',';',' '};
int over = 0;
int f = 0;
int cur = 0;
int temp;

void init_token(){
  t = 0;
  for(int i = 0; i < 20; i++){
    token[i] = NULL;
  }
  
}

void print_table(){
  int i = 0;
  while(table[i].num != -1){
    cout << setiosflags(ios::left) << setw(20) << table[i].val << table[i].num<<endl;
    i++;
  }
}
void init_table(){
  for(int i = 0; i < 100; i++){
    table[i].num = -1;
    for(int j = 0; j < 20; j++){
      table[i].val[j] = '*';
    }
  }
}

void my_scan(){
  infile >> noskipws >>now_char;
  while(!infile.eof()){
    while(now_char == ' ' || now_char == '\n' || now_char == '\t'){
      infile >> noskipws >> now_char;
    }
    if((now_char >= 'a' && now_char <= 'z')||(now_char >= 'A' && now_char <= 'Z')){
      token[t] = now_char;
      infile >> noskipws >> now_char;
      while((now_char >= 'a' && now_char <= 'z')||(now_char >= 'A' && now_char <= 'Z') || (now_char >= '1' && now_char <= '9') || now_char == '_'){
        t++;
        token[t] = now_char;
        infile >> noskipws >> now_char;
      }
      t++;
      token[t] = '\0';
      for(int i = 0; i < 16; i++){
        if(strcmp(token, key_word[i]) == 0){
          outfile << "<" << token << " " << 100 + i << ">    " << "key word" << endl;
          program.push_back(100 + i);
          over = 1;
        }
        
      }
      if(!over){
        temp = 0;
        while(table[temp].num != -1){
          temp = temp + 1;
          if(strcmp(token, table[temp - 1].val) == 0){
            outfile << "<" << token << " " << 1 << ">    " << "biaoshifu"<< endl;
            program.push_back(temp);
            f = 1;
            break;
          }
        }
     
        if(!f){ 
          strcpy(table[cur].val, token);
          table[cur].num = cur;
          outfile << "<" << token << " " << 1 << ">    " << "biaoshifu"<< endl;
          program.push_back(temp);
          cur++;
        }
      
      }
      over = 0;
      f = 0;
     
    }
   
    else if(now_char >= '0' && now_char <= '9'){
      token[t] = now_char;
      infile >> noskipws >> now_char;
      while((now_char >= '0' && now_char <= '9') || now_char == '.'){
        t++;
        token[t] = now_char;
        infile >> noskipws >> now_char;
      }
      t++;
      token[t] = '\0';
      outfile << "<" << token << " " << 2 << ">" << "    " << "number" <<endl;
      program.push_back(2);
    }
    else if(now_char == '*' || now_char == '/'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      if(now_char == '='){
        token[t] = now_char;
        outfile << "<" << token << " " << 4 << ">" << "    " << "yunsuanfu" <<endl;
        program.push_back(4);
        infile >> noskipws >> now_char;
      }
      else{
         outfile << "<" << token << " " << 4 << ">" << "    " << "yunsuanfu" <<endl;
         program.push_back(4);
      }
    }
     else if(now_char == '+' || now_char == '-'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      if(now_char == '=' || now_char == '+' || now_char == '-'){
        token[t] = now_char;
        outfile << "<" << token << " " << 4 << ">" << "    " << "yunsuanfu" <<endl;
        program.push_back(4);
        infile >> noskipws >> now_char;
      }
      else{
         outfile << "<" << token << " " << 4 << ">" << "    " << "yunsuanfu" <<endl;
         program.push_back(4);
      }
    }
    else if(now_char == '='){
      token[t] = now_char;
      infile >> noskipws >> now_char;
      outfile << "<" << token << " " << 5 << ">" << "    " << "yunsuanfu" <<endl;
      program.push_back(5);
    }
    else if(now_char == '?' || now_char == ':'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      outfile << "<" << token << " " << 4 << ">" << "    " << "yunsuanfu" <<endl;
      program.push_back(4);
    }
    else{
      token[t] = now_char;
      for(int i = 0; i < 10; i++){
        if(token[t] == c[i]){
          t++;
          token[t] = '\0';
          outfile << "<" << token << " " << 120 + i << ">" << "    " << "jiefu" <<endl;
          program.push_back(120 + i);
          break;
        }
      }
      infile >> noskipws >>now_char;
    }
    
    init_token();
  }
}
#endif