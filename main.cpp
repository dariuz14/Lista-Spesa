#include <iostream>
#include "User.h"
#include "ShoppingList.h"
#include "Product.h"

using namespace std;
int main() {

    bool create = true;
    int choice;
    map<string, User> users;
    map<string, Product> products;
    map<string, ShoppingList> shoppingLists;

    cout << "Create the shopping list: " << endl;

    while(create){
        cout << "Choose 1 if you want to create a shopping list, 2 otherwise: " << endl;
        cin >> choice;

        switch(choice){
            case 1:{
                string shoppingListName;
                cout << "Insert shopping list name: " << endl;
                cin >> shoppingListName;
                ShoppingList s(shoppingListName);
                shoppingLists.insert(make_pair(shoppingListName, s));
                break;
            }
            case 2:{
                create = false;
                break;
            }
            default:
                break;
        }
    }

    cout << "Create the products: " << endl;
    create = true;

    while(create){
        cout << "Insert 1 if you want to create a new product, otherwise 2: "<< endl;
        cin >> choice;

        switch(choice){
            case 1:{
                string productName;
                int quantity;
                string category;
                cout << "Insert name of the product, its quantity and its category: " << endl;
                cin >> productName;
                cin >> quantity;
                cin >> category;
                try{
                    if(quantity <= 0){
                        throw invalid_argument("Quantity can't to be less or equal than 0");
                    }
                    else {
                        Product p(productName, category, quantity);
                        products.insert(make_pair(productName, p));
                    }
                }catch(std::invalid_argument& e){
                    cerr << e.what() << endl;
                }

                break;
            }
            case 2:
                create = false;
                break;
            default:
                break;
        }
    }

    cout << endl;
    cout << "Create the users: " << endl;
    create = true;

    while(create){
        cout << "Insert 1 if you want to create a new user, 2 otherwise: " << endl;
        cin >> choice;
        switch(choice){
            case 1:{
                string userName;
                cout << "Insert the name of the user: " << endl;
                cin >> userName;
                User u;
                users.insert(make_pair(userName, u));
                break;
            }
            case 2:
                create = false;
                break;
            default:
                break;
        }
    }

    bool operations = true;
    while(operations){
        cout << endl;
        cout << "The operations are: " << endl << "1- Add a product to list" << endl << "2-Remove product from a list" << endl;
        cout << "3- Mark a product as bought" << endl << "4- Add a shopping list to a user's shopping lists" << endl;
        cout << "5- Remove a shopping list by a user's shopping lists" << endl << "6- Display shopping list of a user" << endl;
        cout << "7- Nothing" << endl;
        cin >> choice;

        switch(choice) {
            case 1: {
                string productName;
                string listName;
                cout << "Insert the name of the product and the name of the list to insert" << endl;
                cin >> productName;
                cin >> listName;
                auto itrL = shoppingLists.find(listName);
                auto itrP = products.find(productName);
                try{
                    if(itrL == shoppingLists.end() || itrP == products.end())
                        throw invalid_argument("List name or product name not valid");
                    else{
                        itrL->second.addProduct(itrP->second);
                    }
                }
                catch(std::invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 2: {
                string productName;
                string listName;
                cout << "Insert the name of the product that you want to remove and his name list" << endl;
                cin >> productName;
                cin >> listName;
                auto itrP = products.find(productName);
                auto itrL = shoppingLists.find(listName);
                try{
                    if(itrP == products.end() || itrL == shoppingLists.end()){
                        throw invalid_argument("Product name or shopping list name not valid");
                    }
                    else{
                        itrL->second.removeProduct(productName);
                    }
                }catch(std::invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 3:{
                string productName;
                cout << "Insert the name of the product that you want to mark as bought" << endl;
                cin >> productName;
                auto itrP = products.find(productName);
                try{
                    if(itrP == products.end()){
                        throw invalid_argument("Product name not valid");
                    }
                    else{
                        itrP->second.setProductBought(true);
                    }
                }catch(std::invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 4: {
                string userName;
                string listName;
                cout << "Insert the name of the user and the name of the list to add" << endl;
                cin >> userName;
                cin >> listName;
                auto itrL = shoppingLists.find(listName);
                auto itrU = users.find(userName);
                try{
                    if(itrL == shoppingLists.end() || itrU == users.end())
                        throw invalid_argument("List name or user name not valid");
                    else{
                        itrU->second.addShoppingList(itrL->second);
                    }
                }
                catch(std:: invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 5: {
                string userName;
                string listName;
                cout << "Insert the name of the user and the name of the list to remove" << endl;
                cin >> userName;
                cin >> listName;
                auto itrL = shoppingLists.find(listName);
                auto itrU = users.find(userName);
                try{
                    if(itrL == shoppingLists.end() || itrU == users.end())
                        throw invalid_argument("List name or user name not valid");
                    else{
                        itrU->second.removeShoppingList(listName);
                    }
                }
                catch(std:: invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 6: {
                string userName;
                string listName;
                cout << "Insert the name of the user and his shopping list name to display" << endl;
                cin >> userName;
                cin >> listName;
                auto itrU = users.find(userName);
                auto itrL = shoppingLists.find(listName);
                try{
                    if(itrU == users.end() || itrL == shoppingLists.end()) {
                        throw invalid_argument("List name or user name not valid");
                    }
                    else if(itrU->second.hasList(listName)){
                        itrL->second.printList();
                    }
                    else{
                        cout << "This user has not this shopping list" << endl;
                    }
                }
                catch(std:: invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            }
            case 7: {
                operations = false;
                break;
            }
            default: {
                operations = false;
                break;
            }
        }
    }


    return 0;
}