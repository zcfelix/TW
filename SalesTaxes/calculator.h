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
    unsigned int calcAndRound(unsigned int tax_rate_percent, unsigned int price_cent) const;
    unsigned int calcItemTax(const Item& item) const;
    unsigned int calcItemShelfPrice(const Item& item) const;
    void addLineToReceipt(const Item& item, unsigned int item_count, unsigned int shelf_price) const;
    void updateTotalPrice(unsigned int item_count, unsigned int shelf_price) const { p_receipt_->total_price_cent_ += item_count * shelf_price; }
    void updateTotalTax(unsigned int item_count, unsigned int tax) const { p_receipt_->total_tax_cent_ += item_count * tax; }

    
    Basket*    p_basket_;
    Receipt*   p_receipt_;
    TaxPolicy* p_taxpolicy_;
};

#endif /* calculator_h */
