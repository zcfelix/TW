#ifndef basket_h
#define basket_h

#include <vector>
#include "item.h"

class Basket
{
public:
    void addItem(Item item, unsigned int count) { items_list_.push_back(std::make_pair(item, count)); }
    
private:
    std::vector<std::pair<Item, unsigned int> > items_list_;
    
    friend class Calculator;
};

#endif /* basket_h */
