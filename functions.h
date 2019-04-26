
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#ifndef ABC
#define ABC


  const int MAXSIZE = 100;


  struct item
  {
      int key;
      std::string name;
      std::string manufacturer;
      int amount;
      double price;
      bool status;
  };

  void search_function(int , item []);
  void print_menu();
  void printing_array(int a , item b[]);
  void print_update_menu();
  bool compare_manufacturer(item a, item b);
  bool compare_amount(item a, item b) ;
  bool compare_price(item a, item b) ;
  bool compare_name(item a, item b);
  void sort_function(int a, item b[]);
  void update_item(item a[] , int b);
  void delete_item(item a[], int &b, int c);
  void insert(item i[] , int &a );
  bool status_monitoring_system(int index, item i[] );
  bool changing_status_system(int index , item i[] );
  void search_in_stock(int a, item i[]);
  void search_all(int a, item i[]);
  void search_out_of_stock(int a, item i[]);
  void search_by_product_name(int a, item i[]);
  void search_by_manufacturer(int a, item i[]);
  void search_function(int a, item i[]);

#endif
