/*
Given a positive integer N, find the Nth fibonacci number. Each number of the sequence is the sum of the 2 preceding ones, starting from 0 and 1, and the starting index being 0.

Examples:

#Input 1: N = 2
#Output 1: 1

#Input 2: N = 5
#Output 2: 5

#Input 3: N = 8
#Output 3: 21

#Input 4: N = 11
#Output 4: 89

#Input 5: N = 15
#Output 5: 610 

#Input 6: N = 25
#Output 6: 75025

#Input 7: N = 45
#Output 7: 1134903170

#Input 8: N = 65
#Output 8: 17167680177565
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>

auto nth_fibonacci(int N) -> unsigned long long {
    if(N < 0) return 0; //Return 0 if negative
    if(N == 0 || N == 1) return N; //For 0th and 1st position

    unsigned long long prev = 0, prev2 = 1, curr {};

    //Computation upto the Nth term
    for(int i = 2; i <= N; i++) {
        curr = prev + prev2;
        prev = prev2;
        prev2 = curr;
    }

    return curr;
}

std::map<int, unsigned long long> mp;

auto nth_fibonacci_2(int N) -> unsigned long long {
    if(N < 0) return 0; //Return 0 if negative
    if(N == 0 || N == 1) return N; //For 0th and 1st position

    if(mp.find(N) != mp.end()) {
        return mp[N];
    }

    unsigned long long res {};
    mp[0] = 0; //For 0th position
    mp[1] = 1; //For 1st postion

    //For even N
    if(N % 2 == 0) {
        int k = N / 2;
        res = 2 * nth_fibonacci_2(k - 1) * nth_fibonacci_2(k) + nth_fibonacci_2(k) * nth_fibonacci_2(k);
    }
    //For odd N
    else {
        int k = (N + 1) / 2;
        res = nth_fibonacci_2(k) * nth_fibonacci_2(k) + nth_fibonacci_2(k - 1) * nth_fibonacci_2(k - 1);
    }
    
    //Storing it for further access
    mp[N] = res;
    
    return res;
}

//Using Binet's formula
auto nth_fibonacci_3(int N) -> unsigned long long {
    if(N < 0) return 0; //Return 0 if negative

    double sqrt_5 = std::sqrt(5); //For getting the square root of 5
    double term_add = (1 + sqrt_5) / 2; //1st term of Binet's formula
    double term_sub = (1 - sqrt_5) / 2; //2nd term of Binet's formula
    double res = (pow(term_add, N) - pow(term_sub, N)) / sqrt_5; //Applying the complete Binet's formula

    //Rounding the result to the nearest integer
    return round(res);
}

TEST(Nth_fibonacci, handles_various_cases) {
    EXPECT_EQ(nth_fibonacci(2), 1);
    EXPECT_EQ(nth_fibonacci(5), 5);
    EXPECT_EQ(nth_fibonacci(8), 21);
    EXPECT_EQ(nth_fibonacci(11), 89);
    EXPECT_EQ(nth_fibonacci(15), 610);
    EXPECT_EQ(nth_fibonacci(25), 75025);
    EXPECT_EQ(nth_fibonacci(45), 1134903170);
    EXPECT_EQ(nth_fibonacci(65), 17167680177565);
}

TEST(Nth_fibonacci_2, handles_various_cases) {
    EXPECT_EQ(nth_fibonacci_2(2), 1);
    EXPECT_EQ(nth_fibonacci_2(5), 5);
    EXPECT_EQ(nth_fibonacci_2(8), 21);
    EXPECT_EQ(nth_fibonacci_2(11), 89);
    EXPECT_EQ(nth_fibonacci_2(15), 610);
    EXPECT_EQ(nth_fibonacci_2(25), 75025);
    EXPECT_EQ(nth_fibonacci_2(45), 1134903170);
    EXPECT_EQ(nth_fibonacci_2(65), 17167680177565);
}

TEST(Nth_fibonacci_3, handles_various_cases) {
    EXPECT_EQ(nth_fibonacci_3(2), 1);
    EXPECT_EQ(nth_fibonacci_3(5), 5);
    EXPECT_EQ(nth_fibonacci_3(8), 21);
    EXPECT_EQ(nth_fibonacci_3(11), 89);
    EXPECT_EQ(nth_fibonacci_3(15), 610);
    EXPECT_EQ(nth_fibonacci_3(25), 75025);
    EXPECT_EQ(nth_fibonacci_3(45), 1134903170);
    EXPECT_EQ(nth_fibonacci_2(65), 17167680177565);
}