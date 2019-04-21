#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct item
{

    string name;
    string manufacturer;
    int amount;
    double price;
    bool status;

  };

int main()
{
  string line;
  int count = 0;
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
      x>>inventory[count].name;
      x>>inventory[count].manufacturer;
      x>>inventory[count].amount;
      x>>inventory[count].price;
      x>>inventory[count].status;

      count +=1;

    }

}
