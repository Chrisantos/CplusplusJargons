#include<iostream>

typedef int Length;

template <typename T>
inline T maximus(T const &a, T const &b);

int main() {

    //Length l = 30;
    //std::cout<<l;

    std::cout<<maximus<double>(11, 12.3);


    return 0;
}

template <typename T>
inline T maximus(T const &a, T const &b) {
    return a > b? a : b;

}
