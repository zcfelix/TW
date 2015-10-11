#ifndef calculator_h
#define calculator_h

#include <string>
#include "item.h"
#include "receipt.h"
#include "basket.h"
#include "taxpolicy.h"

class Calculator
{
public:
    Calculator() {}
    Calculator(Basket* p_basket, Receipt* p_receipt, TaxPolicy* p_taxpolicy) : p_basket_(p_basket), p_receipt_(p_receipt), p_taxpolicy_(p_taxpolicy) {}

    void run();
    void setBasket(Basket* p_basket) { p_basket_ = p_basket; }
    void setReceipt(Receipt* p_receipt) {p_receipt_ = p_receipt; }
    void setTaxPolicy(TaxPolicy* p_taxpolicy) {p_taxpolicy_ = p_taxpolicy; }
    
private:
    Basket*    p_basket_;
    Receipt*   p_receipt_;
    TaxPolicy* p_taxpolicy_;
    
    double getItemTaxRate(const Item& item);
    double calcTax(const Item& item, unsigned int item_count, double tax_rate);
    double calcShelfPrice(const Item& item, unsigned int item_count,double tax_rate);
    double roundToNearest(double price);
    bool   isExemption(const Item& item);
    void   addLineToReceipt(const Item& item, unsigned int item_count, double shelf_price);
    void   updateTotalPrice(double price) { p_receipt_->total_price_ += price; }
    void   updateTotalTax(double tax) { p_receipt_->total_tax_ += tax; }
};

#endif /* calculator_h */
