#ifndef receipt_h
#define receipt_h

#include <string>
#include <vector>

class Receipt
{
public:
    Receipt() : total_price_cent_(0), total_tax_cent_(0) {}

private:
    std::vector<std::string> lines_;
    unsigned int total_price_cent_;
    unsigned int total_tax_cent_;
    
    friend class Calculator;
    friend class Printer;
};

#endif /* receipt_h */
