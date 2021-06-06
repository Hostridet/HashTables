#include <iostream>
#include "string"
#include "HashTables.h"

using namespace std;
Game::Game(string name, string genre, string date, string creator)
{
    this->name = name;
    this->genre = genre;
    this->date = date;
    this->creator = creator;
}

HashTable::HashTable(unsigned int Size)
{
    games = new Game[Size];
    this->Size = Size;
}

HashTable::~HashTable()
{
    delete[] games;
}

unsigned int HashTable::hashFunc1(Game &gaming)
{
    gaming.id = 0;

    for (int i = 0; i < gaming.creator.length(); i++)
    {
        gaming.id += gaming.creator[i];
    }

    for (int i = 0; i < gaming.date.length(); i++)
    {
        if (gaming.date[i] == '.')
        {
            continue;
        }
        else
        {
            gaming.id += (int)gaming.date[i];
        }
    }
    unsigned int addr = gaming.id % Size;
    return addr;
}

unsigned int HashTable::hashFunc2(unsigned int addr)
{
    unsigned int addr2 = (addr + K) % Size;
    return addr2;
}

int HashTable::add(Game &gaming)
{
    unsigned int addr2 = hashFunc1(gaming);
    for(int i = 0; i < Size; i++)
    {
        if(games[addr2].pos == 0)
        {
            gaming.pos = 1;
            games[addr2] = gaming;
            return 0;
        }
        else
        {
            if(games[addr2].pos == 1 &&
               games[addr2].name == gaming.name &&
               games[addr2].date == gaming.date &&
               games[addr2].creator == gaming.creator &&
               games[addr2].genre == gaming.genre)
                return 1;
            if(games[addr2].pos == 2) {
                unsigned int PrevAddr = addr2;
                while (games[addr2].pos == 2)
                    addr2 = hashFunc2(addr2);
                if (games[addr2].pos == 1 &&
                    games[addr2].name == gaming.name &&
                    games[addr2].date == gaming.date &&
                    games[addr2].creator == gaming.creator &&
                    games[addr2].genre == gaming.genre)
                {
                    return 1;
                }
                else
                {
                    gaming.pos = 1;
                    games[PrevAddr] = gaming;
                    return 0;
                }
            }
        }
        addr2 = hashFunc2(addr2);
    }

    return 1;
}

int HashTable::del(Game &gaming)
{
    unsigned int addr2 = hashFunc1(gaming);

    for (int i = 0; i < Size; i++)
    {
        if (games[addr2].pos == 0)
            return 1;
        if (games[addr2].pos == 1)
        {
            if (games[addr2].id == gaming.id &&
                games[addr2].creator == gaming.creator &&
                games[addr2].date == gaming.date &&
                games[addr2].genre == gaming.genre &&
                games[addr2].name == gaming.name)
            {
                games[addr2].pos = 2;
                return 0;
            }
        }
        addr2 = hashFunc2(addr2);
    }
    return 1;
}

bool HashTable::search(Game &gaming)
{
    unsigned int addr2 = hashFunc1(gaming);

    for (int i = 0; i < Size; i++)
    {

        if (games[addr2].pos == 0)
            return false;
        if (games[addr2].pos == 1)
        {
            if (games[addr2].id == gaming.id &&
                games[addr2].creator == gaming.creator &&
                games[addr2].date == gaming.date &&
                games[addr2].genre == gaming.genre &&
                games[addr2].name == gaming.name)
            {
                return true;
            }
        }
        addr2 = hashFunc2(addr2);
    }
    return false;
}

std::ostream& operator<<(std::ostream &ofs, Game &gaming)
{
    ofs << gaming.name << ' ' << gaming.genre << ' ' << gaming.date << ' ' << gaming.creator;
    return ofs;
}

void HashTable::print()
{
    int count = 0;
    cout << "-----------------\n";
    for (int i = 0; i < Size; i++)
    {
        if (games[i].pos == 1)
        {
            count++;
            cout  << i << ". " << games[i] << endl;
        }
    }
    if (count == 0)
        cout << "HashTable is empty" << endl;
    cout << "-----------------\n";
}