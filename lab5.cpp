#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
string int2str(int &i){
	string r;
	stringstream rr(r);
	rr << i;
	return rr.str();
}
class hugeint{
	friend ostream & operator<< (ostream &, const hugeint &);
	friend istream & operator>> (istream &,  hugeint &);
public:
	hugeint(){
		init();	
	}
	hugeint(int number){
		init();
		k = int2str(number);
		l = k.size();
		for(int i=0;i<l;i++){
		a[i] = (int)k[l-i-1] -48;
		}
	}
	hugeint(string num){
		init();
		l = num.size();
		k = num;
		for(int i=0;i<l;i++){
		a[i] = num[l-i];
		}
	}
	hugeint operator+(hugeint &other);
	hugeint operator=(hugeint other);
//private:
	string k;
	int l;
	int a[100];
	void init();
	void intarray(int);
};
void hugeint::init(){
	for(int i=0;i<100;i++)	{
		a[i] = 0;
	}
}
hugeint hugeint::operator+(hugeint &other){
	for(int i = 0;i <100;i++){
		a[i] = a[i] + other.a[i];
	}
	for(int i=0;i<99;i++){
		if(a[i] >= 10){
		a[i+1] = a[i+1] + 1;
		a[i] = a[i] -10;
		}
	}
	return *this;
}
hugeint hugeint::operator=(hugeint other){
	return other;
}	
ostream & operator<< (ostream &out,const hugeint &n){
	int q=0;
	for(int i=99;i>=0;i--){
		if(n.a[i] != 0){
			q = i;
			break;
		}
	}
	for(int i=q;i>=0;i--){
		out << n.a[i];	
	}
	out << endl;
	return out;
}
istream & operator>> (istream &in, hugeint &n){
	int s;
	in >> s;
	hugeint o(s);
	for(int i=0;i<100;i++){
		n.a[i] = o.a[i];	
	}
	n.l = o.l;
	/*n.k = int2str(s);
	n.l = n.k.size();
        for(int i=0;i<n.l;i++){
        	n.a[i] = (int)n.k[n.l-i-1] -48;
        }*/
	return in;
}
int main(){
	hugeint x;
	hugeint y(28825252);
	hugeint z("314159265358979323846");
	hugeint result;
	
	cin >> x;
	result = x+y;
	cout << x << "+" << y << "=" << result << endl;
	
	return 0;
}
