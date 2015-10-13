#include <string>
#include <unordered_set>
#include <fstream>
#include "taxpolicy.h"

void TaxPolicy::init()
{
    std::fstream fin("./input/taxpolicy/basic_sales_tax.txt", std::ios::in);
    
    bool is_tax_rate_readed = false;
    unsigned int tax_rate = 0;
    std::unordered_set<std::string> exemptions_list;
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        
        if (!is_tax_rate_readed)
        {
            tax_rate = std::stoi(line);
            is_tax_rate_readed = true;
            continue;
        }
        exemptions_list.insert(line);
    }
    
    tax_items_list_.push_back(TaxItem("basic_sales_tax", tax_rate, exemptions_list));
    
    
    is_tax_rate_readed = false;
    std::fstream fin2("./input/taxpolicy/import_duty.txt", std::ios::in);
    unsigned int tax_rate2 = 0;
    std::unordered_set<std::string> exemptions_list2;
    while (!fin2.eof())
    {
        std::string line;
        std::getline(fin2, line);
        if (!is_tax_rate_readed)
        {
            tax_rate2 = std::stoi(line);
            is_tax_rate_readed = true;
            continue;
        }
        exemptions_list2.insert(line);
    }
    tax_items_list_.push_back(TaxItem("import_duty", tax_rate2, exemptions_list2));
}