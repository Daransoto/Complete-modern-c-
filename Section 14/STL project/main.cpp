#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>

using namespace std;
class Contact {
public:
	string name;
	string lastname;
	string primary_phone;
	string secondary_pohne;
	string email;
	string address;
	string company;
	string group;
};

int main(void) {
	vector<Contact> contacts;
	int option;
	while (1) {
		system("cls");
		cout << "Contacts application" << endl << endl;
		cout << "Menu" << endl;
		cout << "-------------------" << endl << endl;
		cout << "1) Insert contact" << endl;
		cout << "2) Display all contacts" << endl;
		cout << "3) Display contacts from company" << endl;
		cout << "4) Display contacts from group" << endl;
		cout << "5) Search in contacts" << endl;
		cout << "6) Count of contacts" << endl;
		cout << "7) Exit" << endl << endl;

		cout << "Choose an option: ";
		cin >>  option;
		system("cls");
		cin.ignore();

		if (option == 1) {
			Contact new_contact = Contact();
			cout << "Insert contact name: ";
			getline(cin, new_contact.name);
			cout << endl << "Insert contact lastname: ";
			getline(cin, new_contact.lastname);
			cout << endl << "Insert contact primary phone number: ";
			getline(cin, new_contact.primary_phone);
			cout << endl << "Insert contact secondary phone number: ";
			getline(cin,  new_contact.secondary_pohne);
			cout << endl << "Insert contact email: ";
			getline(cin,  new_contact.email);
			cout << endl << "Insert contact address: ";
			getline(cin,  new_contact.address);
			cout << endl << "Insert contact company: ";
			getline(cin,  new_contact.company);
			cout << endl << "Insert contact group: ";
			getline(cin,  new_contact.group);
			contacts.emplace_back(new_contact);
			system("cls");
			cout << "New contact stored: " << new_contact.name;
		}
		else if (option == 2) {
			int op_sort;
			cout << "Sort by..." << endl << endl;
			cout << "1) First name" << endl;
			cout << "2) Lastname" << endl << endl;
			cout << "Choose an option: ";
			cin >>  op_sort;
			system("cls");
			if (op_sort == 1) {
				sort(contacts.begin(), contacts.end(), [](Contact& c1, Contact& c2) {return c1.name < c2.name; });
				for (Contact contact : contacts) {
					cout << contact.name << " " << contact.primary_phone << endl;
				}
			}
			else if (op_sort == 2) {
				sort(contacts.begin(), contacts.end(), [](Contact& c1, Contact& c2) {return c1.lastname < c2.lastname; });
				for (Contact contact : contacts) {
					cout << contact.name << " " << contact.primary_phone << endl;
				}
			}
		}
		else if (option == 3) {
			string company;
			cout << "What company do you want to see contacts from?" << endl << endl;
			getline(cin,  company);
			for (Contact contact : contacts) {
				if (contact.company == company) cout << contact.name << " " << contact.primary_phone << endl;
			}
		}
		else if (option == 4) {
			string group;
			cout << "What group do you want to see contacts from?" << endl << endl;
			getline(cin,  group);
			for (Contact contact : contacts) {
				if (contact.group == group) cout << contact.name << " " << contact.primary_phone << endl;
			}
		}
		else if (option == 5) {
			int op_search;
			string search_st;
			cout << "Search by..." << endl << endl;
			cout << "1) First name" << endl;
			cout << "2) Lastname" << endl << endl;
			cout << "Choose an option: ";
			cin >>  op_search;
			system("cls");
			cout << "Enter the search string: ";
			cin.ignore();
			getline(cin,  search_st);
			system("cls");
			for (Contact contact : contacts) {
				size_t found;
				if (op_search == 1)
					found = contact.name.find(search_st);
				else
					found = contact.lastname.find(search_st);
				if (found != string::npos)
					cout << contact.name << " " << contact.primary_phone << endl;
			}
		}
		else if (option == 6) {
			int op_search, count = 0;
			string search_st;
			cout << "Count by..." << endl << endl;
			cout << "1) Company" << endl;
			cout << "2) Group" << endl << endl;
			cout << "Choose an option: ";
			cin >>  op_search;
			system("cls");
			cout << "Enter the name of the company/group: ";
			cin.ignore();
			getline(cin,  search_st);
			for (Contact contact : contacts) {
				if (op_search == 1) {
					if (contact.company == search_st)
						count++;
				}
				else
					if (contact.group == search_st)
						count++;
			}
			system("cls");
			cout << "The amount of contacts from " << search_st << " is " << count;
		}
		else if (option == 7)
			break;

		_getch();
	}
	return 0;
}