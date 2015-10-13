#include "taxitem.h"

unsigned TaxItem::getTaxRatePercent(const Item &item) const
{
    if (tax_name_ == "import_duty")
    {
        if (item.getName().find("imported") != std::string::npos)
            return tax_rate_percent_;
        else
            return 0;
    }
    
    std::string item_name = item.getName();
    for (auto &e : exemptions_list_)
    {
        if (item_name.find(e) != std::string::npos)
            return 0;
    }
    return tax_rate_percent_;
}