#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "item.h"
#include "basket.h"
#include "taxpolicy.h"
#include "receipt.h"
#include "calculator.h"
#include "printer.h"

bool IsLegal(const std::string& line)
{
    if (line.empty()) return false;
    if (line.find(" at ") == std::string::npos) return false;
    return true;
}

unsigned int PriceStringToCent(const std::string& price_str)
{
    auto pos = price_str.find('.');
    if (pos != std::string::npos)
    {
        unsigned int big = std::stoi(price_str.substr(0, pos));
        unsigned int small = std::stoi(price_str.substr(pos + 1));
        return big * 100 + small;
    }
    return std::stoi(price_str);
}

bool GetItemProperties(const std::string& line, std::string& item_name, unsigned int& item_count, unsigned int& item_price, bool& is_imported)
{
    if (!IsLegal(line)) return false;
    
    std::string delim = " at ";
    auto pos1 = line.find(delim);
    
    
    std::string price_str = line.substr(pos1 + delim.length());
    item_price = PriceStringToCent(price_str);
    
    //double price_origin = std::stod(line.substr(pos1 + delim.length()));
    //item_price = static_cast<unsigned int>(std::stod(line.substr(pos1 + delim.length())) * 100.0);
    
    
    auto pos2 = line.find(" ");
    item_count = std::stoi(line.substr(0, pos2));
    item_name = line.substr(pos2 + 1, pos1 - 2);
    if (line.find("imported") != std::string::npos) is_imported = true;
    return true;
}

bool ThrowItemsToBasket(Basket& basket)
{
    std::vector<Item> ret;
    std::ifstream fin("./input/itemlist/input1.txt", std::ios::in);
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        //if (!IsLegal(line)) continue;
        
        std::string item_name;
        unsigned int item_count;
        unsigned int item_price;
        bool is_imported = false;
        
        if (GetItemProperties(line, item_name, item_count, item_price, is_imported))
        {
            Item item(item_name, item_price, is_imported);
            basket.addItem(item, item_count);
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    Basket b;
    ThrowItemsToBasket(b);
    
    TaxPolicy *tp = TaxPolicy::getInstance();
    tp->init();                                         // 为什么不能默认参数，从而省略路径?
    
    Receipt r;
    
    Calculator calc;
    calc.setBasket(&b);
    calc.setReceipt(&r);
    calc.setTaxPolicy(tp);
    calc.run();
    
    Printer printer;
    printer.setReceipt(&r);
    printer.printToConsole();
    return 0;
}


