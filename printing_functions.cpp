#include "functions.h"
using namespace std;


void printing_array(int index, item inventory[]) // A function printing the infomation of item when neccessary
{
    cout << inventory[index].key <<" ";
    cout << inventory[index].name <<" ";
    cout << inventory[index].manufacturer <<" ";
    cout << inventory[index].amount <<" ";
    cout <<fixed<<setprecision(2)<< inventory[index].price <<" ";
    cout<<endl;

}

void print_update_menu() // A function pringting the menu of update function
{
  cout<<"Which information to be updated?"<<endl;
  cout<<"1. Name"<<endl;
  cout<<"2. Manufacturer"<<endl;
  cout<<"3. Stock"<<endl;
  cout<<"4. Price"<<endl;
  cout<<"(Enter 0 to exit)"<<endl;
  cout<<endl;
  cout<<"Your choice: ";
}


void print_menu() // A function printing the main menu function when neccsary
{
  cout<< "-------------------------------------------------------------"<<endl;
  cout << "1) Search and sort commodity according to different filters. " << endl;
  cout << "2) Insert new commodity. " << endl;
  cout << "3) Delete obsolete commodity. " << endl;
  cout << "4) Update commodity information. " << endl;
  cout << "5) Exit. "<<endl;
  cout << endl;
  cout << "Your choice: ";
}
