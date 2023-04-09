//
// Created by Dario Mezzasalma on 05/04/2023.
//

#ifndef LISTASPESA_OBSERVER_H
#define LISTASPESA_OBSERVER_H

#include <string>

using namespace std;

class Observer{
public:
    virtual ~Observer() = default;
    virtual void update(const string& listName) = 0;
};

#endif //LISTASPESA_OBSERVER_H
