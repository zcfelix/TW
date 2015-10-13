#include "publicfunction.h"

bool IsLegal(const std::string& line)
{
    if (line.empty()) return false;
    if (line.find(" at ") == std::string::npos) return false;
    return true;
}

unsigned int CalcAndRound(unsigned int tax_rate_percent, unsigned int price_cent)
{
    unsigned int origin_cent = static_cast<unsigned int> ((tax_rate_percent * price_cent) / 100);
    
    unsigned int round_cent = origin_cent;
    if (origin_cent % 5 != 0)
    {
        unsigned int pre_bits = origin_cent / 10;
        round_cent = (pre_bits + 1) * 10;
    }
    return round_cent;
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

bool GetItemProperties(const std::string& line, std::string& item_name, unsigned int& item_count, unsigned int& item_price)
{
    if (!IsLegal(line)) return false;
    
    std::string delim = " at ";
    auto pos1 = line.find(delim);
    
    
    std::string price_str = line.substr(pos1 + delim.length());
    item_price = PriceStringToCent(price_str);
    
    auto pos2 = line.find(" ");
    item_count = std::stoi(line.substr(0, pos2));
    item_name = line.substr(pos2 + 1, pos1 - 2);
    return true;
}


