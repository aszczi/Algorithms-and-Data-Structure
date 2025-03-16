#include "setList.h"
#include "setArr.h"
#include <iostream>

//--------------------------------------setList---------------------------------------------
    int setList::getSize() {
        return vec.size();
    }

    void setList::printSet() {
        for (int i =0; i< vec.size(); i++) {
            std::cout << vec[i] << " ";
        }
    }

    void setList::insert(int x) {
        if (!isInSet(x)) {
            vec.push_back(x);
        }
    }

    void setList::clearSet() { vec.clear(); }

    void setList::withdraw(int x) {
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            if (*it == x) {
                vec.erase(it);
                return;
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
        setList result = *this;
        for (int val : obj.vec) {
            if (!result.isInSet(val)) {
                result.insert(val);
            }
        }
        return result;
    }

    setList setList::operator-(setList& obj) {
        setList result;
        for (int val : vec) {
            if (!obj.isInSet(val)) {
                result.insert(val);
            }
        }
        return result;
    }

    setList setList::operator*(setList& obj) { //czesc wspolna
        setList result;
        for (int i = 0; i < setList::vec.size(); i++) {
            if (obj.isInSet(vec[i])) {
                result.insert(vec[i]);
            }
        }
        return result;
    }

    bool setList::operator==(setList& obj) {
        if (obj.getSize() != getSize()) {
            return false;
        }
        for (int i = 0; i < vec.size(); i++) {
            if (!obj.isInSet(vec[i])) {
                return false;
            }
        }
        return true;
    }
    bool setList::operator<=(setList& obj) {

        for (int a : vec) {
            if (!obj.isInSet(a)) {
                return false;
            }
        }
        return true;
    }
    bool setList::operator>=(setList& obj) {
        // A >= B
        for (int a : obj.vec) {
            if (!isInSet(a)) {
                return false;
            }
        }
        return true;
    }

    //----------------------------------------------------setArr-----------------------------------------------------------

    setArr::setArr() {
        table = new bool[universeSize] {false};
        size =0;
    }

    bool setArr::checkRangeCorrectness(int x){
        if (x < universeSize){
            return true;
        }
        return false;
    }


    void setArr::insert(int x) {
        if (checkRangeCorrectness(x) && !table[x]) {
            table[x] = true;
            size++;
        }

    }

    void setArr::withdraw(int x) {
        if (checkRangeCorrectness(x) && table[x]){
            size--;
            table[x] = false;
        }

    }
    bool setArr::isInSet(int i) {
        return checkRangeCorrectness(i) && table[i];

    }
    int setArr::getSize() {
        return size;
    }

    void setArr::clearSet() {
        for (int i = 0; i < universeSize; i++) {
            table[i] = false;
        }
        size = 0;
    }
    void setArr::printSet() {
        for (int i = 0; i <universeSize; i++) {
            if (table[i] == true) {
                std::cout<< i <<" ";
            }
        }
    }


     setArr setArr::operator+(setArr& object) {
        setArr result;
        for (int i = 0; i < universeSize; ++i) {
            if (this->table[i] || object.table[i]) {
                result.insert(i);
            }
        }
        return result;
    }



    setArr setArr::operator*(setArr& object) {
        setArr result;
        for (int i = 0; i < universeSize; i++) {
            if (this->table[i] && object.isInSet(i)) {
                result.insert(i);
            }
        }
        return result;
    }


    setArr setArr::operator-(setArr& object) {
        setArr result;
        for (int i = 0; i < universeSize; i++) {
            if (this->table[i] && !object.isInSet(i)) {
                    result.insert(i);
                }
            }
        return result;
    }


    bool setArr::operator==(setArr& object) {
        for (int i = 0; i< setArr::universeSize; i++) {
            if ((table[i] != object.isInSet(i))) {
                return false;
            }
        }
        return true;
    }

    bool setArr::operator <= (setArr& object) {
        //a <= b  czyli wszystkie elementy w a musza byc w b
        for (int i = 0; i < universeSize; i++) {
            if (this->table[i] == true) {
                if (!object.isInSet(i)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool setArr::operator >= (setArr& object) {
        //a >= b  czyli wszystkie elementy w b musza byc w a
        for (int i = 0; i < setArr::universeSize; i++) {
            if (object.isInSet(i) == true) {
                if (!this->table[i])
                    return false;
            }
        }
        return true;
    }

