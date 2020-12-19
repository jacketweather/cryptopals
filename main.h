#pragma once
#include "util.h"
#include <stdio.h>
#include <assert.h>

void hextobase64(char* src, char* dst, int size);
void fixedxor(const char* s1, const char* s2, char* dst, size_t length);
pair<string, size_t> singleByteXORCipher(const char* src, size_t length);
