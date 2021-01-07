/** http://www.cplusplus.com/reference/list/list/
 * list::list
 * Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
 * 
 * List:
 *  - constructor
 *  - void assign()
 *  - reference back(), Returns a reference to the last element in the list container.
 *  - reference front(),
 *  - iterator  begin(), Returns an iterator pointing to the first element in the list container.
 *  - iterator end(), 
 *  - void clear(), remove all elements
 *  - iterator erase(iterator position) / iterator erase(iterator position)
 *  - void remove(val_type value)
 *  - iterator emplace(), The container is extended by inserting a new element at position
 *  - bool empty()
 *  - iterator insert(iterator position, value), inserting new elements before the element at the specified position.
 *  - merge(list& x), Merges x into the list by transferring all of its elements at their respective ordered positions(both containers shall already be ordered).
 *  - pop_back() / pop_front(), remove element
 *  - push_back() / push_front(), add element
 *  - remove_if(Predicate pred), 
 *  - void resize(num); void resize(num, value), Resizes the container so that it contains n elements.
 *  - void reverse(), Reverses the order of the elements in the list
 *  - void sort(), void sort(Compare comp), 
 *  - void splice(Iterator position, list& x), void splice(Iterator position, list& x, Iterator position), void splice(Iterator position, list& x, Iterator first, Iterator second),  
 *  - void swap(list&x )
 *  - void unique().
 * 
*/

#include "../../debug_tools/add_header.h"

bool mycomparison (double first, double second)
{ return ( int(first)>int(second) ); }

bool is_odd(const int& num){return (num%2);} // function as predicate
struct is_even{ // struct as predicate 
    bool operator() (const int& num){return (num%2)==0;}
};

int main()
{
    /** constructors used in the same order as described above
     * 
    */
   cout << "-------------- constructor ---------------" << endl;
    list<int> first; // empty list of ints
    list<int> second(4, 100);                                                 // four ints with value 100
    list<int> third(second.begin(), second.end());                            // iterating through second
    list<int> fourth(third);                                                  // a copy of third
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    //   list<int> fifth (myints, myints +2);
    DisplayList(first, "first");
    DisplayList(second, "second");
    DisplayList(third, "third");
    DisplayList(fourth, "fourth");
    DisplayList(fifth, "fifth");

    /** assign()
     * Assigns new contents to the list container, replacing its current contents
    */
   cout << "-------------- assign ---------------" << endl;
    first.assign(7, 100); // 7 ints with value 100
    second.assign(first.begin(), first.end()); // a copy of first
    int myints1[] = {1776, 7, 4};
    third.assign(myints1, myints1 + 3); // assigning from array
    DisplayList(first, "first");
    DisplayList(second, "second");
    DisplayList(third, "third");

    /** emplace()
     *   iterator emplace (const_iterator position, Args&&... args);
    */
   cout << "-------------- emplace ---------------" << endl;
    list<pair<int,char>> lm;
    lm.emplace(lm.begin(), 100, 'a');
    lm.emplace(lm.begin(), 200, 'b');
    cout << lm.begin()->first << " " << lm.begin()->second << endl;
    // DisplayList(lm);

    /** insert()
     * single element: iterator insert (const_iterator position, const value_type& val);
     * fill: iterator insert (const_iterator position, size_type n, const value_type& val);
     * range: template <class InputIterator>, iterator insert (const_iterator position, InputIterator first, InputIterator last);
    */
    cout << "-------------- insert ---------------" << endl;
    list<int> li;
    list<int>::iterator it_i;
    for (size_t i = 0; i < 5; i++)
        li.push_back(i);
    DisplayList(li, "li");
    
    it_i = li.begin();
    li.insert(it_i, 10);
    DisplayList(li, "li");
    
    li.insert(it_i, 3, 20);
    DisplayList(li, "li");

    vector<int> vec(3,100);
    li.insert(it_i,vec.begin(),vec.end());
    DisplayList(li, "li"); 

    /** merge(list& x)
     * Merges x into the list by transferring all of its elements 
     * at their respective ordered positions into the container
    */
    cout << "-------------- merge ---------------" << endl;
    list<int> lm1, lm2;
    lm1.push_back(3);lm1.push_back(1);lm1.push_back(5);
    lm2.push_back(4);lm2.push_back(6);lm2.push_back(2);
    lm1.sort(); lm2.sort();
    lm1.merge(lm2); // merge  
    // lm2 is now empty
    DisplayList(lm1);DisplayList(lm2);
    
    lm2.push_back(7);
    lm1.merge(lm2,mycomparison);
    DisplayList(lm1);

    /** remove_if()
     * Removes from the container all the elements for which Predicate pred returns true. This calls the destructor of these objects.
    */
   cout << "-------------- remove / remove_if ---------------" << endl;
   int arr1[] = {12, 23,10, 32, 8, 11};
   list<int> lr1, lr2;
   lr1.assign(arr1, arr1+6);
   DisplayList(lr1);
   lr1.remove_if(is_odd);
   DisplayList(lr1);
   lr1.remove_if(is_even()); // ?? struct class 
   DisplayList(lr1);

   /** resize()
    * Resizes the container so that it contains n elements.
   */
   cout << "-------------- resize ---------------" << endl;
   list<int> ls;
   for (size_t i = 0; i < 10; i++)
    ls.push_back(i);
   DisplayList(ls);
   ls.resize(5);DisplayList(ls);
   ls.resize(8,100); DisplayList(ls);
   ls.resize(12); DisplayList(ls);

    return 0;
}