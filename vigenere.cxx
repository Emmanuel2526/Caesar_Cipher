#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;
bool isAlphabet(char value, string* a);
void print(string value);
void Vigenere_Cipher();
string removeSpace(string value);
string input(string prompt);
int main(){
  //Cipher Function.
  Vigenere_Cipher();
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
string removeSpace(string value){
	value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());
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
void Vigenere_Cipher(){
 print("A Vigunere Cipher Encryption and Decryption Programme by Osazuwa.E.O \nEnter 1 to encrypt, 2 to decrypt."); 
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
  string key;
  string plainText;
  string cipherText = "";
  while(true){
  	//Finding out if user wants to encrypt or decrypt data.
  	bool state_check = false;
  	int state;
  	while(!state_check){
  		string state_string = removeSpace(input("Operation: "));
  		if(state_string == "1"){
  			state = 1;
  			state_check = true;
  		}else if(state_string == "2"){
  			state = -1;
  			state_check = true;
  		}else{print("Invalid Operation.");}
  	}
  	bool key_check = false;
  	string key;
  	while(!key_check){
  		//Taking In key value as a string to be processed
  		key = input("key: ");
  		string key1 = key;
  		key = removeSpace(key);
  		//key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
  		if(key.size() == 0 || key != key1){
  			print("Invalid key");
  		}else{key_check = true;}
  	}
  	bool plainText_check = false;
  	while(!plainText_check){
  		plainText = input("PlainText: ");
  		string plainText1 = removeSpace(plainText);
  		//plainText1.erase(remove_if(plainText1.begin(), plainText1.end(), ::isspace), plainText1.end());
  		if(plainText1.size() == 0){
  			print("We don't encrypt empty data.");
  		}else{plainText_check = true;}
  	}
  	i = 0;
  	for(char alphabet : plainText){
    	if(isAlphabet(alphabet, &alphabets)){
      	if(alphabet == toupper(alphabet)){
      		char v = alphabets[(letters[alphabet] + letters[key[i % key.size()]]) % 26];
      		cipherText += toupper(v);
      	}else{
      		cipherText += alphabets[(letters[alphabet] + letters[key[i % key.size()]]) % 26];
      	}
      	i++;
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