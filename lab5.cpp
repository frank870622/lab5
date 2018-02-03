#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
class HugeInt;
string add(string, string);
string sub(string, string);
istream& operator>> (istream&, HugeInt&);
ostream& operator<< (ostream&, const HugeInt&);
class HugeInt{
	friend istream& operator>> (istream&, HugeInt&);
	friend ostream& operator<< (ostream&, const HugeInt&);
	public:
		HugeInt(){}
		HugeInt(int);
		HugeInt(string);
		string getNum();
		void setNum(string);
		
		HugeInt operator+ (HugeInt);
		HugeInt operator- (HugeInt);
		const HugeInt& operator= (const HugeInt&);
	private:
	string num;
};

HugeInt::HugeInt(int newnum){
	string newstring = to_string(newnum);
	reverse(newstring.begin(), newstring.end());
	num = newstring;
	}
HugeInt::HugeInt(string newnum){
	reverse(newnum.begin(), newnum.end());
	num = newnum;
}
string HugeInt::getNum(){
	return num;
}
void HugeInt::setNum(string inputnum){
	num = inputnum;
}
HugeInt HugeInt::operator+ (HugeInt other){
	HugeInt temp;
	temp.setNum(add(getNum(), other.getNum()));
	return temp;
}
HugeInt HugeInt::operator- (HugeInt other){
	HugeInt temp;
	temp.setNum(sub(getNum(), other.getNum()));
	return temp;
}
const HugeInt& HugeInt::operator= (const HugeInt& other){
	this->num = other.num;
	return *this;

}
string add(string a, string b){
	int length = (a.length() > b.length())?a.length():b.length();
	string c = (a.length() > b.length())?a:b;
	for (int i = 0; i < length; ++i){
		if (i >= a.length() || i >= b.length())	break;
		c[i] = a[i] + b[i] - 48;
	}
	for (int i = 0; i < length; ++i){
		if (c[i] > 57){
			c[i] = c[i] - 10;
			if (i != length - 1)	c[i + 1] = c[i + 1] + 1;
			else c = c + "1";
		}
	}
	return c;
}
string sub(string a, string b){
	int negative = (a.length() > b.length())?0:1;
	if(negative == 1){
		string temp = b;
		b = a;
		a = temp;
	}
	int length = (a.length() > b.length())?a.length():b.length();
	string c = (a.length() > b.length())?a:b;
	for (int i = 0; i < length; ++i){
		if (i >= a.length() || i >= b.length())	break;
		c[i] = a[i] - b[i] + 48;
	}
	for (int i = 0; i < length; ++i){
		if (c[i] < 48){
			c[i] = c[i] + 10;
			if(i != length - 1)	c[i + 1] = c[i + 1] - 1;
			else c = c + "-";
		}
	}
	if(negative == 1) c = c + "-";
	return c;
}

istream& operator>> (istream &in, HugeInt &output){
	string temp;
	in >> temp;
	reverse(temp.begin(), temp.end());
	output.setNum(temp);
	return in;
}
ostream& operator<< (ostream &out, const HugeInt &input){
	string temp = input.num;
	reverse(temp.begin(), temp.end());
	out << temp;
	return out;
}

int main(){
	HugeInt x;
	HugeInt y(28825252);
	HugeInt z("314159265358979323846");
	HugeInt result;

	cin >> x;
	result = x + y;
	cout << x << "+" << y << "=" << result << endl;


	result = z - x;
	cout << result << endl;


	return 0;
}

