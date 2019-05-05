// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "functions.h"
#include "tree.h"
#include "map.h"
#include <iomanip>

using namespace std;

int main()
{
	cout << "Hello World!\n";
	string mystring;
	cin >> mystring;
	if (mystring.length() > 0)
	{
		cout << "\nMemory space is " << mystring.length() * 8 << " bites \n";
		list mylist = creating_list_of_frequency(mystring);
		list::node*cur = mylist.head;
		cout << "\nFequencies of symbols:\n";
		while (cur != nullptr)
		{
			cout << cur->symbol << " ";
			cur = cur->next;
		}
		cout << "\n";
		cur = mylist.head;
		while (cur != nullptr)
		{
			cout << cur->frequency << " ";
			cur = cur->next;
		}
		cout << "\n";
		tree mytree;
		mytree.div(mylist);
		map<string> mymap;
		for (Iterator *tmp = mytree.createBfsIterator(); tmp->hasNext(); tmp->next())
			if (tmp->current_list().size == 1)
				mymap.insert(tmp->current_list().head->symbol, tmp->current_code());
		cout << "\nCodes of symbols:\n";
		for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
			if (tmp->current_color() != 'n')
				cout << setw(tmp->current_data().length()) << tmp->current_key() << " ";
		cout << "\n";
		for (mapIterator<string> *tmp = mymap.createBfsIterator(); tmp->hasNext(); tmp->next())
			if (tmp->current_color() != 'n')
				cout << setw(tmp->current_data().length()) << tmp->current_data() << " ";
		cout << "\n";
		string newstring, finded;
		int check;
		for (int i = 0; i < mystring.length(); i++)
		{
			finded.clear();
			mymap.find(&check, &finded, mystring[i]);
			newstring += finded;
		}
		cout << "\nNew string is\n";
		cout << newstring << "\n";
		cout << "\nMemory space is " << newstring.length() << " bites \n";
		double k = (double)mystring.length() * 8 / (double)newstring.length();
		cout << "Coefficient of compression is " << k << "\n";
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
		cout << "\nCoded string was\n" << codedstring << "\n";
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
