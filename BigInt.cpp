#include <iostream>
#include "BigInt.h"
#include <cstring>

using namespace std;

int main()
{
	BigInt x;
	cout << x << endl;
	x = BigInt(42);
	cout << x << endl;
	return 0;
}

BigInt::BigInt()
{
	data = "0";
	isNegative = false;
}

BigInt::BigInt(int x)
{
	data = to_string(x);
	if(x < 0)
		isNegative = true;
	else
		isNegative = false;
}

ostream& operator<< (ostream& out, const BigInt& right)
{
	out << right.data;
	return out;
}