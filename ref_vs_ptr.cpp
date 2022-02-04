#include <cassert>

/*
 * Question: What really is a reference? 
 *
 * Answer: A pointer points to a location in memory and must be dereferenced prior to being used.
 * A reference, on the other hand, is also a pointer to a location in memory, but it is treated 
 * implicitly as the thing it is pointing to. Examples follows below.
 */

int** testFn(int var, int& ref, int* ptr) {
    assert(var == ref && ref == *ptr);
    //Because var was copied, it exists in a new address
    assert(&var != &ref && &var != ptr);
    assert(&ref == ptr);
    //This will generate a compiler warning because we are returning of
    //stack alloc memory, but that is the point of this exercise 
    return &ptr;
}

int main(){
    //We see from above that the pointer z and the reference ref point to the same memory address.
    int var = 1;
    int& ref = var;
    int* ptr1 = &var; 
    assert(ptr1==&ref);
    assert(*ptr1==var && ref==var);

    var = 2;
    assert(ptr1==&ref);
    assert(*ptr1==2 && ref==2);
    
    //In fact, we can assign the address of a reference to a pointer
    int* ptr2 = &ref;
    assert(ptr2==&var);
    assert(*ptr2==var && ref==var);
    var = 3;
    assert(*ptr2==var && ref==var);

    //What about pass by ref vs pass by ptr?
    int** retPtr = testFn(var, ref, ptr2);
    //This shows that the pointer itself was copied!
    assert (retPtr != &ptr2);
    //So, the benefit of passing by reference rather than value is to prevent any copying
}
