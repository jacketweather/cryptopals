#pragma once
#include "util.h"

/* convert raw bytes into hex string */
string byteToHex(vector<unsigned char> src) {
	char hex[17] = "0123456789abcdef";
	string dst;

	for (size_t idx = 0; idx < src.size(); ++idx) {
		dst.push_back(hex[src[idx] >> 4]);
		dst.push_back(hex[src[idx] & 15]);
	}
	
	return dst;

}

/* convert character into hex representation */
string charToHex(unsigned char src) {
	char hex[17] = "0123456789abcdef";
	string dst;

	dst.push_back(hex[src >> 4]);
	dst.push_back(hex[src & 15]);

	return dst;
}

/*
* similar to Counter in python; returns key : counts
*/
unordered_map<char, int> Counter(string s) {
	
	unordered_map<char, int> cnt;

	if (s == "") {
		return cnt;
	}

	for (size_t idx = 0; idx < s.size(); ++idx) {
		
		if (cnt.find(s[idx]) == cnt.end()) {
			cnt.emplace(s[idx], 1);
		}
		else {
			cnt[s[idx]] += 1;
		}

	}

	return cnt;

}

/* normalize unordered_map vals*/
unordered_map<char, float> normCounter(unordered_map<char, int> s) {
	// normalize 
	int sum = 0;
	unordered_map<char, float> cnt;
	for (pair<char, int> i : s) {
		sum += i.second;
	}
	for (pair<char, int> i : s) {
		cnt.emplace(i.first, i.second / sum);
	}

	return cnt;

}

float englishDistance(unordered_map<char, float> dist, unordered_map<char, float> sample) {

	float diff = 0;

	for (pair<char, float> ele : sample) {
		if (dist.find(ele.first) == dist.end()) {
			diff += 1;
		}
		else {
			diff += abs(ele.second - dist[ele.first]);
		}
	}

	return diff;

}

void strlower(char* s) {
	if (s == nullptr) {
		return;
	}

	size_t idx = 0;

	while (s[idx] != '\0') {
		if (s[idx] >= 'A' && s[idx] <= 'Z') {
			s[idx] += 32;
		}
		++idx;
	}

}

/* converts hex character into byte representation
*  for example, c -> 12 */
int ctoi(char c) {

	if (48 <= c && c <= 57) {
		return c - 48;
	}

	return c - 97 + 10;

}

/* converts integer into hex character representation
*  for example, 10 -> a */
char itoc(int i) {

	if (0 <= i && i <= 9) {
		return i + 48;
	}
	return (char) (i + 97 - 10);

}


/* compares two string buffers. true if same, false if not */
bool streq(const char* l, const char* r) {

	if (l == nullptr && r == nullptr) {
		return true;
	}
	else if (l == nullptr || r == nullptr) {
		return false;
	}

	size_t idx = 0;
	while (*(l + idx) != '\0' && *(r + idx) != '\0') {
		if (*(l + idx) != *(r + idx)) {
			return false;
		}
		++idx;
	}

	// if either ended early
	if ((*(l + idx) == '\0' && *(r + idx) != '\0') || (*(l + idx) != '\0' && *(r + idx) == '\0')) {
		return false;
	}

	return true;

}