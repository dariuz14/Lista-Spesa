//
// Created by Dario Mezzasalma on 25/03/2023.
//

#include "User.h"
#include <stdexcept>
#include <iostream>

void User::addShoppingList(ShoppingList &shoppingList) {
    auto sListPtr = make_shared<ShoppingList>(shoppingList);
    myLists.insert(make_pair(shoppingList.getListName(),sListPtr));
    shoppingList.subscribe(this);
}

void User::removeShoppingList(const string &name) {
    auto itr = myLists.find(name);
    if(itr == myLists.end()){
        throw invalid_argument("listaspesa with this name is not found");
    }
    else{
        itr->second->unsubscribe(this);
        myLists.erase(name);
    }
}

void User::update(const string &listName) {
    auto itr = myLists.find(listName);
    cout <<"List: " << listName << " updated " << endl;
    cout << endl;
    itr->second->printNotBought();
}

const map<string, shared_ptr<ShoppingList>>& User::getMyLists() const {
    return myLists;
}
