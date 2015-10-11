#ifndef taxpolicy_h
#define taxpolicy_h

#include <string>
#include <unordered_set>

class TaxPolicy             // 单例
{
public:
    static TaxPolicy* getInstance() { static TaxPolicy instance; return &instance; }
    void init(std::string file_path);
    void setBasicSalesTax(double basic_sales_tax);
    void setImportDuty(double imported_duty);
    void setExemptions(std::unordered_set<std::string>& exemptions);
    
private:
    TaxPolicy() {};
    TaxPolicy(const TaxPolicy& t) {};
    TaxPolicy& operator=(const TaxPolicy& t) = delete;
    
    double basic_sales_tax_;
    double imported_duty_;
    std::unordered_set<std::string> exemptions_list_;
    
    friend class Calculator;
};

#endif /* taxpolicy_h */
