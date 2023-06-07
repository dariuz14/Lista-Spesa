//
// Created by Dario Mezzasalma on 25/05/2023.
//

#include "gtest/gtest.h"
#include "../Observer.h"
#include "../ShoppingList.h"
#include "../Product.h"

class ObserverTest: public testing::Test, public Observer{
public:
    void update(const string& listName) override {
        updated = true;
    }

    bool isUpdated() const{
        return updated;
    }

protected:
    void SetUp() override {
        s.subscribe(this);
    }

    void TearDown() override {
        s.unsubscribe(this);
    }

    bool updated = false;
    ShoppingList s{"spesa"};
};

TEST_F(ObserverTest, TestUpdate){
    Product p{"pane", "farinaggi", 1};
    ASSERT_FALSE(isUpdated());
    s.addProduct(p);
    ASSERT_TRUE(isUpdated());
};