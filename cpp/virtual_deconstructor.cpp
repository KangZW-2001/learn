#include <iostream>

class Base{
    public:
        Base(){std::cout << "Base Constructor \n";}
        // 在父类的析构函数前面加上 ~ ,在delete的时候，就会先调用子类的析构函数，再调用父类的析构函数
        // 在析构函数前面加~，不是重载overload这个析构函数，而是add a deconstructor函数
        virtual ~Base(){std::cout << "Base Deconstructor \n";} 
};

class Derived : public Base{
    public:
        Derived(){std::cout << "Derived constructor \n";}
        ~Derived(){std::cout << "Derived Deconstructor \n";}
};

int main()
{
    Base* base = new Base();
    delete base;
    std::cout << "-------------------" << std::endl;
    Derived* derived = new Derived();
    delete derived;
    std::cout << "-------------------" << std::endl;
    Base* poly = new Derived();
    delete poly;
    std::cout << "-------------------" << std::endl;
    return 0;
}
