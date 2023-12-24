#ifndef LIST_HPP
#define LIST_HPP

#include "NumberNode.hpp"

class List
{
private:
	NumberNode *head;
	int size;
	
	NumberNode *FindPrev(int Local)
	{
		int index = 1;
		if(Local < 0 || Local > size) throw "Finding prev is not true";
		else if(Local == 0) throw "Head node has no prev";
		else
		{
			for(NumberNode *itr = head; itr != NULL; itr = itr->next, index++)
			{
				if(index == Local) return itr;
			}
		}
	}
public:
	List()
	{
		head = NULL;
		size = 0;
	}
	
	NumberNode *GetNode(int Local)
	{
		int index = 0;
		if(Local < 0 || Local > size) throw "Finding prev is not true";
		else
		{
			for(NumberNode *itr = head; itr != NULL; itr = itr->next, index++)
			{
				if(Local == index)
				return itr;
			}
		}
	}
	
	Numbers *GetNumber(int Local)
	{
		NumberNode *Node = GetNode(Local);
		Node->GetNumber();
	}
	
	int count()
	{
		return size;
	}
	
	void add(Numbers *number)
	{
		insert(number, size);
	}
	
	void insert(Numbers *number, int Local)
	{
		if(Local < 0 || Local > size) throw "Insert is not proper";
		else if(Local == 0)
		{
			head = new NumberNode(number);
		}
		else
		{
			int index = 1;
			for(NumberNode *itr = head; itr != NULL; itr = itr->next, index++)
			{
				if(index == Local)
				{
					NumberNode *prev = FindPrev(Local);
					prev->next = new NumberNode(number, prev->next);
				}
			}
		}
		size++;
	}
	
	void GetOddEarlier()
	{
		Numbers *Num = GetNumber(0);
		int digit = Num->GetDigitNode(0)->Digit;
	}
	
	friend ostream& operator << (ostream& screen, List& list)
	{
		for(NumberNode *itr = list.head; itr != NULL; itr = itr->next)
		{
			screen << itr->number << " ";
		}
		return screen;
	}
	
	void clearNums()
	{
		for(NumberNode *itr = head; itr != NULL; itr = itr->next)
		{
			itr->clearNumbers();
		}
	}
	
	~List()
	{
		clearNums();
	}
};

#endif