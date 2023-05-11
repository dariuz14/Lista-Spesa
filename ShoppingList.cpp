//
// Created by Dario Mezzasalma on 31/03/2023.
//

#include "ShoppingList.h"
#include <stdexcept>
#include <iostream>

void ShoppingList::addProduct(const Product &product) {
    auto itr = shoppingList.find(product.getName());
    if(itr != shoppingList.end() && itr->second->getCategory() == product.getCategory()){
        int result = itr->second->getQuantity() + product.getQuantity();
        itr->second->setQuantity(result);
    }
    else{
        auto productPtr = make_shared<Product>(product);
        shoppingList.insert(make_pair(product.getName(), productPtr));
    }

    std::string productCat = product.getCategory();
    bool flag = false;
    for(auto& it: categories){
        if(it.first == productCat) {
            flag = true; //categoria già presente, aggiorno numero oggetti nella categoria
            it.second++;
            break;
        }
    }
    if(!flag){
        categories.insert(make_pair(productCat, 1));
    }
    notifyObservers();
}

void ShoppingList::removeProduct(const string &name) {
    auto itr = shoppingList.find(name);
    if(itr == shoppingList.end()){
        throw invalid_argument("This product name is not valid");
    } else{
        auto itc = categories.find(itr->second->getCategory());
        itc->second--;
        if(itc->second == 0){
            categories.erase(itc);
        }
        itr->second->setQuantity(0);
        shoppingList.erase(itr);
        notifyObservers();
    }
}

void ShoppingList::subscribe(Observer *o) {
    observers.push_back(o);
}

void ShoppingList::unsubscribe(Observer *o) {
    observers.remove(o);
}

void ShoppingList::notifyObservers() {
    for(auto& itr: observers){
        itr->update(listName);
    }
}

void ShoppingList::setBought(const string &name) {
    auto itr = shoppingList.find(name);

    if(itr != shoppingList.end()){
        if(itr->second->isBought()) itr->second->setProductBought(false);
        else itr->second->setProductBought(true);
        notifyObservers();
    }
    else{
        throw invalid_argument("Product name is not valid");
    }
}

int ShoppingList::countNotBought() {
    int result = 0;
    for(auto &itr: shoppingList){
        if(!itr.second->isBought()){
            result += itr.second->getQuantity();
        }
    }
    return result;
}

void ShoppingList::printNotBought() {
    int result = 0;
    cout << "Products to buy: "<< endl;
    string c;
    bool first;
    for(auto &itr: categories){
        c = itr.first;
        first = true;
        if(itr.second != 0){
            for(auto &s: shoppingList){
                if(s.second->getCategory() == c){
                    if(first){
                        cout <<"Category: "<< c << endl;
                        first = false;
                    }
                    if(!s.second->isBought() && s.second->getQuantity() !=0){
                        cout << s.first << " " << s.second->getQuantity() << endl;
                        result += s.second->getQuantity();
                    }

                }
            }
        }
    }
}

void ShoppingList::printList() {
    std::map<std::string, shared_ptr<Product>>:: iterator itr;
    for(itr = shoppingList.begin(); itr != shoppingList.end(); ++itr){
        cout << "Product: " << itr->first << ", quantity: " << itr->second->getQuantity() << endl;
    }

}