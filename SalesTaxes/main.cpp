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

bool ThrowItemsToBasket(Basket& basket, std::string input_path);

bool ThrowItemsToBasket(Basket& basket, std::string input_path)
{
    std::vector<Item> ret;
    std::ifstream fin(input_path, std::ios::in);
    if (!fin.is_open())
        return false;

    while (!fin.eof())
    {
        std::string line;
        std::getline(fin, line);
        if (!IsLegal(line)) continue;
        
        std::string item_name;
        unsigned int item_count;
        unsigned int item_price;
        
        if (GetItemProperties(line, item_name, item_count, item_price))
        {
            Item item(item_name, item_price);
            basket.addItem(item, item_count);
        }
    }
    fin.close();
    return true;
}


int main(int argc, const char * argv[])
{
    std::string input_file;
    std::string output_file = "./output/output.txt";                // 默认输出
    
    if (argc == 1)
        input_file = "./input/input1.txt";                          // 默认输入
    else if (argc == 2)
        input_file = argv[1];
    else if (argc == 3)
    {
        input_file  = argv[1];
        output_file = argv[2];
    }
    else
    {
        std::cerr << "Incorrect argument. Useage: ./SalesTax <input_file> <outout_file>\n"
                  << "Options: \n<input_file>      Item list for calculating taxes\n"
                  << "<output_file>     Optional, output file to save result\n"
                  << std::endl;
        return -1;
    }
    
    Basket b;
    bool isThrown = ThrowItemsToBasket(b, input_file);
    if (!isThrown)
    {
        std::cerr << "Error: input file not found" << std::endl;
        return -1;
    }
    
    TaxPolicy *tp = TaxPolicy::getInstance();
    tp->init();
    //tp->initFromFile("./input/taxpolicy.txt");
    
    Receipt r;
    
    Calculator calc;
    calc.setBasket(&b);
    calc.setReceipt(&r);
    calc.setTaxPolicy(tp);
    calc.run();
    
    Printer printer;
    printer.setReceipt(&r);
    printer.printToConsole();
    printer.printToFile(output_file);
    return 0;
}


