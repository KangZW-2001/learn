#include <iostream>

struct Vector2 {
    float a, b;
};

struct Vector4{
    union {
        struct {
            float a,b,c,d;
        };    
        struct{
            Vector2 x,y;
        };
    };
};

void printVec2(const Vector2& v)
{
    std::cout << v.a << "," << v.b << std::endl;
}

int main(int argc, char ** argv){
    Vector4 vec4 = {1.0f, 2.f, 3.f, 4.f};
    printVec2(vec4.x);
    printVec2(vec4.y);
    vec4.c = 100.0f;
    std::cout << "AFTER CHANGE : " << std::endl;
    printVec2(vec4.x);
    printVec2(vec4.y);
    // 简单的一个例子--------------------
    struct Union{
        union {
            int a;
            char b;
        };
    };
    Union u;
    u.a = 'a'; // 当改变a的时候，b也会被设置成相应的值也就是 'a'
    std::cout << u.a << "," << u.b << std::endl;

    u.b = 'a' + 3; // 同理，当改变b的时候，a也会被设置成相应的值
    std::cout << u.a << "," << u.b << std::endl;
    return 0;
}
