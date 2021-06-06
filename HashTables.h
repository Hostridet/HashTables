#include "string"
#pragma once

using namespace std;

struct Game
{
public:
    Game() = default;
    Game(string name, string genre,string date,string creator);
    string name;
    string genre;
    string date;
    string creator;
    char pos = 0;
    unsigned int id = 0;

};
class HashTable
{
private:
    int Size;
    Game *games;
    unsigned int K = 4;
    unsigned int hashFunc1(Game &gaming);
    unsigned int hashFunc2(unsigned int addr);
public:
    explicit HashTable(unsigned int Size = 10);
    ~HashTable();
    int add(Game &gaming);
    int del(Game &gaming);
    bool search(Game &gaming);
    void print();
};

