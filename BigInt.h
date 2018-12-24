#ifndef BIGINT_H
#define BIGINT_H 

using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(int x);
	explicit BigInt(string x);
	BigInt operator+(const BigInt left, const BigInt right);

friend ostream& operator<< (ostream& out, const BigInt& right);

private:
	string data;
	bool isNegative;
};

#endif