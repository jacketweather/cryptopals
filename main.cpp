#include "main.h"
#include "test.h"

void tests1c1(void) {

	char arr[97] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char ans[65] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
	char buffer[65];

	hextobase64(arr, buffer, sizeof(arr) - 1);
	assert(streq(ans, buffer) == true);

}

void tests1c2(void) {
	char s1[37] = "1c0111001f010100061a024b53535009181c";
	char s2[37] = "686974207468652062756c6c277320657965";
	char ans[37] = "746865206b696420646f6e277420706c6179";
	char buf[37];

	fixedxor(s1, s2, buf, sizeof(s1) - 1);
	assert(streq(buf, ans) == true);

}

void tests1c3(void) {
	char src[69] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

	pair<string, size_t> answer = singleByteXORCipher(src, sizeof(src) - 1);
	cout << "Answer is " << answer.first << " with key " << answer.second << "\n";

}

int main(void) {

	teststrcmp();
	printf("Passed util funcs tests.\n");
	tests1c1();
	tests1c2();
	tests1c3();
	printf("Passed all tests.\n");
	getchar();

	return 0;
}