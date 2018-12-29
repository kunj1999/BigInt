#include <iostream>
#include "BigInt.h"
#include <string>
#include <math.h>
#include "tests.h"
using namespace std;

void reverse_string(string& obj);


int main()
{
	/*
	BigInt a;
	BigInt b;

	a = BigInt("-99");
	b = BigInt("40");
 	cout<<a<<" / "<<b<<endl<< (a % b)<<endl;
	return 0;
	*/
	cout << (100<100) << endl;
	BigInt a;
	BigInt b;

	a = BigInt("-123456789012345678901234567890");
	b = BigInt("0");
 	cout<<a<<" * "<<b<<endl<< (a * b)<<endl;

	BigInt x;
	BigInt y;


	x = BigInt();
	cout << x << endl;
	x = BigInt(-100);
	cout << x << endl;
	x = BigInt("1231231231231231231");
	cout << x << endl;
	//x = BigInt(" )4456615");
	//cout << x << endl;
	x = BigInt("-123456789012345678901234567899");
	cout << x << endl;

	y = BigInt("1");
		
	//cout << (x / y) << endl;
	

	y = BigInt("1");
	x = BigInt("299999999999999999999");

	cout << x + y << endl;

	y = BigInt("111111111111111111");
	x = BigInt("111111111111111111");

	cout << x + y << endl;

	x = BigInt(1000);
	y = BigInt(1);

	cout << "Subtraction" << endl;
	cout << x - y << endl;

	x = BigInt(4);
	y = BigInt(-5);

	cout << x - y << endl;

	cout << "testing loop" << endl;
	for (int i = -10; i < 10; i++) {
		for (int j = -10; j < 10; j++) {
			x = BigInt(i);
			y = BigInt(j);
			//cout << x << " " << y << endl;
			cout << i << "+" << j << "=   " << x + y << ":" << i + j << endl;
		}
	}

	x = BigInt(100);
	y = BigInt(-100);
	cout << "CHECKING THE WEIRD CASE " << x + y << endl;


	x = BigInt(-100);
	cout << "THIS SHOULD BE -100: " << x << endl;

	cout << "TESTING DR.ADAM'S CODE WHEN TESTING GLEN" << endl;

	if (test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "You win so far..." << endl;
	}
	else
	{
		cout << "MUAHHAHAHAHAHHAHAH" << endl;
	}

	if (test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred_with_string_constructor())
	{
		cout << "You win so far..." << endl;
	}
	else
	{
		cout << "MUAHHAHAHAHAHHAHAH" << endl;
	}

	if (test_carry_over_40_digits())
	{
		cout << "Glen rules" << endl;
	}
	else
	{
		cout << "You are feeble" << endl;
	}
	if (test_for_negative_zero())
	{
		cout << "woo" << endl;
	}
	else
	{
		cout << "boo" << endl;
	}
	cout << "DOING MY TESTS" << endl;
	if (test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Win Sub Test" << endl;
	}
	else
	{
		cout << "Failed Sub Test" << endl;
	}

	if (test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred_with_string_constructor())
	{
		cout << "Win Sub Test 2" << endl;
	}
	else
	{
		cout << "Failed Sub Test 2" << endl;
	}
	if (test_all_pairs_less_than_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Win Less than Test" << endl;
	}
	else
	{
		cout << "Fail Less than Test" << endl;
	}
	if (test_all_pairs_greater_than_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Win Greater than Test" << endl;
	}
	else
	{
		cout << "Fail greater than Test" << endl;
	}
	if (test_all_pairs_multiply_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Win Multiply Test" << endl;
	}
	else
	{
		cout << "Fail Multiply Test" << endl;
	}
	if (test_all_pairs_equality_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Passed Equality Test" << endl;
	}
	else
	{
		cout << "Fail Equality Test" << endl;
	}
	if(test_all_pairs_divide_than_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "divide passed" << endl;
	}
	else
	{
		cout << "divide failed" << endl;
	}
	if(test_all_pairs_modulo_than_negative_one_hundred_to_positive_one_hundred())
	{
		cout << "Modulo passed" << endl;
	}
	else
	{
		cout << "Modulo failed" << endl;
	}
}

BigInt::BigInt()
{
	data = "0";
	isNegative = false;
}

BigInt::BigInt(int x)
{							
	if(x < 0)
		isNegative = true;								//Check if the integer is negative
	else
		isNegative = false;
	x = abs(x);											//Does absolute value on the integer
	data = to_string(x);								//Turn integer to string using "to_string" function
}

BigInt::BigInt(string x)
{
	int size = x.size();
	int i = 0;

	while(x[i] == ' ' || (x[i] != '+' && x[i] != '-' && !isdigit(x[i])))		//Check the precessing space characters
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

	while(isdigit(x[i]) && i < size)					//Take each character and assemble the BigInt object
	{
		data.push_back(x[i]);
		i++;
	}
	if(data.size() == 1 && data[0] == '0')
		isNegative = false;
}

void reverse_string(string& obj)						//Reverses the string
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



BigInt BigInt::operator+(BigInt& right)				//Does integer addition on the BigInt objects
{
	string temp_string = "";
	BigInt retVal;
	char c;
	int sum, carry = 0, i = 0, size;
	int li = this->data.size() - 1;
	int ri = right.data.size() - 1;

	if(this->isNegative == right.isNegative)		//Does a normal addition if the both objects are negative or positive
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
		if(this->isNegative && right.isNegative)
			retVal.isNegative = true;
		retVal.isNegative = this->isNegative;
	}
	else if(this->isNegative)						//If the left hand side is negative, call the subtraction function
	{
		this->isNegative = false;
		retVal = right - *this;						//When calling subtraction function, swap the objects
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

	if(right.isNegative)							//If the right hand sied is negative, then change it to positive and call the oveloade+
	{
		right.isNegative = false;
		retVal = *this + right;
		right.isNegative = true;
		return retVal;
	}
	if(this->isNegative == right.isNegative)		//Do normal subtraction if both are positive
	{
		if(right < *this)
		{
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
		}
		else										//If the left Handside is smalled than right then do right - left
		{
			retVal = right - *this;
			retVal.isNegative = true;				//Manually assign negative sign
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
	else if(this->isNegative)						//If left handside is negative, change right handside to negative and call overload+
	{
		right.isNegative = true;
		retVal = *this + right;
		right.isNegative = false;
		return retVal;
	}
	else											//If right handside is negative, change right handside to positive and call overload+
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

	if(this->isNegative && !right.isNegative)		//if(-left < right) return true;
	{
		return 1;
	}
	else if(right.isNegative && !this->isNegative)	//if(left < -right) return false;
 	{
		return 0;
	}
	
	if(!this->isNegative && !right.isNegative)		//Check if both are negative values
	{
		if(this->data.size() == right.data.size())	//Check if the size of the data are the same
		{
			while(i < right.data.size())			//Compare each character starting from the left
			{
				left_int = static_cast<int> (this->data[i] - 48);
				right_int = static_cast<int> (right.data[i] - 48);
				if(left_int < right_int)
					return 1;
				else if(left_int > right_int)
					return 0;
				i++;
			}
			if(left_int == right_int)
			return -1;
		}
		else
			return (this->data.size() < right.data.size());		//Return true or false based on the size of the data
	}
	else
	{
		if(this->data.size() == right.data.size())
		{
			while(i < right.data.size())
			{
				left_int = static_cast<int> (this->data[i] - 48);
				right_int = static_cast<int> (right.data[i] - 48);
				if(left_int > right_int)
					return 1;
				else if(left_int < right_int)
					return 0;
				i++;
			}
			if(left_int == right_int)
			return -1;
		}
		else
			return (this->data.size() > right.data.size());
	}
	return -11111;
}

int BigInt::operator>(BigInt& right)				//Similar algorith to that of overload<
{
	int left_int = -1;
	int right_int = 0;
	int i = 0;

	if(this->isNegative && !right.isNegative)
	{
		return 0;
	}
	else if(right.isNegative && !this->isNegative)
	{
		return 1;
	}

	if(!this->isNegative && !right.isNegative)
	{
		if(this->data.size() == right.data.size())
		{
			while(i < right.data.size())
			{
				left_int = static_cast<int> (this->data[i] - 48);
				right_int  = static_cast<int> (right.data[i] - 48);
				if(left_int > right_int)
					return 1;
				else if (left_int < right_int)
					return 0;
				i++;
			}
			if(left_int == right_int)
			{
				return -1;
			}
		}
		else
		{
			return (this->data.size() > right.data.size());
		}
	}
	else
	{
		if(this->data.size() == right.data.size())
		{
			while(i < right.data.size())
			{
				left_int = static_cast<int> (this->data[i] - 48);
				right_int  = static_cast<int> (right.data[i] - 48);
				if(left_int > right_int)
					return 0;
				else if (left_int < right_int)
					return 1;
				i++;
			}
			if(left_int == right_int)
			{
				return -1;
			}
		}
		else
		{
			return (this->data.size() < right.data.size());
		}
	}
	return -1111111;
}

int BigInt::operator==(BigInt& right)
{
	if((*this > right) == -1)							//If the the overloaded greater than return -1, then objects are equal to each other
	{
		return 1;
	}
	else 
		return 0;
}

BigInt BigInt::operator*(BigInt& right)
{
	
	int carry;
	int mult;
	int ph = 0;
	int li, ri;
	string temp_string;
	BigInt retVal = BigInt(0); 
	BigInt temp_val;

	if(right < *this)									//Check which object is the smallest for time optimization.
	{
		ri = right.data.size() - 1;
		while(ri >= 0)									//Do multiplication one letter at a time
		{
			li = this->data.size() - 1;
			for(int i = 0; i < ph; i++)
				{
					temp_string.push_back('0');
				}
			carry = 0;
			while(li >= 0)
			{
				mult = static_cast<int>(this->data[li] - 48) * static_cast<int>(right.data[ri] - 48) + carry;
				carry = mult/10;
				mult %= 10;
				temp_string.push_back(static_cast<char>(mult + 48));
				li--;
			}
			if(carry)
				temp_string.push_back(static_cast<char>(carry + 48));
			reverse_string(temp_string);
			temp_val = BigInt(temp_string);
			retVal = retVal + temp_val;
			temp_string.clear();
			ri--;
			ph++;
		}
	}
	else
	{
		return (right * *this);
	}
	trim(retVal);
	if(retVal.data[0] != '0')							//Manually assign the negative sign to returning object
	{
		if(this->isNegative == right.isNegative)
			retVal.isNegative = false;
		else 
			retVal.isNegative = true;
	}
	return retVal;
}

BigInt BigInt::operator/(BigInt& right)
{
	BigInt retVal(0);
	BigInt temp_val(1);
	BigInt sub;

	if(this->isNegative && right.isNegative)			//Check if the both objects are negative
	{
		this->isNegative = false;						//If they are then change them to positive and call the overload/ with modified negative sign
		right.isNegative = false;
		retVal = *this/right;
		return retVal;
	}
	else if(this->isNegative || right.isNegative)
	{
		if(this->isNegative)							//If only left or right is negative, then change it to positve and call the overload/
		{
			this->isNegative = false;
			retVal = *this/right;
			this->isNegative = true; 
		}
		else
		{
			right.isNegative = false;
			retVal = *this/right;
			right.isNegative = true;
		}
		if(retVal.data[0] != '0')
			retVal.isNegative = true;
		return retVal;
	}
	if(right.data[0] == '0' && right.data.size() == 1)	//Checks if right handside is 0, in which case it's illegal
	{
		cout << "Cannot divide by Zero!" << endl;
		cout << "Exiting... ";
		exit(1);
	}

	sub = *this-right;									//Call the subtraction overloaded to see how many time right handside subtracts left handside
	while(!sub.isNegative)
	{
		retVal = retVal + temp_val;
		sub = sub-right;

	}
	trim(retVal);
	return retVal;
}
BigInt BigInt::operator%(BigInt& right)					//similar algorith as the overload/, but insted return the carry object.
{
	BigInt retVal;
	BigInt sub;

	if(this->isNegative && right.isNegative)
	{
		this->isNegative = false;
		right.isNegative = false;
		retVal = *this%right;
		if(retVal.data[0] != '0')
				retVal.isNegative = true;
		return retVal;
	}
	else if(this->isNegative || right.isNegative)
	{
		if(this->isNegative)
		{
			this->isNegative = false;
			retVal = *this%right;
			this->isNegative = true;
			if(retVal.data[0] != '0')
				retVal.isNegative = true;
			return retVal;
		}
		else
		{
			right.isNegative = false;
			retVal = *this%right;
			right.isNegative = true;
			return retVal;
		}
	}
	if(right.data[0] == '0' && right.data.size() == 1)
	{
		cout << "Cannot divide by Zero!" << endl;
		cout << "Exiting... " << endl;
		exit(1);
	}

	sub = *this-right;
	if(sub.isNegative)
	{
		retVal = *this;
		return retVal;
	}

	while(!sub.isNegative)
	{
		retVal = sub;
		sub = sub - right;
	}
	trim(retVal);
	return retVal;
}

void BigInt::borrow_previous(BigInt& obj, int iterator)		//Reduces the value of the previous character by one and stores it back
{															//Used for subtraction
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

void BigInt::trim(BigInt& obj)								//Gets rid of leading zero in the data
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

ostream& operator<< (ostream& out, const BigInt& right)		//Prints out the BigInt object
{
	if(right.isNegative)
	{
		out << '-';
	}
	out << right.data;
	return out;
}
