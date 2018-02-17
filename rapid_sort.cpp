#include <iostream>
#include <vector>

int partition(std::vector<int>& l, int begin, int end)
{
    int i = begin, j = end; 
    int pivot = l[(end + begin)/ 2];

    while (i <= j)
    {
        while (l[i] < pivot)
            i ++;
        while (l[j] > pivot)
            j --; 

        if (i <= j)
        {
            std::swap(l[i], l[j]);
            i++;
            j--;
        }
    }
    return i;
};

void rapid_sort(std::vector<int>& l, int begin, int end)
{
    int pivot = partition(l, begin, end);
    
    if (begin < pivot - 1)
        rapid_sort(l, begin, pivot-1);
    
    if (pivot < end)
        rapid_sort(l, pivot, end); 
};

int  main(int argc, char * argv[])
{
    std::vector<int> v{5, 4, 3, 2, 1};
    rapid_sort(v, 0, 4);
    for (auto a: v)
        std::cout << a << std::endl;
    
    std::cout << (int)(1.8) << std::endl;
    return 0;
}
