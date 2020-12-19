#include "test.h"

void teststrcmp(void) {

	assert(streq("hello", "hello") == true);
	assert(streq("", "") == true);
	assert(streq("", "a") == false);
	assert(streq("a", "") == false);
	assert(streq("sdfsa", "sadfas") == false);
	assert(streq("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", "") == false);
	assert(streq("3490ujrhwpnuife;lkemdbrfnydtj'pokrhi;5e", "3490ujrhwpnuife;lkemdbrfnydtj'pokrhi;5e") == true);
	assert(streq("ttvozcspkxrvvcvitmksovltpiwljyjn"
					"eytqyfiwnfxucdqgwcqcppcsvweteosz"
					"azimlxwifujngrwvuritnmjhsxzejmui"
					"jpexjfeiljknuuzzulidjejbiyeyfzyz"
					"tshrgkkphoxejvoshlwgzseqbalvtmmm",
					"ttvozcspkxrvvcvitmksovltpiwljyjn"
					"eytqyfiwnfxucdqgwcqcppcsvweteosz"
					"azimlxwifujngrwvuritnmjhsxzejmui"
					"jpexjfeiljknuuzzulidjejbiyeyfzyz"
					"tshrgkkphoxejvoshlwgzseqbalvtmmm") == true);
	assert(streq("lkj:nsdfnlkslnljkf9348th5ugirtbnjkd;klsfn fsjdlasdjl ;fjls;d jfassnqui2h78e39rw04eifgptfbokvmdjncshbA",
					"lkj:nsdfnlkslnljkf9348th5ugirtbnjkd;klsfn fsjdlasdjl ;fjls;d jfassnqui2h78e39rw04eifgptfbokvmdjncshbA") == true);
	assert(streq("f", "f ") == false);
	assert(streq("f", " f ") == false);
	assert(streq("", "A") == false);
	assert(streq("a", "A") == false);
	assert(streq("1", " 1") == false);
	assert(streq("1", " 1 ") == false);
	assert(streq(" 1", " 1 ") == false);
	assert(streq("2", "22") == false);
	assert(streq("hi", "hit") == false);
	assert(streq("onetwothree", "onetwot") == false);
}



void testHammingDistance(void) {

	vector<unsigned int> v1 = bytes("this is a test");
	vector<unsigned int> v2 = bytes("wokka wokka!!!");
	assert(hammingDistance(v1, v2) == 37);
	assert(hammingDistance(vector<unsigned int>(bytes("aaa")), vector<unsigned int>(bytes("aaa"))) == 0);
	assert(hammingDistance(vector<unsigned int>(bytes("aab")), vector<unsigned int>(bytes("aaa"))) == 2);
	assert(hammingDistance(vector<unsigned int>(bytes("aa")), vector<unsigned int>(bytes("aaa"))) == 8);
	assert(hammingDistance(vector<unsigned int>(bytes("ab")), vector<unsigned int>(bytes("aaa"))) == 10);
	assert(hammingDistance(vector<unsigned int>(bytes("a")), vector<unsigned int>(bytes("aaa"))) == 16);
	assert(hammingDistance(vector<unsigned int>(bytes("b")), vector<unsigned int>(bytes("aaa"))) == 18);
	assert(hammingDistance(vector<unsigned int>(bytes("")), vector<unsigned int>(bytes("aaa"))) == 24);

}