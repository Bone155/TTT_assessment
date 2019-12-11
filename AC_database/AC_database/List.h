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
	Target creed;
	string* targets;
	int size;
public:
	List();
	List(int _size);
	List(string &input);
	~List();

	void remove(string &name);
	void print();
};

