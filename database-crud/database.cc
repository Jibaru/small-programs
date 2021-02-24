#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "database.h"

void showPerson(const Person *p)
{
    if (p != NULL)
    {
        std::cout
            << p->id << "\t"
            << p->name << "\t\t"
            << p->age << "\t"
            << p->profession << std::endl;
    }
}

void showPersons(const std::vector<Person *> &persons)
{
    showDatabaseHead();
    std::vector<Person *>::const_iterator it = persons.begin();
    for (; it != persons.end(); ++it)
    {
        showPerson(*it);
    }
}

void showDatabaseHead()
{
    std::cout << std::endl
              << "Id\tName\t\tAge\tProfession" << std::endl
              << std::endl;
}

void insertPerson(const Person *p)
{
    if (p != NULL)
    {
        std::ofstream file(DATABASE_NAME, std::ios_base::app);
        int nextId = getNextId();
        file << nextId << ',' << p->name << ',' << p->age << ',' << p->profession << "\n";
        file.close();
    }
}

bool updatePerson(const Person *p)
{
    std::string line;
    std::ifstream file(DATABASE_NAME);
    std::ofstream temp("temp.txt");

    bool updated = false;

    if (file.is_open())
    {
        while (getline(file, line))
        {

            std::vector<std::string> personParts;
            std::stringstream ss(line);
            std::string item;
            bool notFinded = true;

            while (notFinded && getline(ss, item, ','))
            {
                personParts.push_back(item);
                notFinded = false;
            }

            int findedId = stringToInt(personParts[0]);

            if (findedId != p->id)
            {
                temp << line << std::endl;
            }
            else
            {
                temp << p->id << ',' << p->name << ',' << p->age << ',' << p->profession << "\n";
                updated = true;
            }
        }
        temp.close();
        file.close();

        if (updated)
        {
            remove(DATABASE_NAME);
            rename("temp.txt", DATABASE_NAME);
        }
        else
        {
            remove("temp.txt");
        }
    }

    return updated;
}

std::vector<Person *> getAllPersons()
{
    std::string line;
    Person *p = NULL;
    std::vector<Person *> persons;
    std::ifstream file(DATABASE_NAME);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::vector<std::string> personParts;
            std::stringstream ss(line);
            std::string item;

            while (getline(ss, item, ','))
            {
                personParts.push_back(item);
            }

            p = new Person();
            p->id = stringToInt(personParts[0]);
            p->name = personParts[1];
            p->age = stringToInt(personParts[2]);
            p->profession = personParts[3];

            persons.push_back(p);
        }
        file.close();
    }
    return persons;
}

Person *getPerson(const int id)
{
    bool notFound = true;
    Person *p = NULL;
    std::vector<Person *> persons = getAllPersons();
    std::vector<Person *>::iterator it = persons.begin();
    for (; it != persons.end(); ++it)
    {

        if (notFound && (*it)->id == id)
        {
            p = (*it);
        }
    }
    return p;
}

bool deletePerson(const int id)
{
    std::string line;
    std::ifstream file(DATABASE_NAME);
    std::ofstream temp("temp.txt");

    bool deleted = false;

    if (file.is_open())
    {
        while (getline(file, line))
        {

            std::vector<std::string> personParts;
            std::stringstream ss(line);
            std::string item;
            bool notFinded = true;

            while (notFinded && getline(ss, item, ','))
            {
                personParts.push_back(item);
                notFinded = false;
            }

            int findedId = stringToInt(personParts[0]);

            if (findedId != id)
            {
                temp << line << std::endl;
            }
            else
            {
                deleted = true;
            }
        }
        temp.close();
        file.close();

        if (deleted)
        {
            remove(DATABASE_NAME);
            rename("temp.txt", DATABASE_NAME);
        }
        else
        {
            remove("temp.txt");
        }
    }

    return deleted;
}

/* Util functions */

int stringToInt(const std::string &s)
{
    std::stringstream ss(s);
    int x = 0;
    ss >> x;
    return x;
}

int getNextId()
{
    int maxId = -9999;
    std::vector<Person *> persons = getAllPersons();
    std::vector<Person *>::iterator it = persons.begin();
    for (; it != persons.end(); ++it)
    {

        if ((*it)->id > maxId)
        {
            maxId = (*it)->id;
        }
    }
    return (maxId + 1);
}