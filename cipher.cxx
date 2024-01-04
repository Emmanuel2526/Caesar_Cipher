#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
bool isAlphabet(char value, string* a);
void print(string value);
void Caesar_Cipher();
int main(){
  Caesar_Cipher();
  return 0;
}
void print(string value){
	cout << value << endl;
}
string input(string prompt){
	string value;
	cout << prompt;
	getline(cin, value);
	return value;
}
bool isAlphabet(char value, string* a){
  for(char alphabet : *a){
    if(value == alphabet || value == toupper(alphabet)){
      return true; 
    }
  }
  return false;
}
void Caesar_Cipher(){
	print("A Caesarean Cipher Encryption and Decryption Programme by Osazuwa.E.O \nPositive shifts can be used to encrypt, while negative shifts can be used for decryption.");
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
  while(true){
  	bool shift_check = false;
  	int shift;
  	while(!shift_check){
  		//Taking In shift value as a string to be processed
  		shift_string = input("Shift: ");
  		string shift_string1 = shift_string;
  		shift_string1.erase(remove_if(shift_string1.begin(), shift_string1.end(), ::isspace), shift_string1.end());
  		try{
  			shift = stoi(shift_string);
  			int shift1 = stoi(shift_string1);
  			if(shift != shift1){
  				print("Invalid Shift");
  			}else{shift_check = true;}
  		}catch(...){print("Invalid Shift");}
  	}
  	if(shift < 0){
    	shift = (shift % 26) + 26;
  	}
  	bool plainText_check = false;
  	while(!plainText_check){
  		plainText = input("PlainText/CipherText: ");
  		string plainText1 = plainText;
  		plainText1.erase(remove_if(plainText1.begin(), plainText1.end(), ::isspace), plainText1.end());
  		if(plainText1.size() == 0){
  			print("We don't encrypt empty data.");
  		}else{plainText_check = true;}
  	}
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
  	print("Result: " + cipherText);
  	cipherText = "";
  	string quit = input("Do you want to quit y/n?: ");
  	if(quit == "y"){break;}
  }
}