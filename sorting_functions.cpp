#include "functions.h"
using namespace std;


// -----------------------BOOLEAN FUNCTIONS FOR SORTING RULES---------------------------------------//


bool compare_manufacturer(item a, item b){                   // boolean functions to return TRUE when a<b according to Manufacturer
                                                            // input: 2 item data type to compare.
  int value;
  value = (a.manufacturer).compare(b.manufacturer);
  if(value>0)
      return false;
  return true;
  }

bool compare_amount(item a, item b) {return a.amount<b.amount;}

bool compare_price(item a, item b) {return a.price<b.price;}

bool compare_name(item a, item b){
  int value;
  value = (a.name).compare(b.name);
  if(value>0)
      return false;
  return true;
  }



//---------------------------------------SORT FUNCTION---------------------------------------//

void sort_function(int array_size, item inventory[]){             //function to print sort menu and call the proper sorting functions
                                                                  // input: size of array as int and array of items

    int choice;

    cout << "How do you want to sort the results?"<<endl;
    cout << "1) Key (unsorted) " << endl;
    cout << "2) Name " << endl;
    cout << "3) Manufacturer  " << endl;
    cout << "4) Price " << endl;
    cout << "5) Stock Number " << endl;
    cout << "Enter anything else to return to main menu.";
    cout << "Your choice: ";
    cin  >>  choice;

    if(choice==2)
        {
          sort(inventory, inventory + array_size ,compare_name);
        }
    else if(choice==3)
        {
          sort(inventory, inventory + array_size ,compare_manufacturer);
        }
    else if(choice==4)
        {
          sort(inventory, inventory + array_size ,compare_price);
        }
    else if(choice==5)
        {
          sort(inventory, inventory + array_size ,compare_amount);
        }
}
