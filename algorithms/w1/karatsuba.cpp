#include <string>
#include <iostream>


std::string multiply(const std::string& x, const std::string& y)
{
    auto l = x.size();
    if (l <= 2)
    {
        auto t = std::stoi(x) * std::stoi(y);
        return std::to_string(t);
    }
    std::cout << l << std::endl;    
    auto a = x.substr(0, l/2);
    auto b = x.substr(l/2);
    auto c = y.substr(0, l/2);
    auto d = y.substr(l/2);
    return x;
}

std::string add(const std::string& x, const std::string& y)
{
    auto l = std::max(x.size(), y.size());
    std::string result; 

    int carry = 0;
    for (auto i = 0; i < l; i ++)
    {
        int a = 0; 
        int b = 0;
        int c = 0; 

        if (i < x.size())
            a = (int)x.at(i) - 48;
        else
            a = 0;

        if (i < y.size())
            b = (int)(y.at(i)) - 48;
        else
            b = 0;

        c = a + b + carry;
        if (c >= 10)
        {
            carry = 1;
            c -= 10;
        }
        else
            carry = 0;

        result.insert(0, std::to_string(c));
    }
    if (carry > 0)
        result.insert(0, "1");

    return result;
}

int main()
{
    std::cout << "add: " << ::add(std::string("9999"), std::string("1111")) << std::endl;
    ::multiply(std::string("1234"), std::string("5678"));
    std::cout << "expected: " << 1234 * 5678 << std::endl;
}
