#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "simple_address_book.hpp"

int main() {
    std::vector<Contact> contacts;
    int choice;

    do {
        menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice; 

        switch (choice) {
            case 1: addContact(contacts); break;
            case 2: updateContact(contacts); break;
            case 3: listContacts(contacts); break;
            case 4: deleteContact(contacts); break;
            case 5: deleteAllContacts(contacts); break;
            case 6: searchContact(contacts); break;
            case 7: std::cout << "Exiting program.\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 7);

    return 0;
}

void menu() {
    std::cout << "\nAddress Book Menu:\n";
    std::cout << "1. Add Contact\n";
    std::cout << "2. Update Contact\n";
    std::cout << "3. List Contacts\n";
    std::cout << "4. Delete Contact\n";
    std::cout << "5. Delete All Contacts\n";
    std::cout << "6. Search Contact\n";
    std::cout << "7. Exit\n"<<std::endl;
}

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std:: cout<<"----> dont use space between names ^_^ "<<std::endl;
    std::cout << "Enter name: ";
    std::cin>>newContact.name;

    std::cout << "Enter phone number: ";
    std::cin>>newContact.phoneNumber;
 
    std::cout << "Enter email: ";
    std::cin>>newContact.email;

    contacts.push_back(newContact);
    std::cout << "Contact added successfully.\n";
}

void updateContact(std::vector<Contact>& contacts) {
    std::string name;
    std::fflush(stdin);
    std::cout << "Enter the name of the contact to update: ";
    std::fflush(stdin);
    std::cin>>name;
    std::fflush(stdin);
    auto i = std::find_if(contacts.begin(), contacts.end(), [&name]( Contact& c) {
        return c.name == name;
    });

    if (i != contacts.end()) {
        std::cout << "Updating contact...:\n";
        std::cout << "Enter new phone number: ";
     
        std::cin>>(i->phoneNumber);
        std::cout << "Enter new email: ";
    
       std::cin>>(i->email);
        std::cout << "Contact updated successfully.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

void listContacts(  std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts to display.\n";
    } else {
        std::cout << "Contacts:\n";
        for (auto& contact : contacts) {
            contact.display();
            std::cout << "---------------------\n";
        }
    }
}

void deleteContact(std::vector<Contact>& contacts) {
    std::string name;
    std::fflush(stdin);
    std::cout << "Enter the name of the contact to delete: ";
    std::fflush(stdin);
    std::cin>>name;
    std::fflush(stdin);

    auto i = std::remove_if(contacts.begin(), contacts.end(), [&name]( Contact& c) {
        return c.name == name;
    });

    if (i != contacts.end()) {
        contacts.erase(i, contacts.end());
        std::cout << "Contact deleted successfully.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

void deleteAllContacts(std::vector<Contact>& contacts) {
    contacts.clear();
    std::cout << "All contacts deleted successfully.\n";
}

void searchContact( std::vector<Contact>& contacts) {
    std::string name;
    std::fflush(stdin);
    std::cout << "Enter the name of the contact to search: ";
    std::fflush(stdin);
    std::cin>>name;
    std::fflush(stdin);

    auto i = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
        return c.name == name;
    });

    if (i != contacts.end()) {
        std::cout << "Contact found:\n";
        i->display();
    } else {
        std::cout << "Contact not found.\n";
    }
}
