#pragma once 

namespace my {

using namespace std;

template <typename T> 
class shared_ptr 
{
public:
	shared_ptr(): sharedCount(nullptr), rawPtr(nullptr) {}

	shared_ptr(T* ptr): rawPtr(ptr) {
		sharedCount = new uint32_t(1);
	}

	shared_ptr(const shared_ptr<T> & sp) : sharedCount(sp.sharedCount), rawPtr(sp.rawPtr)  {
		if (sharedCount == nullptr) (*sharedCount)++;
	}

	shared_ptr<T>& operator= (const shared_ptr<T>& sp) {
		if (sp.rawPtr == rawPtr) return;

		// remove old contents
		decrCount();

		// add new contents
		rawPtr = sp.rawPtr;
		sharedCount = sp.sharedCount;
		if (sharedCount == nullptr) (*sharedCount)++;
	}

	~shared_ptr() { decrCount(); }

	T& operator* () { 
		if (sharedCount == nullptr) throw std::runtime_error("de-referencing null sharead pointer");
		return *rawPtr;
	}

	T* operator-> () { 
		if (sharedCount == nullptr) throw std::runtime_error("de-referencing null sharead pointer");
		return rawPtr;
	}
	
private:
	void decrCount() {
		if (sharedCount == nullptr) return;
		(*sharedCount)--;
		if (*sharedCount == 0) {
			delete sharedCount;
			delete rawPtr;
		}
	}


	uint32_t* sharedCount;
	T* rawPtr;
};



template <typename T>
shared_ptr<T>  make_shared(T *ptr) 
{
	return shared_ptr<T>(ptr);
}





}
