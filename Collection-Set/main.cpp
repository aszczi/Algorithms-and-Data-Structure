#include <iostream>
#include "setList.h"
#include "setArr.h"

int setList::getSize() {
    return setList::vec.size();
}

void setList::printSet() {
    for (int i  =0; i< setList::vec.size(); i++) {
        std::cout << setList::vec[i] << " ";
    }
}

void setList::insert(int x) {
vec.push_back(x);
}

void setList::withdraw(int x) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == x) {
            vec.erase(vec.begin() + i);
        }
    }
}

bool setList::isInSet(int x) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == x) {
            return true;
        }
    }
    return false;
}

setList setList::operator+(setList& obj) {

    for (int i = 0; i < setList::vec.size(); i++) {
        if (obj.isInSet(vec[i])) {
            obj.insert(vec[i]);
        }
    }
    return obj;
}

setList setList::operator-(setList& obj) {

    for (int i = 0; i < setList::vec.size(); i++) {
        if (obj.isInSet(vec[i])) {
            obj.withdraw(vec[i]);
        }
    }
    return obj;
}

setList setList::operator*(setList& obj) {

    return obj;
}
bool setList::operator==(setList& obj) {
    if (obj.getSize() != getSize()) {
        return false;
    }
    for (int i = 0; i < setList::vec.size(); i++) {
        if (!obj.isInSet(vec[i])) {
            return false;
        }
    }
    return true;
}
bool setList::operator<=(setList& obj) {

    return true;
}
//set Arr

setArr::setArr() {

}
void setArr::insert(int x) {

}

void setArr::withdraw(int x) {

}
bool setArr::isInSet(int i) {

}
int setArr::getSize() {

}
void setArr::clearSet() {

}
void setArr::printSet() {

}
int main() {


    return 0;
}

