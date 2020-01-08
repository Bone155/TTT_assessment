#include "List.h"

List::List()
{
}

List::List(string & input)
{
	/*for (int i = 0; i < size; i++) {
		list->name[(size - 1) - i] = input;
	}*/
	fstream file;
	file.open("HitList.txt", ios::out | ios::app);
	if (!file.is_open())
	{
		std::cerr << "File not found." << endl;
	}
	file.clear();
	cin >> lines;
	cout << endl;
	for (int i = -1; i < lines; i++) {
		std::getline(cin, input);
		file << input << endl;
	}
	cout << endl;
	file.flush();
	file.close();
}


List::~List()
{
	
}

void List::remove(string &name)
{
	for (int i = 0; i < size; i++) {
		if (name == list->name[i]) {
			list->name[i] = "";
		}
	}
}

void List::print()
{
	for (int i = 0; i < size; i++) {
		cout << list->name[i] << endl;
	}
}
