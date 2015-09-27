#include <iostream>
#include "shared_ptr.h"
#include <assert.h>


using namespace std;


class TestClass
{
public:
	TestClass(int _id) : id(_id) { 
		cout << "in ctor " << id << endl;
		Count++;
	}

	~TestClass() { 
		cout << "in dtor " << id << endl;
		Count--;
	}
	int id;

public:
	static unsigned int Count;

};

unsigned int TestClass::Count=0;



void test1()
{
	{
		my::shared_ptr<TestClass> sp(new TestClass(4));
		assert(TestClass::Count == 1);
		assert((*sp).id == 4);
		assert(sp->id == 4);

		{
			auto sp2(sp);
			assert(sp2->id == 4);
			sp2->id=3;
			auto sp3 = my::make_shared(new TestClass(5));
			assert(TestClass::Count == 2);
		}
		assert(sp->id == 3);
	}
	assert(TestClass::Count == 0);


}



int main()
{
	test1();
}
