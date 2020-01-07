#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

struct Target {
	string* name;
};

class List
{
	Target* list;
	string* targets;
public:
	int size;
	List();
	List(string &input);
	~List();

	void remove(string &name);
	void print();
};

