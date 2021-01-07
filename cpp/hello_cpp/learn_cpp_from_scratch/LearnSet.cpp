/** http://www.cplusplus.com/reference/set/set/
 * Sets are containers that store unique elements following a specific order.
 * associative: Elements in associative containers are referenced by their key and not by their absolute position in the container.
 * Ordered: The elements in the container follow a strict order at all times. All inserted elements are given a position in this order.
 * 
 * List:
 *  - constructor set::set()
 *  - set::operator =
 *  - iterator set::begin() / iterator set::end()
 *  - void set::clear()
 *  - int set::count(val), only return 1/0 for set, useful for multiset
 *  - bool set::empty()
 *  - iterator emplace(), simplified insert()
 *  - iterator insert()
 *  - void erase(key/ iterator / range) / void clear() 
 *  - set::iterator find(key)
 *  - void set::swap(set& s)
*/

#include "../../debug_tools/add_header.h"

int main(){

    /** constructor, operator=, set::size()
     * 
    */
    cout << "------------- constructor, operator= ------------" << endl;
    set<int> s1;
    s1.insert(1);
    s1.insert(2);
    DisplaySet(s1);
    // initial set from array
    int arr[] = {1, 2, 4};
    set<int> s2(arr,arr+3);
    DisplaySet(s2);

    set<int> s3=s2;
    s2 = set<int>();
    DisplaySet(s3, "s3");
    DisplaySet(s2, "s2");

    return 0;
}