#include "List.h"

List::List()
{
}

List::List(string & input)
{
	for (int i = 0; i < size; i++) {
		list->name[(size - 1) - i] = input;
	}
	
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
	find(list, name);
}

void List::print()
{
	fstream file;
	file.open("HitList.txt", ios::in);
	if (!file.is_open())
	{
		std::cerr << "File not found." << endl;
	}
	string text;
	while (std::getline(file, text)) {
		cout << text << endl;
	}
	cout << endl;
	file.close();
}

Target List::find(Target* targets, string& name) {
	Target tag;
	fstream file;
	file.open("HitList.txt", ios::in);
	if (file.is_open) {
		string text;
		while (std::getline(file, text)) {
			if (&text == &name) {
				tag.name = &text;
			}
		}
		file.close();
	}
	return tag;

}