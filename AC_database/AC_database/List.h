#pragma once
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::fstream;
using std::ios;
using std::cout;
using std::cin;
using std::endl;

struct Target {
	string* name;
};

class List
{
	Target* list;
	
public:
	int size;
	List();
	List(string &input);
	~List();

	void remove(string &name);
	void print();
};

