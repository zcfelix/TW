#include <sstream>
#include "calculator.h"

void Calculator::run() const
{
    for (auto &i : p_basket_->items_list_)
    {
        unsigned int tax_sum = calcItemTaxSumPerOne(i.first);
        unsigned int shelf_price = i.first.getPrice() + tax_sum;
        unsigned int item_count = i.second;
        
        addLineToReceipt(i.first, item_count);
        updateTotalPrice(shelf_price, item_count);
        updateTotalTax(tax_sum, item_count);
    }
}

unsigned int Calculator::calcItemTaxSumPerOne(const Item &item) const
{
    unsigned int tax_sum = 0;
    for (auto &p : p_taxpolicy_->tax_items_list_)
    {
        tax_sum += p->roundedTaxPerOne(item);
    }
    return tax_sum;
}

void Calculator::addLineToReceipt(const Item &item, unsigned int item_count) const
{
    unsigned int shelf_price = item.getPrice() + calcItemTaxSumPerOne(item);
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << item_count << " " << item.getName() << ": " <<  (shelf_price * item_count)/ 100.0;
    p_receipt_->lines_.push_back(ss.str());
}

