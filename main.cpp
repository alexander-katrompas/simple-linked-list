#include "./main.h"

/***********************
    global constants
***********************/
const int DAYS = 7;
const string days[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

/**********************************************************
    creates a singly linked list of the days of the week
**********************************************************/
void buildList1(Item **head) {
     //easiest to understand solution
     
     Item *newItem, *position;

     for(int i=0; i<DAYS; i++){

         //create item
         newItem = new Item;
         newItem->day = i;
         newItem->dayname = days[i];
         newItem->next = NULL;

         //attached it
         if(*head == NULL){
             //it's the first item
             *head = newItem;
             position = *head;
         } else {
             //not the first item
             position->next = newItem;
             position = newItem;
         }
     }

}

void buildList2(Item **head) {
     // more elegant and efficent solution
     // more difficult to understand

     Item *newItem;
     for(int i=0; i<DAYS; i++){

         //create item
         newItem = new Item;
         newItem->day = i;
         newItem->dayname = days[i];
         newItem->next = NULL;

         //attached it
         *head = newItem;
         head = &newItem->next;
     }

}

void buildList3(Item*& last_ptr, int dayofweek) {
    // using recursion
    // most elegant solution
    // most difficult to understand
    
    if (dayofweek < DAYS) {
        last_ptr = new Item;
        last_ptr->day = dayofweek;
        last_ptr->dayname = days[dayofweek];
        buildList3(last_ptr->next, dayofweek + 1);
    } else
        last_ptr = NULL;
}


/**********************************************************
    displays a singly linked list of the days of the week
**********************************************************/
void displayList(Item *head) {
    Item *current = head;

    cout << "Listing the days of the week" << endl;
    cout << "============================" << endl;
    for(int i=0; i<DAYS && current != NULL; i++){
        cout << current->day << ": " << current->dayname << endl;
        current = current->next;
    }
}


/********************************************************************
    creates a head pointer, sends it to buildList, then displayList
********************************************************************/
int main() {

    Item *headptr = NULL;

    // uncomment and use only one of these at a time to see how they work
    buildList1(&headptr);
    //buildList2(&headptr);
    //buildList3(headptr);
    displayList(headptr);

    return 0;
}

