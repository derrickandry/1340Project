#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
//#include "functions.h"
using namespace std;

const int MAXSIZE = 100;

struct item
{
    int key;
    string name;
    string manufacturer;
    int amount;
    double price;
    bool status;
};
// -----------------------BOOLEAN FUNCTIONS FOR SORTING---------------------------------------//
bool compare_manufacturer(item a, item b){
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



//------------------------------------------------------------------------------------------------//
void sort_function(int array_size, item inventory[]){

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
void print_update_menu()
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

void update_item(item inventory[], int index)
{
  string name, man;
  int amount;
  double price;
  int choice;
  print_update_menu();
  while(choice!=0)
      {
        cin>>choice;
        if(choice==1)
          {
            cout<<"Please input the new name: ";
            cin>>name;
            inventory[index].name = name;
            cout<<"Name updated!";
            cout<<endl;
            print_update_menu();
          }
        else if(choice==2)
          {
            cout<<"Please input the new manufacturer: ";
            cin>>man;
            inventory[index].manufacturer = man;
            cout<<"Manufacturer updated!";
            print_update_menu();
          }
        else if(choice==3)
          {
            cout<<"Please input the new amount: ";
            cin>>amount;
            inventory[index].amount = amount;
            cout<<"Stock updated!";
            print_update_menu();
          }
        else if(choice==4)
          {
            cout<<"Please input the new price: ";
            cin>>price;
            inventory[index].price = price;
            cout<<"Price updated!";
            print_update_menu();
          }
        else if(choice==0)
            break;
      };
}

void delete_item(item inventory[], int &count, int index)
{
  count -=1;
  for(int i = index; i<count; i++)
      {
        inventory[index].key = inventory[index+1].key-1;
        inventory[index].name = inventory[index+1].name;
        inventory[index].manufacturer = inventory[index+1].manufacturer;
        inventory[index].amount = inventory[index+1].amount;
        inventory[index].price  = inventory[index+1].price;
        inventory[index].status = inventory[index+1].status;
      }
}
void insert(item inventory[], int &count)
{
  string name,man;
  int amount;
  double price;
  cout<<"Please input the details: NAME MANUFACTURER AMOUNT PRICE"<<endl;
  cin >> name>>man>>amount>>price;
  inventory[count].key = count+1;
  inventory[count].name = name;
  inventory[count].manufacturer = man;
  inventory[count].amount = amount;
  inventory[count].price  = price;
  inventory[count].status = 0;
  count +=1;

}
bool status_monitoring_system(int index, item inventory[]){
    if (inventory[index].amount <= 5){
        cout << inventory[index].name << "only has" << inventory[index].amount << "in stock now, it is time to re-stock!" << endl;
        return true;
    }
    else{
        return false;
    }
}

bool changing_status_system(int index, item inventory[]){
    if (inventory[index].amount == 0){
        inventory[index].status = false;
        cout << inventory[index].name << "is now inavailable" << endl;
        return true;
    }
    else{
        return false;
    }
}

void printing_array(int index, item inventory[]){
    cout << inventory[index].key <<" ";
    cout << inventory[index].name <<" ";
    cout << inventory[index].manufacturer <<" ";
    cout << inventory[index].amount <<" ";
    cout <<fixed<<setprecision(2)<< inventory[index].price <<" ";
    cout<<endl;

}



void search_in_stock(int array_size, item inventory[]){

    int i,found;
    int no_result_flag = 1;
    int n = 0;
    const int MAXSIZE = 100;
    item *sorted_inventory;
    sorted_inventory = new item[MAXSIZE];
    int action, product_choice, choice = 0;

    for (int i = 0; i < array_size; i++){
        if (!inventory[i].status){
          no_result_flag = 0;
          sorted_inventory[n].key = inventory[i].key;
          sorted_inventory[n].name = inventory[i].name;
          sorted_inventory[n].manufacturer = inventory[i].manufacturer;
          sorted_inventory[n].amount = inventory[i].amount;
          sorted_inventory[n].price  = inventory[i].price;
          sorted_inventory[n].status = inventory[i].status;
          n+=1;
        }
        }

    if(no_result_flag==0){
    sort_function(n,sorted_inventory);

    for(int m = 0; m<n ; m++)
        printing_array(m,sorted_inventory);

    cout<<"Input the key of your chosen product: ";
    cin>>product_choice;
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Delete commodity"<<endl;
    cout<<"2. Update commodity"<<endl;
    cin>>action;
    if(action==1)
        delete_item(inventory,array_size,product_choice-1);
    else if(action==2)
        update_item(inventory, product_choice-1);
    }
    else
      cout << "No results found! Returning to main menu"<<endl;
  }
void search_all(int array_size, item inventory[]){

    int i,found;
    int n = 0;
    const int MAXSIZE = 100;
    item *sorted_inventory;
    sorted_inventory = new item[MAXSIZE];
    int action, product_choice, choice = 0;

    for (int i = 0; i < array_size; i++){
          sorted_inventory[n].key = inventory[i].key;
          sorted_inventory[n].name = inventory[i].name;
          sorted_inventory[n].manufacturer = inventory[i].manufacturer;
          sorted_inventory[n].amount = inventory[i].amount;
          sorted_inventory[n].price  = inventory[i].price;
          sorted_inventory[n].status = inventory[i].status;
          n+=1;
        }

    sort_function(n,sorted_inventory);

    for(int m = 0; m<n ; m++)
        printing_array(m,sorted_inventory);

    cout<<"Input the key of your chosen product: ";
    cin>>product_choice;
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Delete commodity"<<endl;
    cout<<"2. Update commodity"<<endl;
    cin>>action;
    if(action==1)
        delete_item(inventory,array_size,product_choice-1);
    else if(action==2)
        update_item(inventory, product_choice-1);

    else
      cout << "No results found! Returning to main menu"<<endl;
  }
void search_out_of_stock(int array_size, item inventory[]){

    int i,found;
    int no_result_flag = 1;
    int n = 0;
    const int MAXSIZE = 100;
    item *sorted_inventory;
    sorted_inventory = new item[MAXSIZE];
    int action, product_choice, choice = 0;

    for (int i = 0; i < array_size; i++){
        if (inventory[i].status){
          no_result_flag = 0;
          sorted_inventory[n].key = inventory[i].key;
          sorted_inventory[n].name = inventory[i].name;
          sorted_inventory[n].manufacturer = inventory[i].manufacturer;
          sorted_inventory[n].amount = inventory[i].amount;
          sorted_inventory[n].price  = inventory[i].price;
          sorted_inventory[n].status = inventory[i].status;
          n+=1;
          }
        }
    if(no_result_flag==0){
    sort_function(n,sorted_inventory);

    for(int m = 0; m<n ; m++)
        printing_array(m,sorted_inventory);

    cout<<"Input the key of your chosen product: ";
    cin>>product_choice;
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Delete commodity"<<endl;
    cout<<"2. Update commodity"<<endl;
    cin>>action;
    if(action==1)
        delete_item(inventory,array_size,product_choice-1);
    else if(action==2)
        update_item(inventory, product_choice-1);
    }
    else
      cout << "No results found! Returning to main menu"<<endl;
  }

void search_by_product_name(int array_size, item inventory[]){

  int i,found;
  int no_result_flag = 1;
  int n = 0;
  const int MAXSIZE = 100;
  item *sorted_inventory;
  sorted_inventory = new item[MAXSIZE];

  string name_of_product;
  int action, product_choice, choice = 0;
  cout << "Input the name of product: ";
  cin >> name_of_product;
  for(i = 0; i<array_size; i++)
      {
        found = (inventory[i].name).find(name_of_product);
        if(found!=string::npos)
            {
              no_result_flag = 0;
              sorted_inventory[n].key = inventory[i].key;
              sorted_inventory[n].name = inventory[i].name;
              sorted_inventory[n].manufacturer = inventory[i].manufacturer;
              sorted_inventory[n].amount = inventory[i].amount;
              sorted_inventory[n].price  = inventory[i].price;
              sorted_inventory[n].status = inventory[i].status;
              n+=1;
            }
      }
  if(no_result_flag==0){
      sort_function(n,sorted_inventory);

      for(int m = 0; m<n ; m++)
          printing_array(m,sorted_inventory);

      cout<<"Input the key of your chosen product: ";
      cin>>product_choice;
      cout<<"What do you want to do?"<<endl;
      cout<<"1. Delete commodity"<<endl;
      cout<<"2. Update commodity"<<endl;
      cin>>action;
      if(action==1)
          delete_item(inventory,array_size,product_choice-1);
      else if(action==2)
          update_item(inventory, product_choice-1);
  }
  else
      cout << "No results found! Returning to main menu"<<endl;
  }

void search_by_manufacturer(int array_size, item inventory[]){
    int i,found;
    int no_result_flag = 1;
    int n = 0;
    const int MAXSIZE = 100;
    item *sorted_inventory;
    sorted_inventory = new item[MAXSIZE];

    string name_of_manufacturer;
    int action, product_choice, choice = 0;
    cout << "Input the name of manufacturer: ";
    cin >> name_of_manufacturer;
    for(i = 0; i<array_size; i++)
        {
          found = (inventory[i].manufacturer).find(name_of_manufacturer);
          if(found!=string::npos)
              {
                no_result_flag = 0;
                sorted_inventory[n].key = inventory[i].key;
                sorted_inventory[n].name = inventory[i].name;
                sorted_inventory[n].manufacturer = inventory[i].manufacturer;
                sorted_inventory[n].amount = inventory[i].amount;
                sorted_inventory[n].price  = inventory[i].price;
                sorted_inventory[n].status = inventory[i].status;
                n+=1;
              }
        }

    if(no_result_flag==0){
    sort_function(n,sorted_inventory);

    for(int m = 0; m<n ; m++)
        printing_array(m,sorted_inventory);

    cout<<"Input the key of your chosen product: ";
    cin>>product_choice;
    cout<<"What do you want to do?"<<endl;
    cout<<"1. Delete commodity"<<endl;
    cout<<"2. Update commodity"<<endl;
    cin>>action;
    if(action==1)
        delete_item(inventory,array_size,product_choice-1);
    else if(action==2)
        update_item(inventory, product_choice-1);
    }
    else
      cout << "No results found! Returning to main menu"<<endl;

}



void search_function(int array_size, item inventory[]){
    int num_1;
    cout << "Please choose which filter would you like to use:" << endl;
    cout << "1) in-stock " << endl;
    cout << "2) out-of-stock " << endl;
    cout << "3) product name " << endl;
    cout << "4) manufacturer " << endl;
    cout << "5) no filter"     << endl;
    cout << "Or enter any other number to return to main menu."<< endl;
    cout << "Your choice: ";
    cin >> num_1;
    if(num_1 == 1){
        search_in_stock(array_size, inventory);
    }
    else if(num_1 == 2){
        search_out_of_stock(array_size, inventory);
    }
    else if(num_1 == 3){
        search_by_product_name(array_size, inventory);
    }
    else if(num_1 == 4){
        search_by_manufacturer(array_size, inventory);
    }
    else if(num_1 == 5){
        search_all(array_size, inventory);
    }
    }

void print_menu()
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
bool inventory_status_monitor(){
    return false;
}

int main()
{
  string line;
  int count = 0;  //stores the number of items in inventory
  const int MAXSIZE = 100;
  item *inventory;
  inventory = new item[MAXSIZE];

  ifstream fin("Store1.txt");
  if (fin.fail())
  {
    cout<< "Can't open file"<<endl;
    exit(1);
  }

  while(getline(fin,line))
    {
      istringstream x(line);
      x>>inventory[count].key;
      x>>inventory[count].name;
      x>>inventory[count].manufacturer;
      x>>inventory[count].amount;
      x>>inventory[count].price;
      x>>inventory[count].status;

      count +=1;

    }


    int action, product_choice, choice = 0;
    cout << "Welcome! There are " << count << " items in the warehouse, please choose a function. " << endl;
    cout << "1) Search commodity according to different filters and update/delete it. " << endl;
    cout << "2) Insert new commodity. " << endl;
    cout << "3) Exit. "<<endl;
    cout << "Your choice: ";
    cin >> choice;
    while (choice != 3){

        if (choice == 1){
            search_function(count, inventory);
            print_menu();
            cin>>choice;
        }
        else if (choice == 2){
            insert(inventory, count);
            cout<<"Item added!";
            print_menu();
            cin>>choice;
        }

        else{

            cout << "Invalid input, please try again: ";
            cin>>choice;
            }
        }
    return 0;
}
