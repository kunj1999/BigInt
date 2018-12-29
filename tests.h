
//I am not the author of this file, nor have I modified the file.
//This file was provided by Chris Morales


#ifndef TESTS_H
#define TESTS_H

#include "BigInt.h"
#include <iostream>
#include <sstream>

using namespace std;

bool test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred_with_string_constructor();
bool test_carry_over_40_digits();
bool test_for_negative_zero();
bool test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred_with_string_constructor();
bool test_all_pairs_less_than_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_greater_than_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_multiply_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_divide_than_negative_one_hundred_to_positive_one_hundred();
bool test_all_pairs_modulo_than_negative_one_hundred_to_positive_one_hundred();



bool test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(i);
			BigInt bigJ(j);
			//cout << "data: " << bigI << " " << bigJ << endl;

			stringstream int_answer;
			int_answer.str("");
			stringstream big_answer;
			big_answer.str("");

			int_answer << i << "+" << j << "=" << i + j;
			big_answer << bigI << "+" << bigJ << "=" << bigI + bigJ;

			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_addition_negative_one_hundred_to_positive_one_hundred_with_string_constructor()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;


			int_answer << i << "+" << j << "=" << i + j;
			big_answer << bigI << "+" << bigJ << "=" << bigI + bigJ;

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;
			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_carry_over_40_digits()
{
	BigInt a("9999999999999999999999999999999999999999");
	string answer = "10000000000000000000000000000000000000000";
	BigInt b("1");

	stringstream big_answer;
	big_answer << a + b;
	if (answer == big_answer.str())
	{
		return true;
	}
	return false;
}

bool test_for_negative_zero()
{
	BigInt a("-123456789123456789123456789123456789");
	BigInt b("123456789123456789123456789123456789");
	string answer = "0";
	stringstream big_answer;
	big_answer << a + b;
	bool result = true;

	if (answer != big_answer.str())
	{
		result = false;
	}
	big_answer.str("");
	big_answer << b + a;
	if (answer != big_answer.str())
	{
		result = false;
	}

	BigInt c("-0");
	BigInt d("-0");

	big_answer.str("");
	big_answer << c + d;
	if (answer != big_answer.str())
	{
		cout << answer << endl;
		cout << "vs." << endl;
		cout << big_answer.str() << endl;
		result = false;
	}
	big_answer.str("");
	big_answer << d + c;
	if (answer != big_answer.str())
	{
		cout << answer << endl;
		cout << "vs." << endl;
		cout << big_answer.str() << endl;
		result = false;
	}
	return result;

}
bool test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(i);
			BigInt bigJ(j);
			stringstream int_answer;
			stringstream big_answer;
			//cout << "data: " << bigI << " " << bigJ << endl;
			int_answer << i << "-" << j << "=" << i - j;
			big_answer << bigI << "-" << bigJ << "=" << bigI - bigJ;

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;

			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_subtraction_negative_one_hundred_to_positive_one_hundred_with_string_constructor()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;

			int_answer << i << "-" << j << "=" << i - j;
			big_answer << bigI << "-" << bigJ << "=" << bigI - bigJ;

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;
			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_less_than_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;


			int_answer << i << "<" << j << "=" << (i < j);
			big_answer << bigI << "<" << bigJ << "=" << (bigI < bigJ);

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;
			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_greater_than_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;


			int_answer << i << ">" << j << "=" << (i > j);
			big_answer << bigI << ">" << bigJ << "=" << (bigI > bigJ);

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;
			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_divide_than_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			if (j != 0)
			{
				BigInt bigI(to_string(i));
				BigInt bigJ(to_string(j));
				stringstream int_answer;
				stringstream big_answer;


				int_answer << i << "/" << j << "=" << (i / j);
				big_answer << bigI << "/" << bigJ << "=" << (bigI / bigJ);

				//cout << int_answer.str() << endl;
				//cout << big_answer.str() << endl;
				if (int_answer.str() != big_answer.str())
				{
					cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
					return false;
				}
				int_answer.str("");
				big_answer.str("");
			}
		}
	}
	return true;
}


bool test_all_pairs_multiply_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;

			int_answer << i << "*" << j << "=" << (i * j);
			big_answer << bigI << "*" << bigJ << "=" << (bigI * bigJ);

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;

			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_equality_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			BigInt bigI(to_string(i));
			BigInt bigJ(to_string(j));
			stringstream int_answer;
			stringstream big_answer;

			int_answer << i << "==" << j << "=" << (i == j);
			big_answer << bigI << "==" << bigJ << "=" << (bigI == bigJ);

			//cout << int_answer.str() << endl;
			//cout << big_answer.str() << endl;
			if (int_answer.str() != big_answer.str())
			{
				cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
				return false;
			}
			int_answer.str("");
			big_answer.str("");
		}
	}
	return true;
}

bool test_all_pairs_modulo_than_negative_one_hundred_to_positive_one_hundred()
{
	for (int i = -100; i <= 100; i++)
	{
		for (int j = -100; j <= 100; j++)
		{
			if (j != 0)
			{
				BigInt bigI(to_string(i));
				BigInt bigJ(to_string(j));
				stringstream int_answer;
				stringstream big_answer;


				int_answer << i << "%" << j << "=" << (i % j);
				big_answer << bigI << "%" << bigJ << "=" << (bigI % bigJ);

				//cout << int_answer.str() << endl;
				//cout << big_answer.str() << endl;
				if (int_answer.str() != big_answer.str())
				{
					cout << "Everything is deborken when i is " << i << " and j is " << j << endl;
					return false;
				}
				int_answer.str("");
				big_answer.str("");
			}
		}
	}
	return true;
}



#endif