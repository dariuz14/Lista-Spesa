//
// Created by Dario Mezzasalma on 19/05/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../Product.h"
#include "../User.h"

class ShoppingListSuite: public ::testing:: Test{
protected:
    void SetUp() override{
        s.addProduct(p1);
        s.addProduct(p2);
        s.addProduct(p3);
    }

    ShoppingList s{"Compere"};
    Product p1{"mela", "frutta", 1};
    Product p2{"latte", "latticini", 2};
    Product p3{"pane", "farinaggi", 1};
    User user;
};

TEST_F(ShoppingListSuite, TestGetShoppingListName){
    ShoppingList l{"Spesa"};
    ASSERT_EQ(l.getListName(), "Spesa");
};

TEST_F(ShoppingListSuite, TestAddProduct){
    Product p("pasta", "farinaggi", 2);
    s.addProduct(p);
    int size = s.getShoppingList().size();
    ASSERT_EQ(size, 4);

    Product p2("pasta", "farinaggi", 3);
    s.addProduct(p2);
    size = s.getShoppingList().size();
    ASSERT_EQ(size, 4);

    auto itr = s.getShoppingList().find("pasta");
    itr->second->setQuantity(2);
    auto res = itr ->second->getQuantity();
    ASSERT_EQ(res , 2);
};

TEST_F(ShoppingListSuite, TestRemoveProduct){
    s.removeProduct("mela");
    int size = s.getShoppingList().size();
    ASSERT_EQ(size, 2);
};

TEST_F(ShoppingListSuite, TestSetBought){
    s.setBought("latte");
    ASSERT_EQ(s.countNotBought(), 2);
};

TEST_F(ShoppingListSuite, TestSubject){
    s.subscribe(&user);
    ASSERT_EQ(s.getObservers().size(), 1);
    s.unsubscribe(&user);
    ASSERT_EQ(s.getObservers().size(), 0);
};

TEST_F(ShoppingListSuite, TestCountNotBought){
    ASSERT_EQ(s.countNotBought(), 4);
};
