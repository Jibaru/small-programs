/**
 * Compile with g++
 * g++ database.h main.h -o main
 * 
 * Maked by Jibaru
*/
#include <iostream>
#include <vector>
#include <conio.h>
#include "database.h"

using namespace std;

int main()
{
    Person *p = NULL;
    int option = 0, personId = 0;

    do
    {
        system("cls");
        cout << "Menu" << endl;
        cout << "[1]. Insert" << endl;
        cout << "[2]. Update" << endl;
        cout << "[3]. Delete" << endl;
        cout << "[4]. View all" << endl;
        cout << "[5]. View one" << endl;
        cout << "[-1]. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            p = new Person();
            cout << "Insert" << endl;
            cout << "Name: ";
            cin >> p->name;
            cout << "Age: ";
            cin >> p->age;
            cout << "Profession: ";
            cin >> p->profession;

            insertPerson(p);

            cout << "Added successfully" << endl;
            break;
        }
        case 2:
        {
            cout << "Update" << endl;
            cout << "Person id: ";
            cin >> personId;
            p = getPerson(personId);

            if (p != NULL)
            {
                cout << "Name: ";
                cin >> p->name;
                cout << "Age: ";
                cin >> p->age;
                cout << "Profession: ";
                cin >> p->profession;

                if (updatePerson(p))
                {
                    cout << "Updated successfully" << endl;
                }
            }
            else
            {
                cout << "Person not finded" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Delete" << endl;
            cout << "Person id: ";
            cin >> personId;

            if (deletePerson(personId))
            {
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Person not finded" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "View all" << endl;
            vector<Person *> persons = getAllPersons();
            if (persons.size() > 0)
            {
                showPersons(persons);
            }
            else
            {
                cout << "Persons not finded" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "View one" << endl;
            cout << "Person id: ";
            cin >> personId;
            p = getPerson(personId);
            if (p != NULL)
            {
                showDatabaseHead();
                showPerson(p);
            }
            else
            {
                cout << "Person not finded" << endl;
            }
            break;
        }
        }

        getch();
    } while (option != -1);

    return 0;
}