#include "List.h"

List::List()
{
}

List::List(string & input)
{
	for (int i = 0; i < size; i++) {
		targets[(size - 1) - i] = input;
	}
}


List::~List()
{
}

void List::remove(string &name)
{
	for (int i = 0; i < size; i++) {
		if (name == targets[i]) {
			targets[i].empty();
		}
	}
}

void List::print()
{
	for (int i = 0; i < size; i++) {
		cout << targets[i] << endl;
	}
}
