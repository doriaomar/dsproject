#pragma once
#include <string>
using namespace std;

class Node
{
public:
	Node* next;
	string Name;
	int priority;

	Node();
	Node(string val, int pr);
};


class Linkedqueue
{
	int count;
	Node* head;
	Node* tail;

public:
	Linkedqueue();
	void ReadData();
	void Append(string, int);
	void sort();
	void Display();
	void Update();
	bool Empty();
	void Edit();
	void MoveTask(string);
	void Delete(int);
	void clear();
};

class Mother {

	string pass;
	string Name;

public:
	Linkedqueue L;
	Mother();
	string loginfn();
	string registration();
	void NewTask(string&);
	void Disease(string&);
	void balance();

};
