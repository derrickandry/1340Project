#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

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
    cout << inventory[index].price <<" ";
    cout<<endl;
}


// passing an array of struct
void search_function(int array_size, item inventory[]){
    int num_1;
    cout << "Please choose which filter would you like to use:" << endl;
    cout << "1) in-stock " << endl;
    cout << "2) out-of-stock " << endl;
    cout << "3) product name " << endl;
    cout << "4) manufacturer " << endl;
    cin >> num_1;
    if(num_1 == 1){
        for (int i = 0; i < array_size; i++){
            if (!inventory[i].status){
                printing_array(i, inventory);
            }
        }
    }
    else if(num_1 == 2){
        for (int i = 0; i < array_size; i++){
            if (inventory[i].status){
                printing_array(i, inventory);
            }
        }
    }
    else if(num_1 == 3){
        int found;
        string search_name;
        cout<<"Input search querry:";
        cin>>search_name;
        for(int i = 0; i<array_size; i++)
            {
              found = inventory[i].name.find(search_name);
              if(found!=std::string::npos)
                  {
                    printing_array(i, inventory);
                  }
            }
    }
    else{
        string name_of_manufacturner;
        cout << "Please type the name of the : ";
        cin >> name_of_manufacturner;
        for (int i = 0; i < array_size; i++){
            if (name_of_manufacturner == inventory[i].manufacturer){
                printing_array(i, inventory);
            }
        }
    }
}
void print_menu()
{
  cout<< "-------------------------------------------------------------"<<endl;
  cout << "1) Search commodity according to different filters. " << endl;
  cout << "2) Insert new commodity. " << endl;
  cout << "3) Delete obsolete commodity. " << endl;
  cout << "4) Update commodity information. " << endl;
  cout << "5) Exit. "<<endl;
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
    cout << "1) Search commodity according to different filters. " << endl;
    cout << "2) Insert new commodity. " << endl;
    cout << "3) Delete obsolete commodity. " << endl;
    cout << "4) Update commodity information. " << endl;
    cout << "5) Exit. "<<endl;
    cout << "Your choice: ";
    cin >> choice;
    while (choice != 5){

        if (choice == 1){
            search_function(count, inventory);
            cout<<"Input the key of your chosen product: ";
            cin>>product_choice;
            cout<<"What do you want to do?"<<endl;
            cout<<"1. Delete commodity"<<endl;
            cout<<"2. Update commodity"<<endl;
            cin>>action;
            if(action==1)
                delete_item(product_choice-1,inventory);
            else if(action==2)
                update_item(product_choice-1,inventory);
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

        }
    }

    return 0;
}
