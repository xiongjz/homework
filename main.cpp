#include "step1.h"
#include "step2.h"
#include "step3.h"
int main(){
  init_token();
  init_table();
  infile.open("demo.c", ios::in);
  outfile.open("tokens.txt", ios::out);
  my_scan();
  for(int i = 0; i < program.size(); i++){
    cout << program[i] << " ";
  }
  printf("\n");
  print_table();
  printf("\n");
  str = "a+4";
  get_word();
  z();
  for(int i = 0; i < arr.size(); i++){
    printf("%c",ch[arr[i]]);
    
  }
  printf("\n");
  for(int i = 0; i < q.size(); i++){
    printf("%c ",q[i]);
    if((i+1)%4 == 0){
      printf("\n");
    }
  }
  a();
}