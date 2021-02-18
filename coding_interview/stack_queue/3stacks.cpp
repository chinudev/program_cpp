



class AllocatorInterface 
{
public:
    virtual char* alloc()=0;
    virtual void free(char*)=0;
    virtual ~getBlockSize()=0;

    virtual ~AllocatorInterface() {}; 
};


// Manages memory in blocks. 
template <int BlockSize, int NumberOfBlocks> 
class BlockPool
{
public: 
    BlockPool();

    virtual char* alloc();
    virtual void free(char* block);
    virtual getBlockSize() { return BlockSize; } 

private: 
    char pool[BlockSize*NumberOfBlocks];
};


template <typename T> 
class Stack
{
public: 
    Stack( AllocatorInterface* allocator): 
        allocator(_allocator), 
        blockSize(_allocator.getBlockSize()),
        maxEntries(floor( blockSize - sizeof(char*)) / sizeof(T)), 
        currEntries(0), 
        currentBlock(nullptr),
        numBlocks(0)
    {
        if (maxEntries < 1) throw std:exception("Can't fit into specified block");

        char* block = allocator.alloc();
        if (block == nullptr) throw std:exception("Unable to create");

        currentBlock = static_cast<BlockType*> block;
        currentBlock.prev = nullptr;
    }

    ~Stack() 
    {
        allocator.free(currentBlock);
    }

    void push(T value) 
    {
        if (currEntries >= maxEntries) {
            _allocateBlock();
        }
        currentBlock.fieldArray[currEntries] = value;
        currEntrie++;
        assert(currEntries <= maxEntries);
    }

    T pop() 
    {
        if (currEntries < 1) {
            _freeBlock();
        }
        if (currEntries <= 0) throw std::exception("popping empty stack");

        return currentBlock.fieldArray[currEntries--];
    }

    int size() 
    {
        return (numBlocks * maxEntries + currEntries);
    }

private:

    void _allocateBlock() 
    {
        char* block = allocator.alloc();
        if (block == nullptr) throw std:exception("Unable to create");

        BlockType* newBlock = static_cast<BlockType*> block;
        newBlock.prev = currentBlock;
        currEntries = 0;
        currentBlock = newBlock;
        numBlocks++;
    }

    void _freeBlock()
    {
        BlockType* newBlock = currentBlock.prev;
        if (newBlock == nullptr) 
        {
            // We always keep one block allocated.
            return;
        }

        allocator.free(currentBlock);
        currentBlock = newBlock;
        currEntries = maxEntries;
        numBlocks--;
        assert(numBlocks > 0);
    }


private:
    const AllocatorInterface* allocator;
    const int blockSize;
    const int maxEntries;

    int numBlocks;             // Number of blocks allocated. Should always be greater than 1. 
    int currEntries;           // Number of entries in the current block.
    BlockType* currentBlock;


    struct BlockType 
    {
        char* prev;
        T[] fieldArray;
    };
};




