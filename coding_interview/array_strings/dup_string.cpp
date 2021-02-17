#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

// Assuming ANSI character (no unicode)
// 

bool areAllCharactersUniqueOld(const std::string str) 
{
    unordered_set<char> dupSet;

    for (auto i=0; i < str.size(); i++) {
        if (dupSet.find(str[i]) == dupSet.end()) {
            // character not found
            dupSet.insert(str[i]);
        } else {
            return false;
        }

    }
    return true;
}

// Implementation with bit-mask 

class BitMask {
public: 
    BitMask(unsigned int _maxSize) : maxSize(_maxSize) 
    {
        unsigned int size = ceil(maxSize / sizeof(unsigned int));
        bitArray = new unsigned int[size];
    }
    ~BitMask() 
    {
        delete[] bitArray;
    }

    bool getBit(unsigned int bitPos) 
    {
        if (bitPos > maxSize) {
            throw out_of_range("Bit position out of range");
        }
        unsigned int offset = floor(bitPos/ENTRY_SIZE);
        unsigned int bitOffset = bitPos - offset * ENTRY_SIZE;

        return bitArray[offset] & (1 << bitOffset);
    }

    void setBit(unsigned int bitPos) 
    {
        if (bitPos > maxSize) {
            throw out_of_range("Bit position out of range");
        }
        unsigned int offset = floor(bitPos/ENTRY_SIZE);
        unsigned int bitOffset = bitPos - offset * ENTRY_SIZE;

        bitArray[offset] = bitArray[offset] | (1 << bitOffset);
    }

private:

    constexpr static unsigned int ENTRY_SIZE = sizeof(unsigned int);
    unsigned int maxSize;
    unsigned int* bitArray;

};


bool areAllCharactersUnique(const std::string str) 
{
    BitMask bitMask(256);

    for (auto i=0; i < str.size(); i++) {
        if ( bitMask.getBit( str[i] ) ) return false;
        bitMask.setBit(str[i]);
    }
    return true;
}


int main() 
{
    assert(areAllCharactersUnique(string("")) == true);
    assert(areAllCharactersUnique(string("abcd")) == true);
    assert(areAllCharactersUnique(string("abcda")) == false);
}
