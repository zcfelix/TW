#include <sstream>
#include "calculator.h"

unsigned int Calculator::calcAndRound(unsigned int tax_rate_percent, unsigned int price_cent) const
{
    unsigned int origin_cent = static_cast<unsigned int> ((tax_rate_percent * price_cent) / 100);
    
    unsigned int round_cent = origin_cent;
    if (origin_cent % 5 != 0)
    {
        unsigned int pre_bits = origin_cent / 10;
        round_cent = (pre_bits + 1) * 10;
    }
    return round_cent;
}

void Calculator::run() const
{
    for (auto &i : p_basket_->items_list_)
    {
        unsigned int tax = calcItemTax(i.first);
        unsigned int shelf_price = calcItemShelfPrice(i.first);
        unsigned int item_count = i.second;
        
        addLineToReceipt(i.first, item_count, shelf_price);
        updateTotalPrice(item_count, shelf_price);
        updateTotalTax(item_count, tax);
    }
}

unsigned int Calculator::calcItemTax(const Item &item) const
{
    unsigned int tax_cent_sum = 0;
    for (auto &p : p_taxpolicy_->tax_items_list_)
    {
        unsigned int tax_rate_percent = p.getTaxRatePercent(item);
        unsigned int tax_cent = calcAndRound(tax_rate_percent, item.price_);
        tax_cent_sum += tax_cent;
    }
    return tax_cent_sum;
}

unsigned int Calculator::calcItemShelfPrice(const Item &item) const
{
    return item.price_ + calcItemTax(item);
}

void Calculator::addLineToReceipt(const Item &item, unsigned int item_count, unsigned int shelf_price) const
{
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << item_count << " " << item.name_ << ": " <<  (shelf_price * item_count)/ 100.0;
    p_receipt_->lines_.push_back(ss.str());
}

