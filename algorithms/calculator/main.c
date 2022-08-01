#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int calculate(const char* str);
int operations_quantity(const char* str);
int to_int(const char val);

char* expression(char* str);
char* simple_expression(const char* str);
char* take_expression(char* str, size_t* ifrom, size_t* ito);
char* to_str(const int val);

void place_expression(char* str, const char* fragment, const size_t ifrom, const size_t ito);

enum operation { plus, minus, multiply, divide };

// 2 + 2*2 + 3*3
// 2 + 4 + 3*3
// 2 + 4 + 9

// 6 + 9
// 15

int main(void)
{
	char A[20];
	printf("%d\n", strlen(A));

	return 0;
}

int calculate(const char* str)
{
	return atoi(expression(str));
}

int operations_quantity(const char* str)
{
	int quantity = 0;
	bool is_bracket_opened = false;
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		bool is_bracket_opened = false;
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			quantity++;
		else if (str[i] == '(' && is_bracket_opened == false)
			is_bracket_opened = true;
		else if(str[i] == ')' && )
	}
	return 1;
}

int to_int(const char val)
{
	return val - 48;
}

char* expression(char* str)
{
	int quantity = operations_quantity(str); //

	//if (quantity > 1)
	//{
		while (quantity > 1)
		{
			size_t ifrom = 0, ito = 0;
			place_expression(str, expression(take_expression(str, &ifrom, &ito)), ifrom, ito); // //
			quantity = operations_quantity(str);
		}
		return simple_expression(str); //
	//}
	if (quantity == 1)
		return simple_expression(str); //
	if (quantity == 0)
		return str;
}

char* simple_expression(const char* str)
{
	int first = 0, second = 0;
	enum operation op = plus;

	size_t i;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+') { i++; op = plus; break; }
		else if (str[i] == '-') { i++; op = minus; break; }
		else if (str[i] == '*') { i++; op = multiply; break; }
		else if (str[i] == '/') { i++; op = divide; break; }
		//else if (str[i] == ' ') { continue; }
		else
			first = first * 10 + to_int(str[i]);
	}

	for ( ; str[i] != '\0'; i++)
	{
		second = second * 10 + to_int(str[i]);
	}

	switch (op)
	{
	case plus:     { return to_str(first + second); }
	case minus:    { return to_str(first - second); }
	case multiply: { return to_str(first * second); }
	case divide:   { return to_str(first / second); }
	default: return 0;
	}
}

char* take_expression(char* str, size_t* ifrom, size_t* ito)
{
	return "";
}

char* to_str(const int val) 
{
	int val_copy = val;
	size_t n = 0;

	while (val_copy != 0) // finding lenght of 'val' (number 1234 has lenght 4, 12 has lenght 2, etc.)
	{
		n++;
		val_copy /= 10;
	}

	char* result = (char*)malloc(n * sizeof(char));
	val_copy = val;

	size_t i;

	if (val < 0)
	{
		result[0] = '-';
		i = n;
	}
	else 
		i = n - 1;

	while(val_copy != 0)
	{
		result[i--] = val_copy % 10 + 48;
		val_copy /= 10;
	}
	result[n] = '\0';
	
	return result;
}

void place_expression(char* str, const char* fragment, const size_t ifrom, const size_t ito)
{

}
