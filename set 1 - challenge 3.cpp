#include "util.h"

/*
* src: source buffer
* length: length of src buffer
* i gave up on using c style strings halfway lol
*/
pair<string, size_t> singleByteXORCipher(const char* src, size_t length) {

	string translated;
	size_t bestKey = 0;
	float minDist = 100;
	unordered_map<char, float> distribution = {
		{'d', 0.03613}, {'o', 0.06494}, {'c', 0.01986}, {'t', 0.07024}, {'y', 0.01796}, 
		{'p', 0.01836}, {'e', 0.10293},  {' ', 0.17046}, {'h', 0.05129}, {'m', 0.02427},
		{'l' , 0.032}, {'u' , 0.02278}, {'b' , 0.01263}, {'i' , 0.05675}, {'w' , 0.01934}, 
		{'r' , 0.05204}, {'a' , 0.06468}, {'n' , 0.0596}, {'s' , 0.05211}, {'q' , 0.00092}, 
		{'v' , 0.00903}, {'x' , 0.00143}, {'k' , 0.00436}, {'g' , 0.01518}, {'f' , 0.01903}, {'z' , 0.00011}, {'j' , 0.00155}
	};

	
	for (size_t test = 1; test < 256; ++test) {
		size_t idx = 0;
		size_t bufidx = 0;
		string buf;
		float diff = 0;

		while (idx < length) {
			// these are raw bytes rn, like 18 59 126
			buf.push_back(test ^ ((ctoi(src[idx]) << 4) + ctoi(src[idx + 1])));
			idx += 2;
		}

		unordered_map<char, float> cnt = normCounter(Counter(buf));
		
		for (pair<char, float> ele : cnt) {
			if (distribution.find(ele.first) == distribution.end()) {
				diff += 1;
			}
			else {
				diff += abs(ele.second - distribution[ele.first]);
			}
		}

		if (diff < minDist) {
			minDist = diff;
			bestKey = test;
			translated = buf;
		}

		buf = "";

	}

	return pair<string, size_t>(translated, bestKey);
	
}