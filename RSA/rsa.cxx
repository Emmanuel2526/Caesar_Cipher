#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll power(ll v, ll e);
vector<string> ne(string v);
string tlc(string v);
ll gcd(ll a, ll b);
int main(){
 ll e, m;
 cout << "Public Key (e, m): ";
 cin >> e >> m;
 /*
 ll p,q;
 cout << "p q: ";
 cin >> p >> q;
 ll m = p * q;
 ll phi_m = (p-1) * (q-1);
 ll e = 2;
 while(gcd(e, phi_m) != 1){e++;}
 cout << "e, m: "<< e << ", " << m << "\n";
 */
 string pt;
 cout << "plainText: ";
 cin >> pt;
 pt = tlc(pt);
 vector<string> ptb = ne(pt);
 string ir = "26";
 ll nb = 0;
 while(m > stoll(ir)){
    ir += "26";
    ++nb;
 }
 cout << "block length: " << nb << "\n";
 vector<ll> blocks;
 string bm = "";
 for(int i=0; i<ptb.size(); ++i){
    if(i != 0 && i%nb == 0){
        blocks.push_back(stoll(bm));
        bm = "";
    }
    bm += ptb[i];
 }
 if(bm != ""){
    for(int i=0; i<nb-(bm.size()/2); ++i){
        bm += "26";
    }
    blocks.push_back(stoll(bm));
 }
 cout << "unencrypted_block: ";
 for(ll data : blocks){cout << data << " ";}
 cout << endl;
 vector<ll> cblocks;
 for(ll ptb : blocks){
    cblocks.push_back(power(ptb, e) % m);
 }
 cout << "encrypted_block: ";
 for(ll data : cblocks){cout << data << " ";}
 return 0;
}
ll power(ll v, ll e){
    ll v1 = v;
    v = 1;
    while(e--){
        v *= v1;
    }
    return v;
}
string tlc(string v){
    map<char, char> lc =   {{'a', 'A'},
                            {'b', 'B'},
                            {'c', 'C'},
                            {'d', 'D'},
                            {'e', 'E'},
                            {'f', 'F'},
                            {'g', 'G'},
                            {'h', 'H'},
                            {'i', 'I'},
                            {'j', 'J'},
                            {'k', 'K'},
                            {'l', 'L'},
                            {'m', 'M'},
                            {'n', 'N'},
                            {'o', 'O'},
                            {'p', 'P'},
                            {'q', 'Q'},
                            {'r', 'R'},
                            {'s', 'S'},
                            {'t', 'T'},
                            {'u', 'U'},
                            {'v', 'V'},
                            {'w', 'W'},
                            {'x', 'X'},
                            {'y', 'Y'},
                            {'z', 'Z'},
                            {'A', 'A'},
                            {'B', 'B'},
                            {'C', 'C'},
                            {'D', 'D'},
                            {'E', 'E'},
                            {'F', 'F'},
                            {'G', 'G'},
                            {'H', 'H'},
                            {'I', 'I'},
                            {'J', 'J'},
                            {'K', 'K'},
                            {'L', 'L'},
                            {'M', 'M'},
                            {'N', 'N'},
                            {'O', 'O'},
                            {'P', 'P'},
                            {'Q', 'Q'},
                            {'R', 'R'},
                            {'S', 'S'},
                            {'T', 'T'},
                            {'U', 'U'},
                            {'V', 'V'},
                            {'W', 'W'},
                            {'X', 'X'},
                            {'Y', 'Y'},
                            {'Z', 'Z'}};
    string v1 = "";
    for(char v2 : v){
        v1 += lc[v2];
    }
    return v1;
}
vector<string> ne(string v){
    map<char, string> al = {{'A', "01"}, 
                            {'B', "02"},
                            {'C', "03"},
                            {'D', "04"},
                            {'E', "05"},
                            {'F', "06"},
                            {'G', "07"},
                            {'H', "08"},
                            {'I', "09"},
                            {'J', "10"},
                            {'K', "11"},
                            {'L', "12"},
                            {'M', "13"},
                            {'N', "14"},
                            {'O', "15"},
                            {'P', "16"},
                            {'Q', "17"},
                            {'R', "18"},
                            {'S', "19"},
                            {'T', "20"},
                            {'U', "21"},
                            {'V', "22"},
                            {'W', "23"},
                            {'X', "24"},
                            {'Y', "25"},
                            {'Z', "26"}};
    vector<string> v1;
    for(char v2 : v){
        v1.push_back(al[v2]);
    }
    return v1;
}
ll gcd(ll a, ll b){
 ll g = 1;
 a > b ? g = b, b = a, a = g : 0;
 for(ll i=1; i<a+1; ++i){
  ((a % i) + (b % i)) == 0 ? g = i : 0;
 }
 return g;
}
