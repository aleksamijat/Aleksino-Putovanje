#include "dinstring.hpp"

DinString::DinString() {
    len = 0;
    text = NULL;
}

DinString::DinString(const char input[]) {
    len = 0;
    while(input[len] != '\0')
        len++;

    text = new char[len + 1];
    for(int i = 0; i < len; i++)
        text[i] = input[i];

    text[len] = '\0';
}

DinString::DinString(const DinString& ds) {
    len = ds.len;

    text = new char[len + 1];
    for(int i = 0; i < len; i++)
        text[i] = ds.text[i];

    text[len] = '\0';
}

DinString::~DinString() {
    delete[] text;
}

int DinString::length() const {
    return len;
}

char& DinString::operator[] (int i) {
    return text[i];
}

char DinString::operator[] (int i) const {
    return text[i];
}

DinString& DinString::operator=(const DinString& ds) {
    if(this != &ds) {
        delete[] text;
        len = ds.len;
        text = new char[len + 1];
        for (int i = 0; i < len; i++)
            text[i] = ds.text[i];

        text[len] = '\0';
    }

    return *this;
}

DinString& DinString::operator+=(const DinString& ds) {
    int i;
    char *Text_ = new char[len + ds.len + 1];
    for (i = 0; i < len; i++)
        Text_[i] = text[i];
    for (i = 0; i < ds.len; i++)
        Text_[len + i] = ds.text[i];
    Text_[len + ds.len] = '\0';

    len += ds.len;

    delete[] text;
    text = Text_;

    return *this;
}

bool operator==(const DinString& ds1, const DinString& ds_){
    if(ds1.len != ds_.len)
        return false;

    for(int i = 0; i < ds1.len; i++)
        if(ds1.text[i] != ds_.text[i])
            return false;

    return true;
}

bool operator!=(const DinString& ds1, const DinString& ds_){
    if(ds1.len != ds_.len)
        return true;

    for(int i = 0; i < ds1.len; i++)
        if(ds1.text[i] != ds_.text[i])
            return true;

    return false;
}

DinString operator+(const DinString& ds1, const DinString& ds_){
    DinString temp;
    temp.len = ds1.len + ds_.len;

    temp.text = new char[temp.len + 1];

    int i;
    for(i = 0; i < ds1.len; i++)
        temp.text[i] = ds1.text[i];

    for(i = 0; i < ds_.len; i++)
        temp.text[ds1.len + i] = ds_.text[i];
    temp.text[temp.len] = '\0';

    return temp;

}

ostream& operator<<(ostream& output, const DinString& ds) {
    if(ds.len > 0)
        output << ds.text;
    return output;
}
