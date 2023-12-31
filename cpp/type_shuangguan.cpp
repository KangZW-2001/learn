#include <cstdio>
#include <iostream>
typedef unsigned char * byte_pointer;

struct Entity{
    int x,y;
};

int main(){
    int a = 0xaabbccdd;
    byte_pointer pointer = (byte_pointer)&a;
    for(int i = 0; i < sizeof(int); i++)
        // 按照字节顺序打印a的值，同时可以看出这个机器是“大端”还是“小端”
        printf("%.2x \n", pointer[i]);
    std::cout << "------------------" << std::endl;
    Entity e = {20, 30};
    int * position = (int *)&e;
    for (int i = 0; i < 2; i++) {
        std::cout << position[i] << std::endl;
    }
    return 0;
}
