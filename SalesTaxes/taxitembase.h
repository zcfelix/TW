#ifndef taxitem_h
#define taxitem_h

#include <unordered_set>
#include "publicfunction.h"
#include "item.h"

class TaxItemBase                           // 税目抽象基类，每个具体的税目继承该类，实现对应的接口
{
public:
    virtual unsigned int taxRateOfItem(const Item& item) const = 0;
    virtual unsigned int roundedTaxPerOne(const Item& item) const = 0;
    
protected:
    virtual bool isExempted(const Item& item) const = 0;
};

#endif /* taxitem_h */
