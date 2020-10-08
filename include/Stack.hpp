#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;
#define MAX 100000
class stack
{
private:

	int top;
	int a[MAX];
public:
	stack()
	{
		top = -1;
	}

	void push(int shares)//düğümden aldığımız verileri stackimize ekledik.
	{
		if (top >= (MAX - 1))
		{
			return;
		}
		else
		{
			a[++top] = shares;

		}
	}

	void pop()
	{
		if (top < 0)
		{
			cout << "Stack Underflow";
		}
		else
		{
			a[top--];
		}
	}

	bool isEmpty()
	{
		return (top < 0);
	}

	void display()
	{
		cout << a[top] ;
	}
	
	void displayi()//konumdan veri göstermeyi sağladık.
	{
		while(top!=0)
		{
			cout << setw(5) << a[top--];
		}
	}
	
};



#endif