#include <iostream>
#include <assert.h>
using namespace std;

class CharSet
{
public:
	CharSet(const char* str) {
		for (int i=0; i < MAX_CHARS; i++) {
			charCount[i]=0;
		}

		if (str == NULL) {
			return;
		}

		while (*str) {
			charCount[*str]++;
			str++;
		}
	}

	bool operator ==(const CharSet& set2) const {
		for (int i=0; i < MAX_CHARS; i++) {
			if (this->charCount[i] != set2.charCount[i]) {
				return false;
			}
		}
		return true;
	}

private:
	const static unsigned int MAX_CHARS = 256;
	char charCount[MAX_CHARS];
	
};


bool isPermutation(const char* str1, const char* str2)
{
	CharSet s1(str1);
	CharSet s2(str2);
	return (s1 == s2);
}

int main(int argc, char* argv[]) 
{
	assert(isPermutation("apple","peal") == false);
	assert(isPermutation(NULL,NULL) == true);
	assert(isPermutation("abcdabcd","aabbccdd") == true);
	assert(isPermutation("","ab") == false);
	assert(isPermutation("","") == true);

}
