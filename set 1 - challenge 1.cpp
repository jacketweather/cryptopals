#include "util.h"

/*
src: src buffer containing hex characters
dst: buffer to hold converted b64 characters
size: size of the src buffer
*/
void hextobase64(char* src, char* dst, int size) {

	// uninitialized buffer
	if (src == nullptr) {
		return;
	}
	if (size % 3 != 0) {
		return;
	}

	int bufidx = 0;
	const char b64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char term = '\0';

	// get three characters at a time
	for (unsigned int idx = 0; idx < size; idx += 3) {
		
		int one = chartoint(src[idx]);
		int two = chartoint(src[idx + 1]);
		int three = chartoint(src[idx + 2]);

		int c1 = (one << 2) + (two >> 2);
		int c2 = ((two & 3) << 4) + three;

		dst[bufidx] = b64[c1];
		dst[bufidx + 1] = b64[c2];
		bufidx += 2;

	}

	dst[bufidx] = term;
}
