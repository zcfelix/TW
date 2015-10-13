#ifndef publicfunction_h
#define publicfunction_h

#include <string>

bool IsLegal(const std::string& line);
unsigned int CalcAndRound(unsigned int tax_rate_percent, unsigned int price_cent);
bool GetItemProperties(const std::string& line, std::string& item_name, unsigned int& item_count, unsigned int& item_price);
unsigned int PriceStringToCent(const std::string& price_str);

#endif /* publicfunction_h */
