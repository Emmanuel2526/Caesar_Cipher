#include <iostream>
#include <vector>
#include <string>
#include "helper_functions.cxx"
using namespace std;
void encrypt();
void decrypt();
int main(){
  cout << "RSA Cryptosystem Encryption and Decryption Program.\n"
           << "Author: Osazuwa Emmanuel . O\n"
           << "Alias: Nelson EL.\n";
  int eod;
  while(eod != 3){
    cout << "1. For ecryption.\n"
            << "2. For Decryption.\n"
            << "3. To exit program.\n"
            << "Option: "; 
    cin >> eod;
    if(eod == 1){
    	cout << "You have choosen to encrypt your data.\n";
    	encrypt();
    }else if(eod == 2){
    	 cout << "You have choosen to decrypt data.\n";
    }else if(eod == 3){
    	cout << "Thank you for using my program.\n";
    }
  }
  return 0;
}
void encrypt(){
  long long p, q;
  p = ll_input("Enter p: ");
  q = ll_input("Enter q: ");
  //cout << "Hey";
  //int e, m; cout << "e: "; cin >> e; cout << "m: "; cin >> m;
}
