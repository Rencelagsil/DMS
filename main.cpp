#include <iostream>
#include <string>
#include <filesystem>

namespace hm = std:: filesystem;

void displayMenu();
void displayFiles();
void createDirectory();
void changeDirectory();

int main()
{
  int choice;
  do {
    displayMenu();
    std::cin >>choice;
    switch(choice) {
      case 1:
      displayFiles();
      break;
      case 2:
      createDirectory();
      break;
      case 3:
      changeDirectory();
      break;
      case 4:
        std::cout << "Exiting the program." << std::endl;
      break;
    }
    std::cin.ignore();
    std::cin.get();
    
  } while (choice!= 4);
  
    return 0;
}

void displayMenu(){
  std::cout<<"\n MAIN MENU \n";
  std::cout<<"1. To Display List of Files \n";
  std::cout<<"2. To Create New Directory \n";
  std::cout<<"3. To Change The Working Directory \n";
  std::cout<<"4. Exit \n";
  
}

void displayFiles(){
  int choice1;
  std::string extension, nameFilter;

  std::cout << "\nLIST FILES DETAIL\n";
  std::cout << "1. List All Files\n";
  std::cout << "2. List Of Extension Files\n";
  std::cout << "3. List Of Name Wise\n";
  std::cout << choice1;

  switch (choice1) {
    case 1:
    std::cout <<"\n List Of All Files: \n;
      for (const auto & entry: hm::directoty_iterator(hm::current_path())) {
          if (hm:: is_regular_file(entry.status())) {
              std:: cout<< entry.path().filename().string() << std::endl;
      }
      }
break;

  }
}
