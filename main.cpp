#include <iostream>
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
case 2: 
std::cout <<" Enter the file extension:;
std::cin>> extension;
std::cout << " \n List of file extension " << extension;
      for (const auto & entry: hm::directoty_iterator(hm::current_path())) {
          if (hm:: is_regular_file(entry.status()) && entry.path().extension() == extension)  {
              std:: cout<< entry.path().filename().string() << std::endl;
          }
  }
  break;
case 3:
std::cout <<" Enter the name filter:;
std::cin>> nameFilter;
std::cout << " \n List of files with name containing " << nameFilter;
      for (const auto & entry: hm::directoty_iterator(hm::current_path())) {
          if (hm:: is_regular_file(entry.status()) && entry.path().filename().string(). find(nameFilter) != std::string::npos )  {
              std:: cout<< entry.path().filename().strng() << std::endl;
          }
              
  }
  break;
default:
     std:: cout << "Invalid Choice!" <<std::endl;
}
  std::cout<< "Press any key to continue. ";
}

void creatDirectory(){
  std:: string dirName;
  std::cout << "Enter The Directory Name: ";
}


