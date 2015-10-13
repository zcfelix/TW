#include "importedduty.h"

unsigned int ImportedDuty::taxRateOfItem(const Item& item) const
{
    if (isExempted(item))
        return 0;
    else
        return tax_rate_percent_;
}

unsigned int ImportedDuty::roundedTaxPerOne(const Item& item) const
{
    unsigned int price = item.getPrice();
    unsigned int tax_rate = taxRateOfItem(item);
    return CalcAndRound(tax_rate, price);
}

bool ImportedDuty::isExempted(const Item &item) const
{
    if (item.getName().find("imported") != std::string::npos)
        return false;
    else
        return true;
}