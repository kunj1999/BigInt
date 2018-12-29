#ifndef BIGINT_H
#define BIGINT_H 

using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(int x);
	BigInt operator+(BigInt& right);
	BigInt operator-(BigInt& right);
	BigInt operator*(BigInt& right);
	BigInt operator/(BigInt& right);
	BigInt operator%(BigInt& right);
	int operator<(BigInt& right);
	int operator>(BigInt& right);
	int operator==(BigInt& right);
	void borrow_previous(BigInt& obj, int iterator);
	void trim(BigInt& obj);
	explicit BigInt(string x);
	

friend ostream& operator<< (ostream& out, const BigInt& right);

private:
	string data;
	bool isNegative;
};

#endif