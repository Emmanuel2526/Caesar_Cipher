#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
bool isAlphabet(char value, string* a);
int main(){
  unordered_map<char, int> letters(26);
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for(char alphabet : alphabets){
    letters[alphabet] = i;
    i++;
  }
  string shift_string;
  string plainText;
  string cipherText;
  cout << "Shift: ";
  getline(cin, shift_string);
  shift_string.erase(remove_if(shift_string.begin(), shift_string.end(), ::isspace), shift_string.end());
  int shift = stoi(shift_string);
  if(shift < 0){
    shift = (shift % 26) + 26;
  }
  cout << "PlainText: ";
  getline(cin, plainText);
  for(char alphabet : plainText){
    if(isAlphabet(alphabet, &alphabets)){
      cout << alphabets[(letters[alphabet] + shift) % 26];
    }else{
      cout << alphabet;
    }
  }
  return 0;
}
bool isAlphabet(char value, string* a){
  for(char alphabet : *a){
    if(value == alphabet){
      return true; 
    }
  }
  return false;
}