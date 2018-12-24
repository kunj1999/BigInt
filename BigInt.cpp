#include <iostream>
#include "BigInt.h"
#include <string>

using namespace std;

int main()
{
	BigInt x;
	cout << x << endl;
 	x = BigInt(42);
 	cout << x << endl;
 	x = BigInt(" -123456789012345678901234567890 and more stuff");
 	cout << x << endl;
 	x = BigInt("+-4848484848484848");
	return 0;
}

BigInt::BigInt()
{
	data = "0";
	isNegative = false;
}

BigInt::BigInt(int x)
{
	data = to_string(x);								//Turn integer into string using built in to_string function
	if(x < 0)
		isNegative = true;								//Check if the integer is negative
	else
		isNegative = false;
}

BigInt::BigInt(string x)
{
	int size = x.size();
	int i = 0;

	while(x[i] == ' ')									//Check the precessing space characters
	{
		i++;
	}

	if(x[i] == '+')										//Check for negative or positive number
	{
		isNegative = false;
		i++;
	}
	else if(x[i] == '-')
	{
		isNegative = true;
		i++;
	}
	else
	{
		isNegative = false;
	}

	if(!isdigit(x[i]))									//Check for the valid string
	{
		cout<< "Tried to construct invaild BigInt to string" << endl;
		cout<< x << endl;
		cout<< "exiting..." << endl;
		exit(1);
	}

	while(isdigit(x[i]) && i < size)
	{
		data.push_back(x[i]);
		i++;
	}
	data.push_front(x[i]);
}
ostream& operator<< (ostream& out, const BigInt& right)
{
	if(right.isNegative == true)
	{
		cout << '-';
	}
	out << right.data;
	return out;
}