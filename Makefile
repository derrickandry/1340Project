main.o:main.cpp functions.h
  g++ -c main.cpp

printing_functions.o:printing_functions.cpp functions.h
  g++ -c printing_functions.cpp

sorting.o:sorting_functions.cpp functions.h
  g++ -c sorting_functions.cpp

features.o:features.cpp functions.h
  g++ -c features.cpp

main:main.o printing_functions.o sorting.o features.o
