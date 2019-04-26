#include "functions.h"


using namespace std;

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
