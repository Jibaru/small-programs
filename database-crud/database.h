#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>
#include <vector>

#define DATABASE_NAME "database.txt"

struct Person
{
    int id;
    std::string name;
    int age;
    std::string profession;
};
void showPerson(const Person *p);
void showPersons(const std::vector<Person *> &persons);
void showDatabaseHead();
void insertPerson(const Person *p);
bool updatePerson(const Person *p);
std::vector<Person *> getAllPersons();
Person *getPerson(int id);
bool deletePerson(int id);

#endif /* _DATABASE_H_ */