#include <iostream>
#include "BigInt.h"
#include <string>

using namespace std;

void reverse_string(string& obj);


int main()
{
	BigInt a;
	BigInt b;

	a = BigInt("1");
 	b = BigInt(1000);
 	cout<<a<<" - "<<b<<endl<< (a - b)<<endl;
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
}

void reverse_string(string& obj)
{
	string temp;
	int i = obj.size() - 1;
	while(i >= 0)
	{
		temp.push_back(obj[i]);
		i--;
	}
	obj = temp;
}

BigInt BigInt::operator+(BigInt& right)
{
	string temp_string = "";
	BigInt retVal;
	char c;
	int sum, carry = 0, i = 0, size;
	int li = this->data.size() - 1;
	int ri = right.data.size() - 1;

	if(this->isNegative == right.isNegative)
	{
		while(li >= 0 && ri >= 0)
		{
			sum = static_cast<int> (this->data[li] - 48) + static_cast<int> (right.data[ri] - 48) + carry;
			carry = sum/10;
			sum %= 10;
			c = static_cast<char> (sum + 48);
			temp_string.push_back(c);
			li--;
			ri--;
		}
		if(li >= 0)
		{
			while(li >= 0)
			{
				sum = static_cast<int> (this->data[li] - 48) + carry;
				carry = sum/10;
				sum %= 10;
				c = static_cast<char> (sum + 48);
				temp_string.push_back(c);
				li--;
			}
		}
		else
		{
			while(ri >= 0)
			{
				sum = static_cast<int> (right.data[ri] - 48) + carry;
				carry = sum/10;
				sum %= 10;
				c = static_cast<char> (sum + 48);
				temp_string.push_back(c);
				ri--;
			}
		}
		if(carry)
		{
			c = static_cast<char> (carry + 48);
			temp_string.push_back(c);
		}
		reverse_string(temp_string);
		retVal = BigInt(temp_string);
		retVal.isNegative = this->isNegative;
	}
	else if(this->isNegative)
	{
		this->isNegative = false;
		retVal = right - *this;
		this->isNegative = true;
		return retVal;
	}
	else
	{
		right.isNegative = false;
		retVal = *this - right;
		right.isNegative = true;
		return retVal;
	}
	return retVal;
}

BigInt BigInt::operator-(BigInt& right)
{
	int li, ri, borrow;
	int sub = 0;
	char c;
	BigInt retVal;
	string temp_string;

	li = this->data.size() - 1;
	ri = right.data.size() - 1 ;

	if(this->isNegative == right.isNegative)
	{
		if(right < *this)
			while(li >= 0 && ri >= 0)
			{
				sub = static_cast<int> (this->data[li] - 48) - static_cast<int> (right.data[ri] - 48);
				if(sub < 0)
				{
					borrow_previous(*this, li-1);
					sub = static_cast<int> (this->data[li] - 48) - static_cast<int> (right.data[ri] - 48) + 10;
				}
				c = static_cast<char>(sub + 48);
				temp_string.push_back(c);
				li--;
				ri--;
			}
		else
		{
			retVal = right - *this;
			retVal.isNegative = true;
			trim(retVal);
			return retVal;
		}
		while(li >= 0)
		{
			sub = static_cast<int> (this->data[li] - 48);
			c = static_cast<char> (sub + 48);
			temp_string.push_back(c);
			li--;
		}
		while(ri >= 0)
		{
			sub = static_cast<int> (right.data[ri]);
			c = static_cast<char> (sub + 48);
			temp_string.push_back(c);
			ri--;
		}
		reverse_string(temp_string);
		retVal = BigInt(temp_string);
	}
	else if(this->isNegative)
	{
		right.isNegative = true;
		retVal = *this + right;
		right.isNegative = false;
		return retVal;
	}
	else
	{
		right.isNegative = false;
		retVal = *this + right;
		right.isNegative = true;
		return retVal;
	}
	trim(retVal);
	return retVal;
}

int BigInt::operator<(BigInt& right)
{
	int left_int = -1;
	int right_int = 0;
	int i = 0;

	if(this->isNegative && !right.isNegative)
	{
		return 1;
	}
	else if(right.isNegative && !this->isNegative)
	{
		return 0;
	}
	
	if(this->isNegative == right.isNegative)
	{
		if(this->data.size() == right.data.size())
		{
			while(i < right.data.size())
			{
				left_int = static_cast<int> (this->data[i] - 48);
				right_int = static_cast<int> (right.data[i] - 48);
				if(left_int < right_int)
					return 1;
				else if(left_int > right_int)
					return 0;
				i++;
			}
		}
		if(left_int == right_int)
			return -1;
		else
			return (this->data.size() < right.data.size());
	}
	return -11111;
}
void BigInt::borrow_previous(BigInt& obj, int iterator)
{
	int b;
	char c;
	b = static_cast<int> (obj.data[iterator] - 48);
	if(b <= 0)
	{
		b = 9;
		c = static_cast<char> (b + 48);
		obj.data[iterator] = c;
		return borrow_previous(obj, iterator - 1);
	}
	b--;
	c = static_cast<char> (b + 48);
	obj.data[iterator] = c;
}

void BigInt::trim(BigInt& obj)
{
	int size;
	string str = obj.data;
	reverse_string(str);
	size = str.size() - 1;
	while(str[size] == '0' && size > 0)
	{
		str.pop_back();
		size--;
	}
	reverse_string(str);
	obj.data = str;
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