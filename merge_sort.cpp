#include <vector>
#include <iostream>
#include <cassert>

std::vector<int> merge(const std::vector<int>& x, const std::vector<int>& y)
{
    std::vector<int> result;
    int l = x.size() + y.size();
    int j = 0, k = 0;

    for (auto i = 0; i < l; ++ i)
    {
        if ((k == y.size() || x[j] <= y[k]) && (j != x.size()))
        {
            result.push_back(x[j++]); 
        }
        else
        {
            result.push_back(y[k++]);
        }
    }

    return result;
}

std::vector<int> merge_sort(const std::vector<int>& l, int begin, int end)
{
    if (end - begin == 1)
    {
        if (l[begin] <= l[end])
            return std::vector<int>({l[begin], l[end]}); 
        else
            return std::vector<int>{l[end], l[begin]};
    }

    if (end == begin)
        return std::vector<int>({l[begin]}); 
    
    int pivot = begin + (int)((end - begin)/2);
    
    auto a = merge_sort(l, begin, pivot);
    auto b = merge_sort(l, pivot+1, end);

    auto c = merge(a, b);

    return c;
}

int main(int argc, char * argv[])
{
    auto v = std::vector<int>{4, 3, 2, 1, 5, 0, 7, 8, 4};

    auto s = merge_sort(v, 0, v.size() - 1);
    for(auto x: s)
        std::cout << x << std::endl;
}
