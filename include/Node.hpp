#ifndef NODE_HPP
#define NODE_HPP

#include "Stack.hpp"

class Node
{

public:
	Node *prev;
	Node *next;
	int shares;//verileri gösteren değişken

	stack *s = new stack();

	Node(int vshares)
	{
		prev = next = nullptr;
		shares = vshares;

		s->push(shares);
		
	}
	
	/*~Node(){
	delete [] s;

	}*/

	void kay(int vshares) {//sağa sola kaydırmayı listeden gelen bir önceki ya da sonraki verileri stackimizi ekledik.
		shares = vshares;
		s->push(shares);
	}

	void display()
	{
		s->display();
	}
	
	void displayi()//düğümdeki stack değerlerini çağırarak konumdan veri göstermeyi sağladık. 
	{

		s->displayi();
		
	}

};

#endif