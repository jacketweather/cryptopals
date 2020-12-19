#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int								ctoi(char c);
char							itoc(int i);
bool							streq(const char* l, const char* r);
unordered_map<char, int>		Counter(string s);
unordered_map<char, float>		normCounter(unordered_map<char, int> s);
float							englishDistance(unordered_map<char, float> dist, unordered_map<char, float> sample);
void							strlower(char* s);
string							byteToHex(vector<unsigned char> src);
string							charToHex(unsigned char src);
