#ifndef NUMBERS_HPP
#define NUMBERS_HPP

#include "Digits.hpp"

class Numbers
{
private:
	Digits *head;
	int size;

	// Local'leri düğüm numaralarını nitelemek için kullanıyorum.
	Digits *FindPrev(int Local)
	{
		int index = 1;
		if(Local < 0 || Local > size) throw "Finding prev is not true";
		else if(Local == 0) throw "Head node has no prev";
		else
		{
			for(Digits *itr = head; itr != NULL; itr = itr->next, index++)
			{
				if(index == Local) return itr;
			}
		}
	}
public:
	Numbers()
	{
		head = NULL;
		size = 0;
	}
	
	int count()
	{
		return size;
	}
	
	bool isEmpty()
	{
		return size == 0;
	}
	
	void remove()
	{
		removeAt(size - 1);
	}
	
	void removeAt(int Local)
	{
		Digits* del;
		if(Local < 0 || Local >= size) throw "RemoveAt is not proper";
		else if(Local == 0)
		{
			del = head;
			head = head->next;
		}
		else
		{
			Digits *prev = FindPrev(Local);
			del = prev->next;
			prev->next = prev->next->next;
		}
		delete del;
		size--;
	}
	
	void clear()
	{
		for(int i = size; i > 0; i--)
		{
			remove();
		}
	}
	
	void add(const int& Digit)
	{
		insert(Digit, 0);
	}
	
	void insert(const int& Digit, int Local)
	{
		if(Local < 0 || Local > size) throw "Insert is not proper";
		else if(Local == 0)
		{
			head = new Digits(Digit, head);
		}
		else
		{
			Digits *prev = FindPrev(Local);
			prev->next = new Digits(Digit, prev->next);
		}
		size++;
	}
	
	Digits *GetDigitNode(int Local)
	{
		int index = 0;
		if(Local < 0 || Local > size) throw "Finding prev is not true";
		else
		{
			for(Digits *itr = head; itr != NULL; itr = itr->next, index++)
			{
				if(index == Local)
				return itr;
			}
		}
	}
	
	friend ostream& operator << (ostream& screen, Numbers& num)
	{
		if(num.isEmpty()) cout << "List is empty" << endl;
		for(Digits *itr = num.head; itr != NULL; itr = itr->next)
		{
			screen << itr->Digit << " ";
		}
		return screen;
	}
	
	~Numbers()
	{
		clear();
	}
};

#endif