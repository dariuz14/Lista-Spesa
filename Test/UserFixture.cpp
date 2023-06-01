//
// Created by Dario Mezzasalma on 19/05/2023.
//

#include "gtest/gtest.h"
#include "../User.h"
#include "../ShoppingList.h"


class UserSuite: public ::testing:: Test{
protected:
    void SetUp() override{
        u.addShoppingList(s1);
        u.addShoppingList(s2);
    }

    ShoppingList s1{"spesa1"};
    ShoppingList s2{"spesa2"};
    ShoppingList s3{"spesa3"};
    User u;
};

TEST_F(UserSuite, TestHasList){
    ASSERT_TRUE(u.hasList("spesa1"));
};

TEST_F(UserSuite,TestAddShoppingList){
    u.addShoppingList(s3);
    ASSERT_EQ(3, u.getMyLists().size());
}

TEST_F(UserSuite,TestRemoveShoppingList){
    u.removeShoppingList("spesa2");
    ASSERT_EQ(1, u.getMyLists().size());
}
