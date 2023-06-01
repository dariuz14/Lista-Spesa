cmake_minimum_required(VERSION 3.15)
project(listaspesa)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Test)
set(SOURCE_FILES Observer.h Product.h ShoppingList.cpp ShoppingList.h Subject.h User.cpp User.h)

add_executable(listaspesa main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(listaspesa core)
