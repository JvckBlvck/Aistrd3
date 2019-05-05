#pragma once
#include "pch.h"
#include "list.h"

bool equal_lists(list list1, list list2)
{
	if (list1.size != list2.size)
		return false;
	list::node*cur1 = list1.head;
	list::node*cur2 = list2.head;
	while (cur1 != nullptr)
	{
		if (cur1->frequency != cur2->frequency)
			return false;
		if (cur1->symbol != cur2->symbol)
			return false;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return true;
}

template <class T>
bool equal_arrays(T*array1, size_t size1, T*array2, size_t size2)
{
	if (size1 != size2)
		return false;
	for (size_t i = 0; i < size1; i++)
		if (array1[i] != array2[i])
			return false;
	return true;
}