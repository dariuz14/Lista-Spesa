//
// Created by Dario Mezzasalma on 31/03/2023.
//

#ifndef LISTASPESA_SHOPPINGLIST_H
#define LISTASPESA_SHOPPINGLIST_H

#include "Subject.h"
#include "Product.h"
#include <list>
#include <map>
#include <memory>

using namespace std;

class ShoppingList: public Subject{
public:
    ShoppingList(const string& shoppingListName): listName(shoppingListName){}

    ~ShoppingList() override = default;

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notifyObservers() override;

    void addProduct(const Product& product);
    void removeProduct(const string& name);
    void setBought(const string& name);
    int countNotBought() const;
    void printNotBought() const;
    void printList();

    const string &getListName() const {
        return ShoppingList::listName;
    }

    void setListName(const string& name) {
        ShoppingList::listName = name;
    }

    const map<string, shared_ptr<Product>> &getShoppingList() const {
        return shoppingList;
    }

    const list<Observer *> & getObservers() const{
        return observers;
    }

    const map<string, int> &getCategories() const {
        return categories;
    }

private:
    std::string listName;
    map<string, int> categories;
    map<string, shared_ptr<Product>> shoppingList;
    list<Observer*> observers;
};

#endif //LISTASPESA_SHOPPINGLIST_H