#include "basictax.h"

unsigned int BasicTax::taxRateOfItem(const Item &item) const
{
    if (isExempted(item))
        return 0;
    else
        return tax_rate_percent_;
}

unsigned int BasicTax::roundedTaxPerOne(const Item &item) const
{
    unsigned int price = item.getPrice();
    unsigned int tax_rate = taxRateOfItem(item);
    return CalcAndRound(tax_rate, price);
}

bool BasicTax::isExempted(const Item &item) const
{
    std::string item_name = item.getName();
    for (auto &e : exemptions_list_)
    {
        if (item_name.find(e) != std::string::npos)
            return true;
    }
    return false;
}