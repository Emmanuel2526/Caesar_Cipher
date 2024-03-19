#include <iostream>
#include <string>
using namespace std;
long long ll_input(string s){
    bool g = false;
    long long v;
    while(!g){
        cout << s << " ";
        try{
            cin >> v;
            g = true;
        }
        catch(...){
            cout << "\nInvalid Input, Try Again.\n";
            // Clear input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return v;
}
long long phi(long long p, long long q){
  return (p-1)*(q-1);
}
long long gcd(long long a, long long b){
	long long g;
	if(a > b){
		g = a;
		a = b;
		b = g;
	}
	for(long long i=1; i<a+1; ++i){
		if(a % i == 0 && b % i == 0){
			g = i;
		}
	}
	return g;
}