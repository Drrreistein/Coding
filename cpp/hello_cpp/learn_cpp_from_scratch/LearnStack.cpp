/** http://www.cplusplus.com/reference/stack/stack/
 * Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out)
 * 
 * List: 
 *  - constructor(const Container& x), 
 *  - void emplace(args), Adds a new element at the top of the stack, above its current top element
 *  - bool empty(), 
 *  - void pop(),
 *  - void push(),
 *  - size_type size(),
 *  - void swap(stack& x),
 *  - val_type top(),
 
*/

#include "../../debug_tools/add_header.h"

int main()
{
    /**constructor
     * 
    */
    cout << "--------------- constructor -----------------" << endl;
    deque<int> mydeque(3, 100);   // deque with 3 elements
    vector<int> myvector(2, 200); // vector with 2 elements

    stack<int> first;           // empty stack
    stack<int> second(mydeque); // stack initialized to copy of deque

    stack<int, std::vector<int>> third; // empty stack using vector
    stack<int, std::vector<int>> fourth(myvector);
    DisplayStack(first, "first");
    DisplayStack(second, "second");
    cout << "size of first: " << first.size() << '\n';
    cout << "size of second: " << second.size() << '\n';
    cout << "size of third: " << third.size() << '\n';
    cout << "size of fourth: " << fourth.size() << '\n';

    return 0;
}