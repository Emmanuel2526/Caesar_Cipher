#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
bool isAlphabet(char value, string* a);
int main(){
  cout << "A Caesarean Cipher Encryption and Decryption Programme by Osazuwa.E.O \nPositive shifts can be used to encrypt, while negative shifts can be used for decryption. \nTo quit, simply type in quit as your shift value." << endl;
  //Unordered map to store alphabets
  unordered_map<char, int> letters;
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for(char alphabet : alphabets){
    letters[alphabet] = i;
    letters[toupper(alphabet)] = i;
    i++;
  }
  //Declaring variables for input and output
  string shift_string;
  string plainText;
  string cipherText = "";
  //Taking In shift value as a string to be processed
  cout << "Shift: ";
  getline(cin, shift_string);
  shift_string.erase(remove_if(shift_string.begin(), shift_string.end(), ::isspace), shift_string.end());
  int shift = stoi(shift_string);
  if(shift < 0){
    shift = (shift % 26) + 26;
  }
  cout << "PlainText/CipherText: ";
  getline(cin, plainText);
  for(char alphabet : plainText){
    if(isAlphabet(alphabet, &alphabets)){
      if(alphabet == toupper(alphabet)){
      	char v = alphabets[(letters[alphabet] + shift) % 26];
      	cipherText += toupper(v);
      }else{
      	cipherText += alphabets[(letters[alphabet] + shift) % 26];
      }
    }else{
      cipherText += alphabet;
    }
  }
  cout << "Result: "<< cipherText << endl;
  return 0;
}
bool isAlphabet(char value, string* a){
  for(char alphabet : *a){
    if(value == alphabet || value == toupper(alphabet)){
      return true; 
    }
  }
  return false;
}