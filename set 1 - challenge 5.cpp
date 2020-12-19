#include "util.h"

string repeatingKeyXOR(string src, string key) {

	string dst;
	// string storage kinda pepega, should use vector honestly
	// also no more str -> hex str -> bytes... let's do better
	for (size_t idx = 0; idx < src.size(); ++idx) {

		string keyHex = charToHex(key[idx % key.size()]);
		string srcHex = charToHex(src[idx]);
		for (size_t c = 0; c < keyHex.size(); ++c) {
			dst.push_back(itoc(ctoi(keyHex[c]) ^ ctoi(srcHex[c])));
		}

	}
	
	return dst;

}