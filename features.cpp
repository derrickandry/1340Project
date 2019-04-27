#include "functions.h"
using namespace std;


int user_login()                        //function for logging in the menu
{
  string username, password;
  int counter = 0;
  int found = 0;
  string x;
  string details[10][2];

  ifstream fin("login_details.txt");
  if (fin.fail())
  {
    cout<< "Can't open file"<<endl;
    exit(1);
  }

  while(fin>>x)
  {
    details[counter][0] = x;
    fin>>x;
    details[counter][1] = x;
    counter+=1;
  }

  cout<<"Enter Username:";
  cin>>username;
  cout<<"Enter Password:";
  cin>>password;

  for(int i =0;i<10;i++)
      {
        if(details[i][0]==username && details[i][1]==password)
            {
              found==1;
              cout<<"Login Successful!"<<endl;
              return 1;
            }
      }
  return 0;

}

void update_item(item inventory[], int index) // A function allowing users tp update the infomation of item
{                                             // inventory: An array of struct storing the information of items in that store
  string name, man;                           // index: The key of product to be updated
  int amount;
  double price;
  int choice;
  print_update_menu();
  while(choice!=0)
      {
        cin>>choice;
        if(choice==1)
          {
            cout<<"Please input the new name: "; // Update the name.
            cin>>name;
            inventory[index].name = name;
            cout<<"Name updated!";
            cout<<endl;
            print_update_menu();
          }
        else if(choice==2) // Update the manufacturer.
          {
            cout<<"Please input the new manufacturer: ";
            cin>>man;
            inventory[index].manufacturer = man;
            cout<<"Manufacturer updated!";
            print_update_menu();
          }
        else if(choice==3) // Update the Stock.
          {
            cout<<"Please input the new amount: ";
            cin>>amount;
            inventory[index].amount = amount;
            cout<<"Stock updated!";
            print_update_menu();
          }
        else if(choice==4) // Update the price
          {
            cout<<"Please input the new price: ";
            cin>>price;
            inventory[index].price = price;
            cout<<"Price updated!";
            print_update_menu();
          }
        else if(choice==0) // Exit
            break;
      };
}

void delete_item(item inventory[], int &count, int index) // A function allowing users to delete an item from the inventory system
{                                                         // Input:
  count -=1;                                              // inventory[]: An array of struct storing the information of items in that store
  for(int i = index; i<count; i++)                        // index: The key for the product to be deleted (Will be shown after sorting function)    
      {
        inventory[index].key = inventory[index+1].key-1;
        inventory[index].name = inventory[index+1].name;
        inventory[index].manufacturer = inventory[index+1].manufacturer;
        inventory[index].amount = inventory[index+1].amount;
        inventory[index].price  = inventory[index+1].price;
        inventory[index].status = inventory[index+1].status;
      }
}

void insert(item inventory[], int &count)                 // A function allowing users to add one more item from the inventory system  
{                                                         // Input: An array of struct storing the information of items in that store
  string name,man;                                        // count: The number of product in that store
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
bool status_monitoring_system(int index, item inventory[]){ // A function monitoring the stocks in inventory, it will be excuted after the user 
    if (inventory[index].amount <= 5){                      // runs the programming or make an ajustment to the stock, and reminds user to restock
                                                            // if the amount of that item is less than 5.
        cout << inventory[index].name << " only has " << inventory[index].amount << " in stock now, it is time to re-stock!" << endl;
        return true;
    }
    else{
        return false;
    }
}

bool changing_status_system(int index, item inventory[]){ // A function monitoring the availability of that product, it will be excuted after the user
    if (inventory[index].amount == 0){                    // runs the programming or make an ajustment to the stock.
        inventory[index].status = false;
        cout << inventory[index].name << " is now inavailable." << endl;
        return true;
    }
    else{
        return false;
    }
}



void search_in_stock(int array_size, item inventory[]){ // A function allowing the user to search available items
    int i,found;                                        // array_size: number of items in that store
    int no_result_flag = 1;                             // inventory[]: An array of struct storing the information of items in that store
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
void search_out_of_stock(int array_size, item inventory[]){  // A function allowing user to search unavailable product
    int i,found;                                             // array_size: number of items in that store
    int no_result_flag = 1;                                  // inventory[]: An array of struct storing the information of items in that store
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

void search_by_product_name(int array_size, item inventory[]){ // A function allowing user to serach by product name
  int i,found;                                                 // array_size: number of items in that store
  int no_result_flag = 1;                                      // inventory[]: An array of struct storing the information of items in that store
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



void search_function(int array_size, item inventory[]){  // A function allowing user to serach by product name
    int num_1;                                           // array_size: number of items in that store
    cout << "Please choose which filter would you like to use:" << endl; 
    cout << "1) in-stock " << endl;                      // // inventory[]: An array of struct storing the information of items in that store
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
