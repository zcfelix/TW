#ifndef importedduty_h
#define importedduty_h

#include <string>
#include <unordered_set>
#include "taxitembase.h"

class ImportedDuty : public TaxItemBase
{
public:
    ImportedDuty(std::string tax_item_name, unsigned int tax_rate_percent, std::unordered_set<std::string> exemptions_list) : tax_item_name_(tax_item_name),
        tax_rate_percent_(tax_rate_percent), exemptions_list_(exemptions_list) {}
    virtual unsigned int taxRateOfItem(const Item& item) const override;
    virtual unsigned int roundedTaxPerOne(const Item& item) const override;
    
private:
    virtual bool isExempted(const Item& item) const override;
    std::string tax_item_name_;
    unsigned int tax_rate_percent_;
    std::unordered_set<std::string> exemptions_list_;
};

#endif /* importedduty_h */
