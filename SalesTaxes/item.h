#ifndef item_h
#define item_h

#include <string>

class Item
{
public:
    Item(std::string name, unsigned int price) : name_(name), price_(price) {}
    ~Item() {}
    std::string getName() const { return name_; }
    unsigned int getPrice() const { return price_; }
    
private:
    std::string name_;
    unsigned int price_;
    
    friend class Calculator;
};

#endif /* item_h */
