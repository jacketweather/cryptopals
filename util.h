#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

int chartoint(char c);
char inttochar(int i);
bool streq(const char* l, const char* r);
unordered_map<char, int> Counter(string s);
unordered_map<char, float> normCounter(unordered_map<char, int> s);
void strlower(char* s);

