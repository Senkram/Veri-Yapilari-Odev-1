#ifndef NUMBERNODE_HPP
#define NUMBERNODE_HPP

#include "Numbers.hpp"

struct NumberNode
{
	Numbers* number;
	NumberNode *next;
	
	NumberNode(Numbers *number, NumberNode *next = NULL)
	{
		this->number = number;
		this->next = next;
	}
	
	Numbers *GetNumber()
	{
		return number;
	}
	
	void clearNumbers()
	{
		number->clear();
	}
};

#endif