#pragma once
#include "pch.h"
#include "list.h"
#include <iostream>
#include "queue.h"
#include "iterator.h"

using namespace std;

class tree
{
private:
	class node
	{
	public:
		list mylist;
		node*prev;
		node*left;
		node*right;
		string code;
		node(list mylist)
		{
			this->mylist = mylist;
			prev = nullptr;
			left = nullptr;
			right = nullptr;
		}
		~node() {}
	};
	node*root;
public:
	tree()
	{
		root = nullptr;
	}
	~tree() {}
	void divrecurs(node*cur)
	{
		list::node*newcur;
		if (cur->mylist.size > 1)
		{
			size_t fequency, fequencysum, fequencysumhalf;
			fequency = 0;
			fequencysum = 0;
			newcur = cur->mylist.head;
			while (newcur != nullptr)
			{
				fequencysum += newcur->frequency;
				newcur = newcur->next;
			}
			fequencysumhalf = fequencysum / 2;
			list list1, list2;
			newcur = cur->mylist.head;
			while (newcur != nullptr)
			{
				if ((fequency + newcur->frequency) <= fequencysumhalf)
				{
					list1.add(newcur->symbol, newcur->frequency);
					fequency += newcur->frequency;
				}
				else
					list2.add(newcur->symbol, newcur->frequency);
				newcur = newcur->next;
			}
			cur->left = new node(list1);
			cur->left->prev = cur;
			cur->right = new node(list2);
			cur->right->prev = cur;
			if (cur != root)
			{
				if (cur->prev->left == cur)
					cur->code = (cur->prev->code) + "1";
				else
					cur->code = (cur->prev->code) + "0";
			}
			divrecurs(cur->left);
			divrecurs(cur->right);

		}
		else if (cur != root)
		{
			if (cur->prev->left == cur)
				cur->code = (cur->prev->code) + "1";
			else
				cur->code = (cur->prev->code) + "0";
		}
		else
			cur->code = "0";
	}
	void div(list mylist)
	{
		root = new node(mylist);
		divrecurs(root);
	}
	class BfsIterator : public Iterator {
	private:
		Queue *currentNodes;
	public:
		BfsIterator(node *root) {
			currentNodes = new Queue();
			if (root) currentNodes->pushBack(static_cast<void*>(root));
		}
		void next()
		{
			node* current = static_cast<node*>(currentNodes->front());
			currentNodes->popFront();
			if (current->left) currentNodes->pushBack(static_cast<void*>(current->left));
			if (current->right) currentNodes->pushBack(static_cast<void*>(current->right));
		}
		bool hasNext()
		{
			return !currentNodes->isEmpty();
		}
		list current_list() 
		{
			return (static_cast<node*>(currentNodes->front()))->mylist;
		}
		string current_code() 
		{
			return (static_cast<node*>(currentNodes->front()))->code;
		}
	};
	Iterator *createBfsIterator()
	{
		return new BfsIterator(root);
	}
};