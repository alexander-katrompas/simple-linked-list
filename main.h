#include<iostream>
#include<string>

using namespace std;

struct Item {
    int day;
    string dayname;
    Item *next;
};

void buildList1(Item**);
void buildList2(Item**);
void buildList3(Item*&, int dayofweek = 0);
void displayList(Item*);


