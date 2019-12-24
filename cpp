#include "linkedQueue.h"
#include <iostream>
#include <string>
#include <assert.h>
#include<fstream>
using namespace std;

Node::Node()
{
	Name = " ";
	next = 0;
	priority = 0;
}
Node::Node(string val, int pr)
{
	Name = val;
	next = 0;
	priority = pr;
}
Linkedqueue::Linkedqueue()
{
	head = tail = 0;
	count = 0;
}

Mother::Mother()
{
	pass = " ";
	Name = " ";
}
void Linkedqueue::ReadData() {
	system("pause");
	system("cls");
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "       *                                                                                     *" << endl;
	cout << "       *                                                                                     *" << endl;
	cout << "       *    This Mothering role will Teach You More About Yourself Than You Ever Expected    *" << endl;
	cout << "       *                                                                                     *" << endl;
	cout << "       *                                                                                     *" << endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << " Now .. let's Start Our Day , Mammy " << endl;
	cout << endl;
	cout << endl;

	cout << "    Fill Your Tasks Today With it's Priority ...." << endl;
	cout << "    Priority Must be between 1 To 10 " << endl;
	cout << "    1 For Least important and 10 For Most important ." << endl;
	cout << " ***********************************************************" << endl;

	int Choice;
	int P;
	string Task_Name;
	do {
		cout << "Enter Task Name : ";
		cin >> Task_Name;
		do
		{
			cout << "Enter Task Priority : ";
			cin >> P;
		} while (P < 1 || P > 10 || P == 0);
		Append(Task_Name, P);
		cout << " Press 1 to continue : ";
		cin >> Choice;
		cout << "**********************" << endl;
	} while (Choice == 1);
	system("cls");
	/*sort();*/
	cout << " Your tasks today are " << endl;
	cout << "############################" << endl;
	cout << endl;
	Display();
}
void Linkedqueue::Append(string val, int prio)
{
	Node* newNode = new Node;
	newNode->Name = val;
	newNode->priority = prio;
	if (head == 0)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
	sort();
}
void Linkedqueue::sort()
{
	Node* NodeTmp = head;
	Node* NextNode = NodeTmp->next;
	while (NodeTmp->next != 0) {
		//swap(TEMPNEXT, TEMP);
		while (NextNode != 0) {
			if (NodeTmp->priority < NextNode->priority) {
				Node* Swap = new Node;
				Swap->Name = NodeTmp->Name;
				Swap->priority = NodeTmp->priority;
				NodeTmp->Name = NextNode->Name;
				NodeTmp->priority = NextNode->priority;
				NextNode->Name = Swap->Name;
				NextNode->priority = Swap->priority;
				NextNode = NextNode->next; // han5ly temp sabta w n7rk TEMPNEXT f hanb2a b n check var wa7d m3 ba2i l variables */
			}
			else {
				NextNode = NextNode->next;
			}
		}
		NodeTmp = NodeTmp->next;
		NextNode = NodeTmp->next;
	}
}
void Linkedqueue::Display()
{
	Node* tmp = head;

	cout << " Priority :             Task Name : " << endl;
	for (int i = 0; i < count; i++) {
		cout << "   " << tmp->priority << "                       " << tmp->Name << endl;
		tmp = tmp->next;
	}


}
void Linkedqueue::Update() // Pop task depending on it's priority
{
	system("cls");
	if (count != 0)
	{
		Node* temp = head;
		cout << "How pretty Are You !! ..  Our Mission Done  ***" << temp->Name << "***" << endl;
		head = head->next;
		delete temp;
		count--;
		cout << endl;

		if (head != 0)
		{
			cout << "****** Now .. Let us go To Another Mission Mammy  ******" << endl;
			cout << " Your Next Task  : " << head->Name << endl;
			cout << endl;
		}
		else
		{
			system("pause");
			//Empty();
			system(" cls");
			cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
			cout << "       *                                                 *" << endl;
			cout << "       *                                                 *" << endl;
			cout << "       *    Thank You Mom For Your Unconditional Love    *" << endl;
			cout << "       *                                                 *" << endl;
			cout << "       *                                                 *" << endl;
			cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Yaaaaaaaaaaaaaaaaaah !! Congratulation Our Missions Today Done  " << endl;
			cout << endl;
			cout << " Now it's Time To rest" << endl;
		}
	}

}
bool Linkedqueue::Empty()
{

	return (count == 0);
}

void Linkedqueue::Edit()
{
	cout << "Enter Your  Task's Name ";
	string Name;
	int position = 0;
	Node* edit = head;
	cin >> Name;
	while (edit != 0) {
		if (edit->Name != Name) {
			edit = edit->next;
			position++;
		}

		else
		{
			int EditChoice;
			cout << " 1 -> Edit Name" << endl;
			cout << " 2 -> Edit Priorty " << endl;
			cout << " 3 -> Edit Priorty and Name" << endl;
			cout << " 4 -> Delete task" << endl;
			cin >> EditChoice;
			string NName;
			int prioo;
			if (EditChoice == 1) {
				cout << "Enter New Name : ";
				cin >> NName;
				edit->Name = NName;
				break;
			}
			else if (EditChoice == 2)
			{
				do
				{
					cout << "Priority must be between 1 to 10  \n ";
					cout << "Enter Task Priority : ";
					cin >> prioo;
				} while (prioo < 1 || prioo > 10 || prioo == 0);

				edit->priority = prioo;
				break; // break mn l loop l kbera
			}
			else if (EditChoice == 3)
			{
				do
				{
					cout << "Priority must be between 1 to 10   \n ";
					cout << "Enter Task Priority : ";
					cin >> prioo;
				} while (prioo < 1 || prioo > 10 || prioo == 0);
				edit->priority = prioo;
				cout << "Enter New Name : ";
				cin >> NName;
				edit->Name = NName;
				break;
			}

			else if (EditChoice == 4) {
				Delete(position);
				break;
			}
			else {
				cout << "Not Valid ";
				break;
			}
		}// end of else l kbera
	} // end of while loop
	if (count != 0) {
		sort();
	}
}
void Linkedqueue::MoveTask(string name)
{
	system("cls");
	cout << "  We are sorry !    really you have been exhausted today..." << endl;
	cout << endl;
	string New;
	int pos = 0;
	Node* move = head;
	ofstream x;
	x.open(name + ".txt", ios::out | ios::app);
	// Does the file even exist?
	if (!x.is_open())
	{
		cout << "Error opening file";
		exit(-1);
	}
	cout << "Enter Task You Need To Move: ";
	//cin.clear();
	//cin.ignore();
	cin >> New;
	for (int i = 0; i < count; i++)
	{
		if (move->Name == New)
		{
			cin.get();//
			x << New << "\n";
			break;
		}
		move = move->next;
		pos++;
	}
	Delete(pos);

	x.close();
	cout << " Task has been moved sucssesfully!" << endl;
}
void Linkedqueue::Delete(int  N) {
	Node* tmp = head;
	if (N == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < N - 1; i++)
			tmp = tmp->next;
		Node* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (N == count - 1)
			tail = tmp;

	}
	count--;
}
void Linkedqueue::clear() {
	if (count == 0)
		return;
	Node* tmp = head->next;
	while (head->next != 0)
	{
		delete head;
		head = tmp;
		tmp = tmp->next;
	}

	delete head;
	head = tail = 0;
	count = 0;
}
string Mother::registration() {
	system("cls");
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *        The best medicine in the world is a Mother's Hug       *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	fstream M;
	string confirmpass;
	M.open("Motherdata.txt", ios::app); /*app put the data at the end*/
	// Does the file even exist?
	if (!M.is_open())
	{
		cout << "Error opening file";
		exit(-1);
	}
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, Name);

	cout << "Enetr password : ";
	getline(cin, pass);
	while (pass.length() >= 17 || pass.length() < 4)
	{
		cout << "Password length must be between 4 & 17 ..Try Again!!" << endl;
		cout << "Enetr password : ";
		getline(cin, pass);
	}

	//confirm password
	do {
		cout << "Confirm password : ";
		cin >> confirmpass;
		if (pass == confirmpass)
		{

			M << Name << "\n";
			M << pass << "\n";
		}
		else
		{
			cout << "password Not Matching ... TryAgin!!" << endl;
			cout << "Confirm password: ";
			cin >> confirmpass;
		}
	} while (pass != confirmpass);

	cout << "register sussesfuly " << endl;
	cout << "\nThank You , " << Name << endl;
	ofstream z;//bft7 file 3shan yb2a b asm rli 3amel regist
	z.open(Name + ".txt");

	ofstream O;
	O.open(Name + ".D.txt");
	cout << "Do you suffer from any disease? press 'Y' for yes and 'N' for No : ";
	string CH;
	cin >> CH;
	O << CH;
	M.close();
	O.close();
	return Name;//3shan el move w kman el main
}

string Mother::loginfn() {
	system("cls");
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *    The Strength of Motherhood is Greater Than Natural Laws    *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       *                                                               *" << endl;
	cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	string name2, pass2;
	int found = 0; // Initialize this!
	while (true)
	{
		cout << "Enter Username: ";
		cin.ignore();
		cin >> name2;
		cout << "Enter Password: ";
		cin >> pass2;
		ifstream C("Motherdata.txt");
		string infile;
		ifstream z;
		z.open(name2 + ".txt");
		while (!C.eof()) //if not at end in file
		{
			getline(C, infile);

			if ((infile == name2)) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			cout << "\nno such user\n" << endl;
			continue;
			//	return;
		}
		string mypass;
		getline(C, mypass);
		if (pass2 == mypass) {
			cout << "\nWelcome ," << name2 << endl;
			break;
		}
		else {
			cout << "\nInCorrect password...Tryagin!!\n";
		}
		C.close();
	}
	NewTask(name2);

	return name2;
}
void Mother::NewTask(string& name)
{
	ifstream C(name + ".txt");
	string Name;
	int pero;

	while ((C >> Name))// tol ma fe task lef el loop
	{
		cout << " Reminder ***  You Have a Task From Yasterday  " << endl;
		cout << endl;
		cout << "Your Task is : " << Name << endl;
		cout << endl;
		do
		{
			cout << "Priority must be between 1 to 10   \n ";
			cout << "Enter Task Priority : ";
			cin >> pero;
		} while (pero < 1 || pero > 10 || pero == 0);
		L.Append(Name, pero);
	}

	C.close();
}void Mother::Disease(string& Name) {

	int  water;
	ifstream D(Name + ".D.txt");
	string Di;
	D >> Di;
	if (Di == "y" || Di == "Y") {
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                 We care about your health ^_^                 *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                Remember to take your medication :)            *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;

	}
}void Mother::balance() {

	float  water;
	cout << "    Enter water , Normal-> between 2 to 4 litters per day ^_^     ";
	cin >> water;
	if (water > 3 && water <= 4) {
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *             WOow how you do this   (^-^)                      *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}
	else if (water >= 2 && water <= 3) {
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                   good job pretty, keep going   (^-^)                     *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;


	}
	else if (water >= 0 && water <= 1) {

		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *     you don't care about your health but we care  (^-^)        *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;


	}
	else {


		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *       Be careful , this may cause water poisoning             *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       *                                                               *" << endl;
		cout << "       * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
	}


}
