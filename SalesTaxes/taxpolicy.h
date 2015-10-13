#ifndef taxpolicy_h
#define taxpolicy_h

#include <string>
#include <vector>
#include <unordered_set>
#include "taxitem.h"

class TaxPolicy   // 税收政策：单例模式。维护一个税种列表，提供添加税种、初始化等接口
{
public:
    static TaxPolicy* getInstance() { static TaxPolicy instance; return &instance; }
    void addTaxItem(TaxItem tax_item) { tax_items_list_.push_back(tax_item); }
    void init();

private:
    TaxPolicy() {}
    TaxPolicy(const TaxPolicy& taxpolicy) = delete;
    TaxPolicy& operator=(const TaxPolicy& taxpolicy) = delete;
    std::vector<TaxItem> tax_items_list_;
    
    friend class Calculator;
};

#endif /* taxpolicy_h */
