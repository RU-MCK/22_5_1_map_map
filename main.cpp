#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<std::string, std::string> phoneBook;
  std::multimap<std::string, std::string> lastnameBook;
  std::multimap<std::string, std::string>::iterator it;

  int command = 5;
  do {
    std::cout << "Add the phone number and last name of the subscriber to the directory enter-< 1 > " << std::endl
              << "Find out the name of the subscriber by phone number enter-------------------< 2 > " << std::endl
              << "Find out the phone number of the subscriber by last name--------------------< 3 > " << std::endl
              << "For print Phone Book enter--------------------------------------------------< 4 > " << std::endl
              << "For exit enter--------------------------------------------------------------< 0 > " << std::endl;
    std::cin >> command;
    std::string lastname;
    std::string number;
    switch (command) {
      case 0:std::cout << "Exit";
        break;
      case 1:std::cout << "Enter phone number <99-99-99> :" << std::endl;
        std::cin >> number;
        std::cout << "Enter last name:" << std::endl;
        std::cin >> lastname;
        lastnameBook.emplace(lastname, number);
        phoneBook.emplace(number, lastname);
        break;
      case 2:std::cout << "Enter phone number <99-99-99> :" << std::endl;
        std::cin >> number;
        std::cout << phoneBook[number] << std::endl;
        break;
      case 3:std::cout << "Enter last name:" << std::endl;
        std::cin >> lastname;
        it = lastnameBook.find(lastname);
        for (; it != lastnameBook.end(); ++it)
          std::cout << it->second << std::endl;
        break;
      case 4:
        if (!phoneBook.empty()) {
          for (auto &item : phoneBook)
            std::cout << item.first << " " << item.second << std::endl;
        } else
          std::cout << "Phone book is empty!" << std::endl;
        break;
      default:std::cout << "Enter error!" << std::endl;
        break;
    }
  } while (command != 0);
  return 0;
}
