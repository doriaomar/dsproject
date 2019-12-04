#pragma once
#include <string>
using namespace std;
class Node
{
public:
	Node  * next;
	string Name ;
	int priority;

	Node();
	Node(string val);
};


class LinkedList
{
	int count;
	Node  * head;
	Node  * tail;

public:
	LinkedList();
	int Length();
	void Append( string value, int prio);
	void ReadData();
	void Display();
	void sort();
	void Update();
	void Empty();
	void Edit();
	//void Option();
	//void InsertAt(int, T);
	//void DeleteAt(int);
	//void clear();;
	
	//~LinkedList(void);
};
class Mothers
{ public:
	string UserName;
	string Password;
	LinkedList L[2];
	Mothers();
};
