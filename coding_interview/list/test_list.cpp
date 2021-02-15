
#include "list.hpp" 


void test_makeList() 
{
    {
        // We need to explicitly provide template type in absence of any arguments
        auto head = makeList<int>({});
        printList(head);
    }
    {
        auto head = makeList({1,3,4});
        printList(head);
    }
    {
        auto head = makeList({"apple", "orange", "banana", "wow"});
        printList(head);
    }
}

void test_compare()
{
    {
        auto head1 = makeList({1,2,3});
        auto head2 = makeList({"apple"});
        auto head3 = makeList({1,2,3});
        auto head4 = makeList<int>({});
        auto head5 = makeList({1,2,3,4});
        auto head6 = makeList({1,2});

        // This code doesn't compile because the two lists are templatized with different types.
        //    As expected but highlights the benefit of strong typing.
        //assert(compareList(head1, head2) == false);
        printList(head1);
        printList(head3);
        assert(compareList(head1, head3) == true);
        assert(compareList(head1, head3) == true);
        assert(compareList(head4, head4) == true);
        assert(compareList(head1, head3) == true);
        assert(compareList(head1, head5) == false);
        assert(compareList(head1, head6) == false);
    }
    {
        auto head1 = makeList({"apple", "orange", "banana", "wow"});
        auto head2 = makeList({"apple", "orange", "banana", "wow"});
        auto head3 = makeList({"apple", "orange", "banana"});
        assert(compareList(head1, head2) == true);
        assert(compareList(head1, head3) == false);
    }
}


int main(void) 
{
    test_makeList();
    test_compare();
}
