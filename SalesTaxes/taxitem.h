#ifndef taxitem_hpp
#define taxitem_hpp

#include <unordered_set>
#include "item.h"


class TaxItem     // 税种，对应消费税，关税等，每一个税种，维护自己的名称、税率以及免税列表
{
public:
    TaxItem(std::string tax_name, unsigned int tax_rate_percent, std::unordered_set<std::string> exemptions_list) : tax_name_(tax_name),
    tax_rate_percent_(tax_rate_percent) { exemptions_list_ = exemptions_list; }
    
    std::string  getTaxName() const { return tax_name_; }
    unsigned int getTaxRatePercent (const Item& item) const;
    
private:
    std::string  tax_name_;
    unsigned int tax_rate_percent_;
    std::unordered_set<std::string> exemptions_list_;
};

#endif /* taxitem_hpp */
