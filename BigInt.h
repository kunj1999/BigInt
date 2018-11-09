#ifndef BIGINT_H
#define BIGINT_H 

using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(int x);
	explicit BigInt(string x);

friend ostream& operator<< (ostream& out, const BigInt& right);

private:
	string data;
	bool isNegative;
};

#endif