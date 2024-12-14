/*
You are given a phone number represented as a numeric string and a list of words. Each word can be converted into a numeric representation based on the standard phone keypad mapping:

a, b, c -> 2
d, e, f -> 3
g, h, i -> 4
j, k, l -> 5
m, n, o -> 6
p, q, r, s -> 7
t, u, v -> 8
w, x, y, z -> 9

Your task is to write a function that checks whether the numeric representation of each word in the list is a substring of the given phone number. The function should return a vector of booleans where each boolean corresponds to a word in the list:
true if the numeric representation of the word is found in the phone number,
false otherwise.

Examples:

#Input 1: phone_num = "3662277815781519518916891", words = ["foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"]
#Output 1: true true false true true true true false
*/

#include <iostream>
#include <vector>
#include <gtest/gtest.h>

auto string_contain(std::string phone_num, std::vector<std::string>& words) -> std::vector<bool> {
    if(words.size() == 0) return {};

    int len = words.size();
    std::vector<bool> bool_contain(len, false);

    for(int i = 0; i < len; i++) {
        for(int j = 0; j < words[i].length(); j++) {
            switch(words[i][j]) {
                case 'a': case 'b': case 'c': words[i][j] = '2'; break;
                case 'd': case 'e': case 'f': words[i][j] = '3'; break;
                case 'g': case 'h': case 'i': words[i][j] = '4'; break;
                case 'j': case 'k': case 'l': words[i][j] = '5'; break;
                case 'm': case 'n': case 'o': words[i][j] = '6'; break;
                case 'p': case 'q': case 'r': case 's': words[i][j] = '7'; break;
                case 't': case 'v': case 'u': words[i][j] = '8'; break;
                case 'w': case 'x': case 'y': case 'z': words[i][j] = '9'; break;     
            }
        }
    }

    for(int i = 0; i < len; i++) {
        if(phone_num.find(words[i]) != std::string::npos) bool_contain[i] = true;
    }

    return bool_contain;
}

TEST(String_contain, handles_various_cases) {
    std::vector<std::string> words {"foo", "bar", "baz", "foobar", "emo", "cap", "car", "cat"};
    std::vector<bool> result {true, true, false, true, true, true, true, false};
    
    EXPECT_EQ(string_contain("3662277815781519518916891", words), result);
}