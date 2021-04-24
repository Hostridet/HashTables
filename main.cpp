#include <iostream>
#include "HashTables.h"

const int Sizes = 15;

int main() {
    HashTable table = HashTable(Sizes);

    Game Game1, Game2;

    Game1.name = "FarCry";
    Game1.genre = "Action";
    Game1.creator = "Ubisoft";
    Game1.date = "01.05.2007";

    Game2.name = "Crysis";
    Game2.genre = "Action";
    Game2.creator = "Ubisoft";
    Game2.date = "01.05.2007";

    table.add(Game1);
    table.add(Game2);

    for (int i = 1; i < 12; i++)
    {

        table.add(Game1);
        Game1.creator[0]--;
        Game1.date[0]++;
    }

    table.print();
    Game1.creator[0]+=1;
    Game1.date[0]-=1;

    for (int i = 1; i < 7; i++)
    {

        table.del(Game1);
        Game1.creator[0]+=2;
        Game1.date[0]-=2;
    }


    table.print();
    cout << table.search(Game1);

    return 0;
}
