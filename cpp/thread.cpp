#include <iostream>
#include <thread>

static bool is_working = true;
void printSomething(){
    using namespace std::literals::chrono_literals;
    std::cout << "Start Thread : " << std::this_thread::get_id() << std::endl;
    while(is_working){
        std::cout << "Working...." << std::endl;
        std::this_thread::sleep_for(1s);
    }
    std::cout << std::endl << "END" << std::endl;
}

int main(){
    std::cout << "Start Thread : " << std::this_thread::get_id() << std::endl;
    std::thread worker(printSomething);
    std::cin.get();
    is_working = false;
    worker.join();
    std::cin.get();
    return 0;
}
