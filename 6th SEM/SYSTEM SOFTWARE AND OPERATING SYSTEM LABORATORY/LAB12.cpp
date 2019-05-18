
#include<iostream>
#inculde<unistd.h>

int main(int argc, char* argv[])
{
 using namespace std;
 if(argc!=3)
 {
  cout<<"Usage ./a.out sourcefile destination file\n";
  return 0;
 }
 if(link(argv[1],argv[2])==-1)
 {
  cout<<"cant link\n";
  return 1;
 }
 else
 {
  cout<<"Files have been Linked\n";
 }
return 0;
}
