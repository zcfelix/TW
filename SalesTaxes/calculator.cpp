#include <sstream>
#include "calculator.h"

void Calculator::run()
{
    for (auto &p : p_basket_->items_list_)
    {
        double tax_rate = getItemTaxRate(p.first);
        double tax = calcTax(p.first, p.second, tax_rate);
        double shelf_price = calcShelfPrice(p.first, p.second, tax_rate);
        
        addLineToReceipt(p.first, p.second, shelf_price);
        updateTotalTax(tax);
        updateTotalPrice(shelf_price);
    }
}

double Calculator::calcTax(const Item &item, unsigned int item_count, double tax_rate)
{
    double tax = item.price_ * item_count * tax_rate;
    tax = roundToNearest(tax);
    return tax;
}

double Calculator::calcShelfPrice(const Item &item, unsigned int item_count, double tax_rate)
{
    double shelf_price = item.price_ * item_count * (1.0 + tax_rate);
    shelf_price = roundToNearest(shelf_price);
    return shelf_price;
}

double roundToNearest(double price)
{
    
}

void Calculator::addLineToReceipt(const Item& item, unsigned int item_count, double shelf_price)
{
    std::stringstream ss;
    ss << item_count << " " << item.name_ << ": " << shelf_price;
    p_receipt_->lines_.push_back(ss.str());
}

double Calculator::getItemTaxRate(const Item& item)
{
    double tax = 0.0;
    if (item.is_imported_)
        tax += p_taxpolicy_->imported_duty_;
    if (!isExemption(item))
        tax += p_taxpolicy_->basic_sales_tax_;
    return tax;
}

bool Calculator::isExemption(const Item &item)
{
    std::string name = item.name_;
    for (auto &e : p_taxpolicy_->exemptions_list_)
    {
        if (name.find(e) != std::string::npos)
            return true;
    }
    return false;
}
