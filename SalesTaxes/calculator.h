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
    void run() const;
    void setBasket(Basket* p_basket) { p_basket_ = p_basket; }
    void setReceipt(Receipt* p_receipt) { p_receipt_ = p_receipt; }
    void setTaxPolicy(TaxPolicy* p_taxpolicy) { p_taxpolicy_ = p_taxpolicy; }
    
private:
    unsigned int calcItemTaxSumPerOne(const Item& item) const;
    void addLineToReceipt(const Item& item, unsigned int item_count) const;
    void updateTotalPrice(unsigned int shelf_price, unsigned int item_count) const { p_receipt_->total_price_cent_ += item_count * shelf_price; }
    void updateTotalTax(unsigned int tax_sum, unsigned int item_count) const { p_receipt_->total_tax_cent_ += item_count * tax_sum; }

    
    Basket*    p_basket_;
    Receipt*   p_receipt_;
    TaxPolicy* p_taxpolicy_;
};

#endif /* calculator_h */
