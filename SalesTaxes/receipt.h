#ifndef receipt_h
#define receipt_h

#include <string>
#include <vector>

class Receipt
{
public:
    Receipt() : total_price_(0.0), total_tax_(0.0) {}
private:
    std::vector<std::string> lines_;
    double total_price_;
    double total_tax_;
    
    friend class Calculator;
    friend class Printer;
};

#endif /* receipt_h */
