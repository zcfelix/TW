#include <string>
#include <fstream>
#include "taxpolicy.h"

void TaxPolicy::init(std::string file_path = "./input/tax.policy")
{
    std::ifstream fin(file_path, std::ios::in);
    int line_count = 0;
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        if (line_count == 0)
            basic_sales_tax_ = std::stod(line);
        else if (line_count == 1)
            imported_duty_ = std::stod(line);
        else
            exemptions_list_.insert(line);
        line_count++;
    }
}

void TaxPolicy::setBasicSalesTax(double basic_sales_tax)
{
    basic_sales_tax_ = basic_sales_tax;
}

void TaxPolicy::setImportDuty(double imported_duty)
{
    imported_duty_ = imported_duty;
}

void TaxPolicy::setExemptions(std::unordered_set<std::string> &exemptions)
{
    for (auto i : exemptions)
        exemptions_list_.insert(i);
}


