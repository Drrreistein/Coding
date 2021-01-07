/** http://www.cplusplus.com/reference/queue/queue/ 
 * FIFO queue
 * queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), 
 * where elements are inserted into one end of the container and extracted from the other.
 * 
 * List: 
 *  - constructor
 *  - reference& front(), first pushed element of the q
 *  - reference& back(), last pushed element of the q
 *  - bool empty()
 *  - void pop()
 *  - void push(value)
 *  - size_type size()
 *  - void swap(queue& x)
*/
#include "../../debug_tools/add_header.h"

int main ()
{
    /** constructor, initiailization from deque or list
     * 
    */
    cout << "------------ constructor ---------------" << endl;
    deque<int> mydeck (3,100);        // deque with 3 elements
    list<int> mylist (2,200);         // list with 2 elements
    
    queue<int> first;                 // empty queue
    queue<int> second (mydeck);       // queue initialized to copy of deque    
    queue<int,std::list<int> > third; // empty queue with list as underlying container
    queue<int,std::list<int> > fourth (mylist); // queue initialized to copy of list   
    DisplayQueue(first, "first");
    DisplayQueue(second, "second");
    
    /** 
     * 
    */
    



    return 0;
}