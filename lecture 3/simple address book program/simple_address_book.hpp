
#include <iostream>
#include <vector>
#include <string>


struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string email;

    
    void display() const  {
        std::cout << "Name: " << name << "\n";
        std::cout << "Phone Number: " << phoneNumber << "\n";
        std::cout << "Email: " << email << "\n";
    }
};


void addContact(std::vector<Contact>& contacts);
void updateContact(std::vector<Contact>& contacts);
void listContacts(  std::vector<Contact>& contacts);
void deleteContact(std::vector<Contact>& contacts);
void deleteAllContacts(std::vector<Contact>& contacts);
void searchContact( std::vector<Contact>& contacts);
void menu();