#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;
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
char c[10] = {'#','(',')','{','}','[',']',',',';',' '};
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
void init_table(){
  for(int i = 0; i < 100; i++){
    table[i].num = -1;
    for(int j = 0; j < 20; j++){
      table[i].val[j] = '*';
    }
  }
}

void print_table(){
  int i = 0;
  while(table[i].num != -1){
    cout << setiosflags(ios::left) << setw(20) << table[i].val << table[i].num<<endl;
    i++;
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
          outfile << "<" << token << " " << i + 50 << ">    " << "key word" << endl;
          over = 1;
        }
        
      }
      if(!over){
        temp = 0;
        while(table[temp].num != -1){
          temp = temp + 1;
          if(strcmp(token, table[temp - 1].val) == 0){
            outfile << "<" << token << " " << 100 + table[temp].num << ">    " << "biaoshifu"<< endl;
            f = 1;
            break;
          }
        }
        
        if(!f){ 
          strcpy(table[cur].val, token);
          table[cur].num = cur;
          outfile << "<" << token << " " << 100 + table[cur].num << ">    " << "biaoshifu"<< endl;
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
      outfile << "<" << token << " " << 49 << ">" << "    " << "number" <<endl;
    }
    else if(now_char == '*' || now_char == '/'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      if(now_char == '='){
        token[t] = now_char;
        outfile << "<" << token << " " << 11 << ">" << "    " << "yunsuanfu" <<endl;
        infile >> noskipws >> now_char;
      }
      else{
         outfile << "<" << token << " " << 12 << ">" << "    " << "yunsuanfu" <<endl;
      }
    }
     else if(now_char == '+' || now_char == '-'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      if(now_char == '=' || now_char == '+' || now_char == '-'){
        token[t] = now_char;
        outfile << "<" << token << " " << 11 << ">" << "    " << "yunsuanfu" <<endl;
        infile >> noskipws >> now_char;
      }
      else{
         outfile << "<" << token << " " << 12 << ">" << "    " << "yunsuanfu" <<endl;
      }
    }
    else if(now_char == '?' || now_char == ':'){
      token[t] = now_char;
      t++;
      infile >> noskipws >> now_char;
      outfile << "<" << token << " " << 12 << ">" << "    " << "yunsuanfu" <<endl;
    }
    else{
      token[t] = now_char;
      for(int i = 0; i < 10; i++){
        if(token[t] == c[i]){
          t++;
          token[t] = '\0';
          outfile << "<" << token << " " << i << ">" << "    " << "jiefu" <<endl;
          break;
        }
      }
      infile >> noskipws >>now_char;
    }
    
    init_token();
  }
}


int main(){
  init_token();
  init_table();
  infile.open("demo.c", ios::in);
  outfile.open("tokens.txt", ios::out);
  my_scan();
  print_table();  
}
