#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab3/list.h"
#include "../lab3/functions.h"
#include "../lab3/equal.h"
#include "../lab3/tree.h"
#include "../lab3/map.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(creating_list_of_frequency_string)
		{
			std::string mystring = "string";
			list list1 = creating_list_of_frequency(mystring);
			list list2;
			list2.head = new list::node('g', 1);
			list2.head->next = new list::node('n', 1);
			list2.head->next->next = new list::node('i', 1);
			list2.head->next->next->next = new list::node('r', 1);
			list2.head->next->next->next->next = new list::node('t', 1);
			list2.head->next->next->next->next->next = new list::node('s', 1);
			list2.size = 6;
			Assert::IsTrue(equal_lists(list1, list2));
		}
		TEST_METHOD(creating_list_of_frequency_london)
		{
			std::string mystring = "london";
			list list1 = creating_list_of_frequency(mystring);
			list list2;
			list2.head = new list::node('n', 2);
			list2.head->next = new list::node('o', 2);
			list2.head->next->next = new list::node('d', 1);
			list2.head->next->next->next = new list::node('l', 1);
			list2.size = 4;
			Assert::IsTrue(equal_lists(list1, list2));
		}
		TEST_METHOD(map_string)
		{
			std::string mystring = "string";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			char*symbols1 = new char[6];
			size_t i = 0;
			for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					symbols1[i] = tmp->current_key();
					i++;
				}
			char*symbols2 = new char[6];
			symbols2[0] = 'i';
			symbols2[1] = 'g';
			symbols2[2] = 'r';
			symbols2[3] = 'n';
			symbols2[4] = 's';
			symbols2[5] = 't';
			string*codes1 = new string[6];
			i = 0;
			for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					codes1[i] = tmp->current_data();
					i++;
				}
			string*codes2 = new string[6];
			codes2[0] = "11";
			codes2[1] = "101";
			codes2[2] = "001";
			codes2[3] = "100";
			codes2[4] = "01";
			codes2[5] = "000";
			Assert::IsTrue(equal_arrays(symbols1, 6, symbols2, 6) && equal_arrays(codes1, 6, codes2, 6));
		}
		TEST_METHOD(map_london)
		{
			std::string mystring = "london";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			char*symbols1 = new char[4];
			size_t i = 0;
			for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					symbols1[i] = tmp->current_key();
					i++;
				}
			char*symbols2 = new char[4];
			symbols2[0] = 'l';
			symbols2[1] = 'd';
			symbols2[2] = 'n';
			symbols2[3] = 'o';
			string*codes1 = new string[4];
			i = 0;
			for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_color() != 'n')
				{
					codes1[i] = tmp->current_data();
					i++;
				}
			string*codes2 = new string[4];
			codes2[0] = "01";
			codes2[1] = "11";
			codes2[2] = "10";
			codes2[3] = "00";
			Assert::IsTrue(equal_arrays(symbols1, 4, symbols2, 4) && equal_arrays(codes1, 4, codes2, 4));
		}
		TEST_METHOD(codding_string)
		{
			std::string mystring = "string";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			string newstring1, newstring2, finded;
			int check;
			for (int i = 0; i < mystring.length(); i++)
			{
				finded.clear();
				mymap.find(&check, &finded, mystring[i]);
				newstring1 += finded;
			}
			newstring2 = "0100000111100101";
			Assert::AreEqual(newstring1, newstring2);
		}
		TEST_METHOD(codding_london)
		{
			std::string mystring = "london";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			string newstring1, newstring2, finded;
			int check;
			for (int i = 0; i < mystring.length(); i++)
			{
				finded.clear();
				mymap.find(&check, &finded, mystring[i]);
				newstring1 += finded;
			}
			newstring2 = "010010110010";
			Assert::AreEqual(newstring1, newstring2);
		}
		TEST_METHOD(decodding_string)
		{
			std::string mystring = "string";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			string newstring, finded;
			int check;
			for (int i = 0; i < mystring.length(); i++)
			{
				finded.clear();
				mymap.find(&check, &finded, mystring[i]);
				newstring += finded;
			}
			string codedstring;
			string finding;
			size_t i, j;
			i = 0;
			j = 0;
			char key;
			while (i < newstring.length())
			{
				j = i;
				while (j < newstring.length())
				{
					finding.clear();
					for (int k = i; k <= j; k++)
						finding += newstring[k];
					mymap.finddata(finding, &key, &check);
					if (check == -1)
						j++;
					else
					{
						i = j + 1;
						j = newstring.length();
						codedstring += key;
					}
				}
			}
			Assert::AreEqual(codedstring, mystring);
		}
		TEST_METHOD(decodding_london)
		{
			std::string mystring = "london";
			list mylist = creating_list_of_frequency(mystring);
			tree mytree;
			mytree.div(mylist);
			map<string> mymap;
			for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
				if (tmp->current_list().size == 1)
					mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
			string newstring, finded;
			int check;
			for (int i = 0; i < mystring.length(); i++)
			{
				finded.clear();
				mymap.find(&check, &finded, mystring[i]);
				newstring += finded;
			}
			string codedstring;
			string finding;
			size_t i, j;
			i = 0;
			j = 0;
			char key;
			while (i < newstring.length())
			{
				j = i;
				while (j < newstring.length())
				{
					finding.clear();
					for (int k = i; k <= j; k++)
						finding += newstring[k];
					mymap.finddata(finding, &key, &check);
					if (check == -1)
						j++;
					else
					{
						i = j + 1;
						j = newstring.length();
						codedstring += key;
					}
				}
			}
			Assert::AreEqual(codedstring, mystring);
		}
	};
}