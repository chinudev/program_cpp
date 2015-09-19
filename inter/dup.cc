#include <iostream>
#include <assert.h>
using namespace std;

bool noLetterRepeated2(const char* str)
{
	char found[256];
	for (int i=0; i<256; i++) found[i]=false;

	if (str == NULL) return true;

	while (*str) {
		if (found[*str]) return false;
		found[*str] = true;
		str++;
	}

	return true;
}

bool noLetterRepeated(const char* str)
{
	if (str == NULL) return true;

	while (*str) {
		const char *searchStr = str + 1;
		while (*searchStr) {
			if (*str == *searchStr) return false;
			searchStr ++;
			assert(searchStr - str < 256);
		}
		str++;
	}

	return true;
}

int main(int argc, char* argv[]) 
{
	assert(noLetterRepeated(NULL) == true);
	assert(noLetterRepeated("hello") == false);
	assert(noLetterRepeated("helo") == true);
	assert(noLetterRepeated("abcdefghijlmnopqrstuvwxyz0987654321") == true);
}

