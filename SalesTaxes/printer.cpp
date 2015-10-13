#include "printer.h"
#include <iostream>
#include <fstream>

void Printer::printToConsole()
{
    for (auto &l : p_receipt_->lines_)
    {
        std::cout << l << std::endl;
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Sales Taxes: " << (p_receipt_->total_tax_cent_ / 100.0)<< std::endl;
    std::cout << "Total: " << (p_receipt_->total_price_cent_ / 100.0) << std::endl;
}

void Printer::setReceipt(Receipt *p_receipt)
{
    p_receipt_ = p_receipt;
}