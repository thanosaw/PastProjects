
#include "newMap.h"
#include <iostream>
#include <cassert>
using namespace std;
int main()
{
    Map a(1000);
    Map b(5);
    Map c;
    KeyType k[6] = { "idk", "yes" , " no", "maybe", "probably", "definitely" }; ValueType v = 6;
    // a can hold at most 1000 key/value pairs
    // b can hold at most 5 key/value pairs
    // c can hold at most DEFAULT_MAX_ITEMS key/value pairs
      // No failures inserting pairs with 5 d istinct keys into b
    for (int n = 0; n < 5; n++)
       assert(b.insert(k[n], v));
      // Failure if we try to insert a pair with a sixth distinct key into b
    assert(!b.insert(k[5], v));
      // When two Maps' contents are swapped, their capacities are swapped
      // as well:
    //a.swap(b);
    cout << "passed all tests" << endl;
    
}
