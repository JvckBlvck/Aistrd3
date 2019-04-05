#include "pch.h"
#include "functions.h"

using namespace std;

bool is_symbol_contains(list mylist, char symbol)
{
	list::node*cur = mylist.head;
	while (cur != nullptr)
	{
		if (symbol == cur->symbol)
			return true;
		cur = cur->next;
	}
	return false;
}

list creating_list_of_frequency(string mystring)
{
	list mylist;
	size_t frequency;
	for (size_t i = 0; i < mystring.length(); i++)
		if (is_symbol_contains(mylist, mystring[i]) == false)
		{
			frequency = 0;
			for (size_t j = 0; j < mystring.length(); j++)
				if (mystring[i] == mystring[j])
					frequency++;
			mylist.add(mystring[i], frequency);
		}
	return mylist;
}