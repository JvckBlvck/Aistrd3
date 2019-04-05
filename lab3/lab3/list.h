#pragma once
#include "pch.h"

class list
{
public:
	class node
	{
	public:
		char symbol;
		size_t frequency;
		node*next;
		node*prev;
		node(char symbol, size_t frequency)
		{
			this->symbol = symbol;
			this->frequency = frequency;
			next = nullptr;
			prev = nullptr;
		}
		~node() {}
	};
	size_t size;
	node*head;
	node*tail;
	list()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}
	~list() {}
	void add(char symbol, size_t frequency)
	{
		if (size == 0)
		{
			head = new node(symbol, frequency);
			tail = head;
		}
		else
		{
			node*cur = head;
			node*curprev;
			while ((cur != nullptr) && (cur->frequency > frequency))
				cur = cur->next;
			if (cur == head)
			{
				head->prev = new node(symbol, frequency);
				head->prev->next = head;
				head = head->prev;
			}
			else if (cur == nullptr)
			{
				tail->next = new node(symbol, frequency);
				tail->next->prev = tail;
				tail = tail->next;
			}
			else
			{
				curprev = cur->prev;
				cur->prev = new node(symbol, frequency);
				cur->prev->prev = curprev;
				curprev->next = cur->prev;
				cur->prev->next = cur;
			}
		}
		size++;
	}
};