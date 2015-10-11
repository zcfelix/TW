#ifndef printer_hpp
#define printer_hpp

#include "receipt.h"
class Receipt;

class Printer
{
public:
    void printToConsole();
    void setReceipt(Receipt* p_receipt);
    
private:
    Receipt* p_receipt_;
};

#endif /* printer_hpp */
