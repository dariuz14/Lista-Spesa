//
// Created by Dario Mezzasalma on 31/03/2023.
//

#ifndef LISTASPESA_PRODUCT_H
#define LISTASPESA_PRODUCT_H

#include <string>
#include <exception>
#include <stdexcept>


using namespace std;

class Product{
public:
    Product(std::string s, std::string c, int q = 1): name(std::move(s)), category(std::move(c)){
        if(q > 0){
            quantity = q;
        }
        else {
            throw invalid_argument("Value of q is not valid");
        }
    }

    const string &getName() const {
        return name;
    }

    const string &getCategory() const {
        return category;
    }

    int getQuantity() const {
        return quantity;
    }

    bool isBought() const {
        return bought;
    }

    void setQuantity(int q) {
        if(q >= 0){
            quantity = q;
        }
        else{
            throw invalid_argument("Value of q is not valid");
        }
    }

    void setProductBought(bool b){
        bought = b;
    }

private:
    std::string name;
    std::string category;
    int quantity;
    bool bought = false;
};

#endif //LISTASPESA_PRODUCT_H