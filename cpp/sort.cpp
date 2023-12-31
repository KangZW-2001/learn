#include <algorithm>
#include <iostream>
#include <vector>
// #include <functional>
typedef unsigned char* byte_pointer;

int main(int argc, char** argv){
    std::vector<int> v = {3,4,56,1,444,12,43};
    std::sort(v.begin(), v.end(), [](int a, int b){
            // true meas a before b, false means b before a
            if(a == 1) return false;
            if(b == 1) return true;
            return a < b;
            });
    for(int i : v)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
