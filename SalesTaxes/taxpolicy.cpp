#include <string>
#include <unordered_set>
#include <fstream>
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