#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;
string int2str(int &i){
	string r;
	stringstream rr(r);
	rr << i;
	//cout << rr.str() << endl;
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
		a[i] = (int)num[l-i-1] -48;
		}
	}
	hugeint operator+(hugeint &other);
	hugeint operator=(hugeint other);
	hugeint operator-(hugeint &other);
	void function(int);
//private:
	string k;
	int l;
	int a[100];
	void init();
	void intarray(int);
};
void hugeint::function(int r){
	init();
	k = int2str(r);
	l = k.size();
        for(int i=0;i<l;i++){
                a[i] = (int)k[l-i-1] -48;
        }
}
void hugeint::init(){
	for(int i=0;i<100;i++)	{
		a[i] = 0;
	}
}
hugeint hugeint::operator+(hugeint &other){
	hugeint *temp;
	temp  = new hugeint;
	for(int i = 0;i <100;i++){
		temp->a[i] = a[i] + other.a[i];
	}
	for(int i=0;i<99;i++){
		if(temp->a[i] >= 10){
		temp->a[i+1] = temp->a[i+1] + 1;
		temp->a[i] = temp->a[i] -10;
		}
	}
	return *temp;
}
hugeint hugeint::operator=(hugeint other){
	for(int i=0;i<100;i++){
	a[i] = other.a[i];
	}
	return *this;
}
hugeint hugeint::operator-(hugeint &other){
	hugeint *temp;
	temp = new hugeint;
	for(int i=0;i<100;i++){
		temp->a[i] = a[i] - other.a[i];
	}
	for(int i=0;i<99;i++){
		if(temp->a[i] < 0){
			if(temp->a[i+1] > 0){
				temp->a[i] += 10;
				temp->a[i+1] -= 1;
			}
		}
	}
	return *temp;
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
	return out;
}
istream & operator>> (istream &in, hugeint &n){
	int s;
	in >> s;
	n.function(s);
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
	
	result = z - x;
	cout << result << endl;	
	return 0;
}
