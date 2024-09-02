#include <iostream>
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
    std::cin.ignore();
    
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
      default:
      std::cout << "Invalid choice! Please try again." << std::endl;
    }
    std::cout << "Press Enter to continue...";
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
  std::cin.ignore();

  switch (choice1) {
        case 1:
            std::cout << "\nList of All Files:\n";
            for (const auto& entry : hm::directory_iterator(hm::current_path())) {
                std::cout << (hm::is_directory(entry.status()) ? "[DIR] " : "[FILE] ")
                          << entry.path().filename().string() << std::endl;
            }
            break;
        case 2:
            std::cout << "Enter the file extension: ";
            std::cin >> extension;
            std::cout << "\nList of Files with Extension " << extension << ":\n";
            for (const auto& entry : hm::directory_iterator(hm::current_path())) {
                if (hm::is_regular_file(entry.status()) && entry.path().extension() == extension) {
                    std::cout << entry.path().filename().string() << std::endl;
                }
            }
            break;
        case 3:
            std::cout << "Enter the name filter: ";
            std::cin >> nameFilter;
            std::cout << "\nList of Files with Name Containing '" << nameFilter << "':\n";
            for (const auto& entry : hm::directory_iterator(hm::current_path())) {
                if (hm::is_regular_file(entry.status()) && entry.path().filename().string().find(nameFilter) != std::string::npos) {
                    std::cout << entry.path().filename().string() << std::endl;
                }
            }
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
    }
}


void createDirectory() {
    std::string dirName;
    std::cout << "Enter the Directory name: ";
    std::cin >> dirName;

    if (hm::create_directory(dirName)) {
        std::cout << dirName << " Directory Successfully Created." << std::endl;
    } else {
        std::cout << "Failed to create directory. It may already exist or you don't have permission." << std::endl;
}
}

void changeDirectory() {
   int choice2;
    std::string dirName;
    hm::path currentDir = hm::current_path();

    std::cout << "Current Directory: " << currentDir.string() << std::endl;
    std::cout << "\nChange Directory\n";
    std::cout << "1. Step by Step Backward\n";
    std::cout << "2. Goto Root Directory\n";
    std::cout << "3. Forward Directory\n";
    std::cout << "Enter the Number: ";
    std::cin >> choice2;

    switch(choice2) {

   case 1:
      if (currentDir.has_parent_path()) {
          hm::current_path(currentDir.parent_path());
            std::cout << "Moved one directory back to: " << hm::current_path().string() << std::endl;
      } else {
       std::cout << "Already at the root directory." << std::endl;
      }
      break;

   case 2:
      hm::current_path(currentDir.root_path());
        std::cout << "Moved to root directory: " << hm::current_path().string() << std::endl;
      break;

    case 3:
      std::cout << "Please enter the Directory Name: ";
      std::cin >> dirName;
        if (hm::exists(dirName) && hm::is_directory(dirName)) {
             hm::current_path(dirName);
              std::cout << "Moved to directory: " << hm::current_path().string() << std::endl;
        } else {
            std::cout << "Directory does not exist." << std::endl;
          }
        break;

  default:
      std::cout << "Invalid choice!" << std::endl;
}
   
    std::cout << "Press any to continue.";
}
