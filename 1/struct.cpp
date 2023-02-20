#include <iostream>

struct StructExample
{
    void print() {
        a = 3; b = 5;
        std::cout<<  "A = " <<a <<", B = " <<b <<std::endl;
    }

private:
    int a, b;
};

int main() {
    StructExample se;
    se.print();
    return 0;
}
