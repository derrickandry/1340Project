#include "functions.h"


using namespace std;

int main()
{
  int store;
  int found;
  found = user_login();
  while(true)
  {
      if(found==1)
          break;
      cout<<"Login failed, please try again:"<<endl;
      found=user_login();
  }
  string line;
  int count = 0;  //stores the number of items in inventory
  const int MAXSIZE = 100;
  item *inventory;
  inventory = new item[MAXSIZE];
  cout<<"Welcome! Please input the Store Number(1-3):";
  cin>>store;
  while(!(store<=3 ||store>=1))
      {
        cout<<"Invalid input. Please try again!";
        cin>>store;
      }
  ifstream fin;
  if(store==1)
      fin.open("Store1.txt");
  else if(store==2)
      fin.open("Store2.txt");
  else if(store==3)
      fin.open("Store3.txt");
  else
      {
        cout<<"Invalid input. Exiting program.";
        exit(1);
      }
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
    cout << "Welcome! There are " << count << " items in Store "<< store<<", please choose a function. " << endl;
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
