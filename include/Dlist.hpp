#ifndef DLIST_HPP
#define DLIST_HPP

#include "Stack.hpp"
#include "Node.hpp"

#include <iostream>
using namespace std;



class dlist
{
private:
	Node *head;
	Node *tail;
	int konum;
	int dugumsayisi;
public:
	dlist()
	{
		head = tail = nullptr;
	}
	~dlist()
	{
		destroy();
	}

	void push_back(int shares)
	{
		Node *node = new Node(shares);
		if (head == NULL)//hiç eleman yoksa
		{
			head = tail = node;
		}
		else
		{
			head->next = node;
			node->prev = tail;
			tail = node;
			head->prev = tail;
			tail->next = head;
		}

		cout << endl;

	}

	void display(int numara)
	{
		Node  *walk = head;//baş düğümü gösteren gezici düğüm oluşturduk.

		dugumsayisi=numara;

		if (head == tail && head == NULL)
		{
			cout << "liste bos."; return;
		}

		for (int i = 0; i < dugumsayisi - 1; i++)//tek tek verileri gösterdik ve gezicimizi ilerlettik.
		{
			cout << walk->shares;
			cout << setw(15); walk->display(); cout << endl;

			walk = walk->next;
		}
		cout << walk->shares; cout << setw(15);
		walk->display();
		cout << endl;

	}

	void konumdan_goster(int k) {// istenen herhangi bir düğümün verisini ve stackindeki veriyi gösterdik.
		int counter = 0;
		Node *walk = head;
		konum = k;
		
		while (konum != counter)
		{
			counter++;
			walk = walk->next;
		}
		cout << walk->shares << "  :" ;
		walk->displayi();
	}

	void EnBuyukElemanCikar()
	{
		////head=pBas;
		int max=0;
		Node* walk=head;
		Node* temp=head;

		for(int i=0;i<6;i++)
		{
			if(max< walk->shares)
			{
				temp=walk;
				max=walk->shares;
			}
			walk=walk->next;
		}
		cout<<max;

	}

	void sola_hareket() {//baş ve sondaki verileri geçici bir değişkende tutup verileri sola kaydırdık. bu sayede veriler kaybolmadı.

		Node *walk = tail->prev;

		int temp = head->shares;
		int temp1 = tail->shares;

		walk->next->shares = temp;
		walk->next->kay(temp);

		while (walk->prev != tail)
		{
			int temp2 = walk->shares;
			walk->shares = temp1;
			walk->kay(temp1);
			temp1 = temp2;
			walk = walk->prev;

		}
		walk->kay(temp1);
		walk->shares = temp1;

		
	}

	void saga_hareket() {
		Node *walk = head->next;

		int temp = head->shares;
		int temp1 = tail->shares;
	
		walk->prev->shares = temp1;
		walk->prev->kay(temp1);
		

		while (walk->next != head)
		{
			int temp2 = walk -> shares;
			walk->shares = temp;
			walk->kay(temp);
			temp = temp2;
			walk = walk->next;
		}
		walk->kay(temp);
		walk->shares = temp;

	}

	void destroy()//heap te oluşturduğumuz verileri silerek çöp oluşmamasını sağladık.
	{


		Node *walk = head;
		Node *prev_1 = NULL;

		if (head == NULL)return;

		Node *node = walk;
		prev_1 = walk;
		walk = walk->next;
		if (walk->next == head && prev_1 == NULL) {
			head = NULL;
			delete node;
		}

		if (walk == head) {
			prev_1 = head->prev;
			head = head->next;
			prev_1->next = head;
			head->prev = prev_1;
			delete node;
		}

		else if (walk->next == head) {
			prev_1->next = head;
			head->prev = prev_1;
			delete node;
		}



		head = tail = nullptr;
	}
};

#endif 