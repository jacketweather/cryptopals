#include "util.h"
#include <fstream>



 string challenge4(void) {

	string line;
	fstream file("../data/s1p4.txt");

	if (!file) {
		return "";
	}

	string translated;
	float minDist = 1000;
	unordered_map<char, float> distribution = {
		{'d', 0.03613}, {'o', 0.06494}, {'c', 0.01986}, {'t', 0.07024}, {'y', 0.01796},
		{'p', 0.01836}, {'e', 0.10293},  {' ', 0.17046}, {'h', 0.05129}, {'m', 0.02427},
		{'l' , 0.032}, {'u' , 0.02278}, {'b' , 0.01263}, {'i' , 0.05675}, {'w' , 0.01934},
		{'r' , 0.05204}, {'a' , 0.06468}, {'n' , 0.0596}, {'s' , 0.05211}, {'q' , 0.00092},
		{'v' , 0.00903}, {'x' , 0.00143}, {'k' , 0.00436}, {'g' , 0.01518}, {'f' , 0.01903}, {'z' , 0.00011}, {'j' , 0.00155}
	};

	while (getline(file, line)) {

		float totaldiff;

		for (size_t test = 0; test < 256; ++test) {
			size_t idx = 0;
			size_t bufidx = 0;
			string buf;
			float diff;

			while (idx < line.length()) {
				// these are raw bytes rn, like 18 59 126
				buf.push_back(test ^ ((ctoi(line[idx]) << 4) + ctoi(line[idx + 1])));
				idx += 2;
			}

			unordered_map<char, float> cnt = normCounter(Counter(buf));
			diff = englishDistance(distribution, cnt);

			if (diff < minDist) {
				minDist = diff;
				translated = buf;
			}

			buf = "";

		}

	}

	return translated;

}