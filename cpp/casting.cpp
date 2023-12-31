#include <cstdio>
#include <iostream>

class Base{
    public:
        Base(){}
        virtual ~Base(){}
};
class DerivedClass1 : public Base{
    public:
        DerivedClass1(){}
        ~DerivedClass1(){}
};
class DerivedClass2 : public Base{
    public:
        DerivedClass2(){}
        ~DerivedClass2(){}
};

int main(){
    int a = (int)5.5; // C类型的转换
    int b = static_cast<int> (5.5); // C++类型的转换有static_cast、dynamic_ const_ re_interpreter几种
                                    
    // 可以利用dynamic_cast检查转换是否成功
    Base* pointer = new DerivedClass1();
    DerivedClass2* pointer_2 = dynamic_cast<DerivedClass2*>(pointer);
    // 肯定是失败的，因为pointer指向的是DerivedClass1
    if(pointer_2){
        std::cout << "SUCCESS\n";
    }
    else{
        std::cout << "FAILED\n";
    }
    std::cout << "----------------------------------\n";
    // re_interpreter_cast是重新解释这个指针的内容，不发生传唤 和“类型双关”一样
    int c = 0xaabbccdd;
    // char* byte_pointer = static_cast<char*> (&c); // 使用static_cast会报错
    // char* byte_pointer1 = reinterpret_cast<char*> (&c);
    char* byte_pointer1 = ( char*) (&c);
    std::cout << sizeof(byte_pointer1[0]) <<std::endl;

    for(unsigned int i = 0; i < sizeof(int); i++)
        printf("%.2x\n", byte_pointer1[i]); 

    return 0;
}
