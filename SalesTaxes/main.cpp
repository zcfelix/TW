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
#include "publicfunction.h"

bool ThrowItemsToBasket(Basket& basket)
{
    std::vector<Item> ret;
    std::ifstream fin("./input/itemlist/input3.txt", std::ios::in);
    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        if (!IsLegal(line)) continue;
        
        std::string item_name;
        unsigned int item_count;
        unsigned int item_price;
        bool is_imported = false;
        
        if (GetItemProperties(line, item_name, item_count, item_price))
        {
            Item item(item_name, item_price);
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
    std::string out_path = "./output/output2.txt";
    printer.printToFile(out_path);
    return 0;
}


