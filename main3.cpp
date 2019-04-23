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
    string name;
    string manufacturer;
    int amount;
    double price;
    bool status;
};

bool status_monitoring_system(int index, item * input_array){
    if (input_array[index].amount <= 5){
        cout << input_array[index].name << "only has" << input_array[index].amount << "in stock now, it is time to re-stock!" << endl;
        return true;
    }
    else{
        return false;
    }
}

bool changing_status_system(int index, item *& input_array){
    if (*input_array[index].amount == 0){
        *input_array[index].status = false;
        cout << input_array[index].name << "is now inavailable" << endl;
    }
    else{
        return false;
    }
}

int initiating_an_array(item *& input_array){
    string line;
    int count = 0;
    ifstream fin("Store1.txt");
    if (fin.fail())
    {
        cout<< "Can't open file"<<endl;
        exit(1);
    }

    while(getline(fin,line))
    {
        istringstream x(line);
        x>>*input_array[count].name;
        x>>*input_array[count].manufacturer;
        x>>*input_array[count].amount;
        x>>*input_array[count].price;
        x>>*input_array[count].status;
        count +=1;
    }
    return count+1;
}

void pringting_array(int index, item * input_array){
    cout << *input_array[index].name << endl;
    cout << *input_array[index].manufacturer << endl;
    cout << *input_array[index].amount << endl;
    cout << *input_array[index].price << endl;
}


// passing an array of struct
void search_function(int array_size,item * input_array){
    int num_1;
    cout << "Please choose which filter would you like to use:" << endl;
    cout << "1) in-stock " << endl;
    cout << "2) out-of-stock " << endl;
    cout << "3) product name " << endl;
    cout << "4) manufacturer " << endl;
    cin >> num_1;
    if(num_1 == 1){
        for (int i = 0; i < array_size; i++){
            if (items[i].status){
                printing_array(i, input_array);
            }
        }
    }
    else if(num_1 == 2){
        for (int i = 0; i < array_size; i++){
            if (!items[i].status){
                printing_array(i, input_array);
            }
        }
    }
    else if(num_1 == 3){
        string name_of_product;
        cout << "Please type the name of the product: ";
        cin >> name_of_product;
        for (int i = 0; i < array_size; i++){
            if (name == input_array[i].name){
                printing_array(i, input_array);
            }
        }
    }
    else{
        string name_of_manufacturner;
        cout << "Please type the name of the : ";
        cin >> name_of_manufacturner;
        for (int i = 0; i < array_size; i++){
            if (name_of_manufacturner == input_array[i].manufacturer){
                printing_array(i, input_array);
            }
        }
    }
}

bool inventory_status_monitor(){
    return false;
}

int main()
{
    item *inventory;
    inventory = new items[MAXSIZE];
    int choice = 0, total_number_of_items = initiating_an_array(inventory);
    while (choice != 5){
        cout << "Welcome! There are" << total_number_of_items << "items in the warehouse, please choose a function. " << endl;
        cout << "1) Search commodity according to different filters. " << endl;
        cout << "2) Insert new commodity. " << endl;
        cout << "3) Delete obsolete commodity. " << endl;
        cout << "4) Update commodity information. " << endl;
        cout << "5) Exit. ";
        cout << "Your choice: ";
        if (choice == 1){
            searching_function();
            cin >> choice;
        }
        else if (choice == 2){

            cin >> choice;
        }
        else if (choice == 3){

            cin >> choice;
        }
        else if (choice == 4){

            cin >> choice;
        }
        else{
            cout << "Invalid input, please try again: ";
            cin >> choice;
        }
    }
    return 0;
}
