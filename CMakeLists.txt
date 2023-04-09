cmake_minimum_required(VERSION 3.15)
project(listaspesa)

set(CMAKE_CXX_STANDARD 14)

add_executable(listaspesa main.cpp User.cpp User.h Product.h ShoppingList.cpp ShoppingList.h Observer.h Subject.h)
