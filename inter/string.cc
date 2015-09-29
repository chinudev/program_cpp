#include <iostream>
#include <assert.h>

using namespace std;



void myswap(char& a, char&b)
{
	char temp = a;
	a = b;
	b = temp;
}

// reverse string
void reverseString( char* str) 
{
	if (str == nullptr) return;

	int len = strlen(str);
	char *start = str;
	char *end = str+len-1;

	while (start < end) {
		myswap(*start, *end);
		start++; end--;
	}
}

void testReverse()
{
	char a[] {"Hello"};
	reverseString(a); 
	assert( strcmp(a,"olleH") == 0);

	char b[] {"H"};
	reverseString(b); 
	assert( strcmp(b,"H") == 0);

	char c[] {"He"};
	reverseString(c); 
	assert( strcmp(c,"eH") == 0);

	char d[] {""};
	reverseString(d); 
	assert( strcmp(d,"") == 0);

	reverseString(nullptr);
}

//////

void replaceSpace(char str[], unsigned int len)
{
	if (str == nullptr) return;

	// count number of spaces
	int numSpaces = 0;
	for (int i=0; i < len; i++) {
		if (str[i] == ' ') numSpaces++;
	}
	if (numSpaces == 0)  return; 

	// start copying out the 
	char *fromPtr = &str[len-1];
	char *toPtr = &str[len-1+2*numSpaces];

	// terminate the string
	str[len+2*numSpaces] ='\0';

	while (fromPtr >= str) {
		if (*fromPtr != ' ') { 
			*toPtr = *fromPtr;
		} else {
			// This character is a space
			*toPtr = '0'; toPtr--;
			*toPtr = '2'; toPtr--;
			*toPtr = '%'; 

			numSpaces--;
		}
		toPtr--;
		fromPtr--;

		if (numSpaces ==0) {
			assert(fromPtr == toPtr);
			break;
		}
	}


}

void testReplaceHelper(const char *in, const char* result)
{
	char str[100];
	strcpy(str,in);
	replaceSpace(str,strlen(in));
	assert(strcmp(str, result) == 0);
}

void testReplaceSpace()
{

	replaceSpace(nullptr,0);
	testReplaceHelper("","");
	testReplaceHelper(" ","%20");
	testReplaceHelper(" John ","%20John%20");
	testReplaceHelper("Mr John Smith","Mr%20John%20Smith");
}


//
// Given a character array find index for the character that is repeated most often. 
//   
int findMaxRepeatedCharSeq(const char* str)
{
	if (str == nullptr) return -1;
	if (*str == '\0') return -1;   //empty string


	uint32_t    currCharIndex  = 0;
	uint32_t    currStartIndex = 0;
	char        currChar       = *str;
	uint32_t    currSeqLen     = 0;

	uint32_t    maxSeqLen   = 0;
	uint32_t    maxSeqIndex = 0;

	while (*str) {
		if (*str == currChar) {
			currSeqLen++;
		} else {
			if (currSeqLen > maxSeqLen) {
				maxSeqLen = currSeqLen;
				maxSeqIndex = currStartIndex;
			}
			currStartIndex = currCharIndex;
			currChar       = *str;
			currSeqLen     = 1;
		}

		currCharIndex++;
		str++;
	}
	if (currSeqLen > maxSeqLen) {
		return currStartIndex;
	} else {
		return maxSeqIndex;
	}
}

void testMaxRepeatSeq()
{
	assert(findMaxRepeatedCharSeq(nullptr) == -1);

	{
		const char *str = "";
		assert(findMaxRepeatedCharSeq(str) == -1);
	}

	{
		const char *str = "a";
		assert(findMaxRepeatedCharSeq(str) == 0);
	}
	{
		const char *str {"aabb"};
		assert(findMaxRepeatedCharSeq(str) == 0);
	}
	{
		const char *str {"aabbb"};
		assert(findMaxRepeatedCharSeq(str) == 2);
	}

}

int main()
{
	//testReverse();
	//testReplaceSpace();
	testMaxRepeatSeq();
}
