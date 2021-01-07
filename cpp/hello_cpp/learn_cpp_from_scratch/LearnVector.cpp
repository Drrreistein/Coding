/**http://www.cplusplus.com/reference/vector/vector/
 * Vectors are sequence containers representing arrays that can change in size.
 * 
 * List:
 *  - constructor
 *  - assign(Iterator first, Iterator second)/assign(num, val), Assigns new contents to the vector, replacing its current contents
 *  - reference at(), when no, throw error of "out of range"
 *  - val_type back(), front(),
 *  - Iterator begin(), end(),
 *  - size_type capacity(), return the size of space allocated for the vector
 *  - void clear(),
 *  - iterator erase(),
 *  - val_type* data(), Returns a direct pointer pointed to the vector
 *  - void emplace(Iterator position, args), insert a element at position. This new element is constructed using args.
 *  - void insert(iterator position, val_type val) / void insert(iterator position, Iterator first, Iterator second) / void insert(iterator position, num, val_type& val)
 *  - bool empty(),
 *  - operator=,
 *  - operator[],
 *  - void pop_back(),
 *  - void push_back(val_type val),
 *  - void reverse(),
 *  - void resize(size_type n) / void resize(size_type n, val_type val),
 *  - size_type size(),
 *  - void swap(),
 * 
*/
#include "../../debug_tools/add_header.h"

int main(){

    /** constructor
     * 
    */
    cout << "---------------- constructor ----------------\n";
    vector<int> first;DisplayVector(first);                                // empty vector of ints
    vector<int> second (4,100);DisplayVector(second);                       // four ints with value 100
    vector<int> third (second.begin(),second.end());DisplayVector(third);  // iterating through second
    vector<int> fourth (third);DisplayVector(fourth);                       // a copy of third
    int m,n;
    cin >> "intput m, n: " >>m>>n;
    vector<vector<int>> mat(m,n);
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );DisplayVector(fifth);

    /**assign()
     * 
    */
    cout << "---------------- assign ----------------\n";
    vector<int> va1,va2;
    int arr1[]={1,2,4,5};
    va1.assign(5, 10);DisplayVector(va1);
    va2.assign(arr1, arr1+4);DisplayVector(va2);

    /**
     * 
    */


    return 0;
}