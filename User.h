//
// Created by Dario Mezzasalma on 25/03/2023.
//

#ifndef LISTASPESA_USER_H
#define LISTASPESA_USER_H

#include "ShoppingList.h"
#include "Observer.h"
#include <algorithm>
#include <memory>


using namespace std;

class User: public Observer{
public:
    virtual ~User(){
        for(auto &itr:myLists){
            itr.second->unsubscribe(this);
        }
    }
    void update(const string& listName) override;
    void addShoppingList(ShoppingList& shoppingList);
    void removeShoppingList(const string& name);
    const map<string, shared_ptr<ShoppingList>>& getMyLists() const;


private:
    map<std::string, shared_ptr<ShoppingList>> myLists;
};

#endif //LISTASPESA_USER_H