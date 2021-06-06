#include <iostream>
#include "HashTables.h"

const int Sizes = 19;

int main() {
    HashTable table = HashTable(Sizes);

    Game Game1, Game2;

    Game1.name = "DDDCry";
    Game1.genre = "DDDion";
    Game1.creator = "Ubisoft";
    Game1.date = "01.05.2007";

    Game2.name = "Crysis";
    Game2.genre = "Action";
    Game2.creator = "Ubisoft";
    Game2.date = "01.05.2007";

    table.add(Game1);
    table.add(Game2);
    table.print();
    table.del(Game1);
    table.add(Game2);
    table.print();

    for (int i = 1; i < 12; i++)
    {

        table.add(Game1);
        Game1.creator[0]--;
        Game1.date[0]++;
        table.add(Game2);
        Game2.creator[0]++;
        Game2.date[0]--;
    }

    table.print();

    for (int i = 1; i < 14; i++)
    {

        table.del(Game1);
        Game1.creator[0]+=2;
        Game1.date[0]-=2;
        cout<< Game1.creator<<" "<< Game1.date<<endl;
    }

    Game1.name = "DDDCry";
    Game1.genre = "DDDion";
    Game1.creator = "Ubisoft";
    Game1.date = "01.05.2007";

    Game2.name = "Crysis";
    Game2.genre = "Action";
    Game2.creator = "Ubisoft";
    Game2.date = "91.05.2007";


    table.print();
    cout << table.search(Game1);
    for (int i = 1; i < 15; i++)
    {

        table.add(Game1);
        Game1.creator[0]--;
        Game1.date[0]++;
        table.add(Game2);
        Game2.creator[0]++;
        Game2.date[0]--;
    }

    table.print();

    return 0;
}
