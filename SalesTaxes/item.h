#ifndef item_h
#define item_h

#include <string>

class Item
{
public:
    Item(std::string name, double price, bool is_imported = false) : name_(name), price_(price), is_imported_(is_imported) {}
    ~Item() {}
private:
    std::string name_;
    double price_;
    bool is_imported_;
    
    friend class Calculator;
};

#endif /* item_h */
