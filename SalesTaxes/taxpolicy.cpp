#include <string>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include "taxpolicy.h"
#include "basictax.h"
#include "importedduty.h"

void TaxPolicy::init()
{
    std::unordered_set<std::string> exemptions_list { "book", "chocolate", "pill" };
    std::unordered_set<std::string> exemptions_list2;
    TaxItemBase *p_t1 = new BasicTax("basic sales rate", 10, exemptions_list);
    TaxItemBase *p_t2 = new ImportedDuty("imported duty", 5, exemptions_list2);
    addTaxItem(p_t1);
    addTaxItem(p_t2);
}

void TaxPolicy::initFromFile(std::string input_file)
{
    std::ifstream fin(input_file, std::ios::in);
    if (!fin.is_open())
    {
        std::cerr << "Error: Tax Policy not inited correctly" << std::endl;
        return;
    }
    
    int line_cnt = 1;
    std::string tax_name;
    unsigned int tax_percent = 0;
    bool is_imported_duty = false;
    std::unordered_set<std::string> exemptions_list;
    
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        if (line == "=====")
        {
            TaxItemBase *p_t;
            if (is_imported_duty)
                p_t = new ImportedDuty(tax_name, tax_percent, exemptions_list);
            else
                p_t = new BasicTax(tax_name, tax_percent, exemptions_list);
            addTaxItem(p_t);
            exemptions_list.clear();
            line_cnt = 1;
            is_imported_duty = true;
            continue;
        }
        if (line_cnt == 1)
            tax_name = line;
        else if (line_cnt == 2)
            tax_percent = std::stoi(line);
        else
            exemptions_list.insert(line);

        line_cnt++;
    }
}