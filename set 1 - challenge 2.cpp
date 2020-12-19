#include "util.h"


/* fixed size xor given two buffers
*  s1: first string
*  s2: second string
*  dst: buffer to store result in
*  length: length of s1 and s2 (individually) */

void fixedxor(const char* s1, const char* s2, char* dst, size_t length) {

	char term = '\0';

	for (size_t i = 0; i < length; ++i) {
		dst[i] = inttochar(chartoint(s1[i]) ^ chartoint(s2[i]));
	}
	dst[length] = term;
}