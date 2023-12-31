#include <iostream>
#include <chrono>
#include <thread>
struct Timer{

}

void printfunc(){
    for (int i = 0; i < 100 ; i++) {
        std::cout << "HEllo" << std::endl; 
    }
}

int main(int argc, char** argv){
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2s);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << std::endl;
    std::cin.get();
}
