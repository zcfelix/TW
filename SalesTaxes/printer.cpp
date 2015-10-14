#include "printer.h"
#include <iostream>
#include <fstream>

void Printer::printToConsole() const
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

void Printer::printToFile(std::string& file_path) const 
{
    std::ofstream fout(file_path, std::ios::out);
    if (!fout.is_open())
    {
        std::cerr << "Error: output file not opened." << std::endl;
        return;
    }
    
    for (auto &l : p_receipt_->lines_)
    {
        fout << l << std::endl;
    }
    fout.close();
}

void Printer::setReceipt(Receipt *p_receipt)
{
    p_receipt_ = p_receipt;
}