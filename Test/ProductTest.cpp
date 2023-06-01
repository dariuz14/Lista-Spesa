//
// Created by Dario Mezzasalma on 19/05/2023.
//

#include "gtest/gtest.h"
#include "../Product.h"

TEST(ProductSuite, TestConstructor){
    Product p("mela", "frutta", 1);
    ASSERT_EQ(p.getName(), "mela");
    ASSERT_EQ(p.getCategory(), "frutta");
    ASSERT_EQ(p.getQuantity(), 1);
    ASSERT_THROW(Product p2("mela", "frutta", -1), invalid_argument);
}

TEST(ProductSuite, TestSetQuantity){
    Product p("mela", "frutta", 1);
    p.setQuantity(3);
    ASSERT_EQ(p.getQuantity(), 3);
    ASSERT_THROW(p.setQuantity(-1), invalid_argument);
}

TEST(ProductSuite, TestSetBought){
    Product p("mela", "frutta", 1);
    p.setProductBought(true);
    ASSERT_TRUE(p.isBought());
}

