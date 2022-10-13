//Getting to understand how to use structure in cpp
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Just creates the custom data type Contact
struct Contact               //Struct let's C++ know that Contact is a structure
{			                 // Marks the begining of the structures contents( it's memebers)
	string name;             //Contacts name
	long long phoneNumber = 0;  //Contacts phone number
	string email;            //contacts email
};                            //marks the end of the structure

class ContactList
{
	const int max = 200;
	Contact* list = new Contact[max];

public:

	bool eof(Contact* ptr) //should detect the end of our list returns a bool
	{
		if (ptr->name == "")
			return true;
		else
			return false;
	}

	Contact* append()
	{
		for (int i = 0; i < max; i++)
		{
			if (eof(list + i))
				return (list + i);
			else
				cout << "Contact list is full";
		}
	}

	void write(Contact* listContact) //writes to an address
	{
		Contact c;
		cout << "Enter name: ";
		cin >> c.name;
		cout << endl;

		cout << "Enter number: ";
		cin >> c.phoneNumber;

		cout << "Enter email: ";
		cin >> c.email;

		*listContact = c;
	}

	Contact* read(int i)
	{
		return list + i;
	}

	void print(Contact* listContacts1) //read the contents of an adress
	{
		if (listContacts1 != nullptr) {
			cout << "Name: " << listContacts1->name << endl;
			cout << "Number: " << listContacts1->phoneNumber << endl;
			cout << "Email: " << listContacts1->email << endl;
		}
		else
			cout << "Contact not found!\n";
	}

	Contact* search() //search for a contact return address
	{
		cout << "Enter the name you want to searh for: ";
		string searchName;
		cin >> searchName;

		for (int i = 0; i < max; i++)
		{
			if (eof(list + i))
			{
				return nullptr;
				break;
			}
			else if (searchName == (list + i)->name)
			{
				return (list + i);
			}
		}
	}

	void delet()
	{
		Contact* toDelete;
		toDelete = search();
		for(int i = 0, j = 0; i<max; i++, j++)
		{
			if (!eof(&list[i]))
			{
				if (&list[j] == toDelete)
					j++;
				list[i] = list[j];
			}
			else
				break;
		}
	}

	void edit()
	{
		Contact* listContacts2 = search();
		if (listContacts2 != nullptr) {
			write(listContacts2);
		}
		else
			cout << "Contact not found!\n";
	}
};

//creating main menue

void menu()
{
	ContactList contacts;
	bool status;
	do 
	{
		cout << "Select option:\n1) add contact\n2) search Contact\n3) edit\n4) view all\n";
		int selection;
		cin >> selection;

		switch (selection) 
		{
		case 1:
			system("CLS");
			contacts.write(contacts.append());
			break;
		case 2:
			system("CLS");
			contacts.print(contacts.search());
			break;
		case 3:
			system("CLS");
			contacts.edit();
		case 4:
			system("CLS");
			for (int i = 0; i < 100; i++)
			{
				if (!contacts.eof((contacts.read(i))))
					contacts.print(contacts.read(i));
			}
			break;

		}
		cout << "DO you want to go back to the main menu? (1/0)";
		cin >> status;
	} while (status);
}

int main()
{
	menu();
	return 0;
}