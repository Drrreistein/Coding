/**
 * http://www.cplusplus.com/reference/map/map/map/
 *
 * Maps are associative containers that store elements formed by a combination of a key value and a mapped value, 
 * following a specific order.
 * 
 * List:
 *  - constructor
 *  - value_type map::at()
 *  - value_type map::operator[]
 *  - pair<map::iterator, bool> map::insert()
 *  - pair<map::iterator, bool> map::emplace()
 *  - map::iterator map::begin() / map::iterator map::end()
 *  - void map::clear() / void map::erase()
 *  - map::iterator map::find() 
 *  - bool map::empty(), !!not implemented
*/

#include "../../debug_tools/add_header.h"

struct classmap
{
    /* compare char */
    bool operator()(const char& lhs, const char& rhs) const{
        return lhs>rhs;
    }
};

int main(){
    // test
    cout << "-------------- test output --------------" << endl;
    
    /** map::map, constructor
     */
    cout << "-------------- constructor --------------" << endl;
    map<char, int> m1;
    m1['a']=1;
    m1['b']=2;
    m1['c']=3;
    m1['d']=4;
    DisplayMap(m1);

    map<char, int> m2(m1.begin(), --m1.end());
    DisplayMap(m2);

    map<char, int> m3(m2);
    DisplayMap(m3);

    map<char, int, classmap> m4;
    m4['a']=1;
    m4['b']=2;
    m4['c']=3;
    m4['d']=4;
    // DisplayMap(m4); // failed, because m4 dont suit for DisPlayMap function
    for (auto& x : m4)
    {
        /* code */
        cout << x.first <<endl;
    }
    
    /** map::at(), 
     * Returns a reference to the mapped value of the element identified with key k. wenn no key, throw error: out of range
    */
    cout << "-------------- map::at --------------" << endl;
    map<string, int> ma1{{"alpha",0},
    {"beta",0},
    {"sigma",0}};
    DisplayMap(ma1);
    ma1.at("alpha")=10;
    ma1.at("beta")=20;
    ma1.at("sigma")=30;
    DisplayMap(ma1);

    /** map::operator[], different from map::at
     * If k matches the key of an element in the container, the function returns a reference to its mapped value.
     * If k does not match the key of any element in the container, the function inserts a new element with that key 
     * and returns a reference to its mapped value(default int value is 0, string value is empty).
    */
    cout << "-------------- map::operator --------------" << endl;
    map<char, int> mop1;
    mop1['a']=10;
    mop1['b']=100;
    mop1['c']=mop1['a'];
    DisplayMap(mop1);
    cout << "d: "<< mop1['d'] <<endl;
    cout <<"map size: "<< mop1.size() << endl; // 
    DisplayMap(mop1);

    /** pair<map::iterator, bool> map::insert, insert single pair / with hint / range
     * check if element already exists before insertion. if yes, insertion failed; if no, insert and return the iterator
    */
    cout << "-------------- map::insert --------------" << endl;
    map<int,int> m_in1;
    // insert single pair
    m_in1.insert(pair<int,int>(10,1)); 
    m_in1.insert(pair<int,int>(20,2));
    m_in1.insert(pair<int,int>(30,3));
    m_in1.insert(pair<int,int>(30,4)); // insert opearation failed, because key already exists.
    DisplayMap(m_in1);
    pair<map<int,int>::iterator, bool> ret;
    // test return value of insert operation
    ret = m_in1.insert(pair<int,int>(30,4)); 
    ret = m_in1.insert(pair<int,int>(40,4));
    if(ret.second == false){
        cout << "element already exists, insertion failed\n";
        cout << "with a value of " << ret.first->second << endl;
    }else{
        cout << "insertion succeeds\n";
        cout << "with a value of " << ret.first->second << endl;
    }
    // insert in the hint position, becasue hint position sometimes is more efficient.
    map<int,int>::iterator it_in = m_in1.begin();
    m_in1.insert(it_in, pair<int,int>(15,1));
    m_in1.insert(it_in, pair<int,int>(50,1));
    DisplayMap(m_in1);
    // range insertion
    map<int,int> m_in2;
    m_in2.insert(m_in1.begin(), m_in1.find(30)); // 
    DisplayMap(m_in2);

    /** map::emplace(key, value), different from map::insert(pair)
     * Inserts a new element in the map if its key is unique. This new element is constructed in place using args
    */
   cout << "-------------- map::emplace --------------" << endl;
    map<char,int> mymap;
    mymap.emplace('x',100);
    mymap.emplace('y',200);
    mymap.emplace('z',100);
    DisplayMap(mymap);

    /** map::begin, map::end
     * map::begin, Returns an iterator referring to the first element in the map container.
     * map::end, Returns an iterator referring to the past-the-end element in the map container.
    */
    cout << "-------------- map::begin/end --------------" << endl;
    map<int, int> mb1;
    mb1[10]=1;
    mb1[20]=2;
    mb1[30]=3;
    for (map<int,int>::iterator it=mb1.begin(); it!=mb1.end(); it++)
    {
        /* code */
        cout << it->first << ": " << it->second << endl;
    }
 
    /** void map::clear / void map::erase
     * void map::clear, remove all element in the map, leaving a container with the size of 0
     * map::erase, remove either one element or a range of elements
    */
    cout << "-------------- map::clear/erase --------------" << endl;
    map<int,int> m_ce;
    m_ce[10]=1;
    m_ce[20]=2;
    m_ce[30]=3;
    m_ce[40]=4;
    m_ce[50]=5;
    m_ce.erase(10); // erase by key 
    DisplayMap(m_ce);
    
    m_ce.erase(m_ce.begin()); // erase by iterator
    DisplayMap(m_ce);
    
    m_ce.erase(m_ce.begin(), m_ce.find(40)); // erase by iterator range
    DisplayMap(m_ce);

    m_ce[10]=1;
    m_ce[20]=2;
    m_ce.clear();
    DisplayMap(m_ce);
    
    /** iterator map::find()
     * return iterator of the found key, or map::end() 
    */
    map<int,int> mf1;
    map<int,int>::iterator it_f;
    mf1[10]=1;
    mf1[20]=2;
    mf1[30]=3;
    mf1[40]=4;
    DisplayMap(mf1);
    it_f = mf1.find(50);
    if(it_f !=mf1.end()){
        mf1.erase(it_f);
        DisplayMap(mf1);
    }
    
    /** map::rbegin() / map::rend()
     * 
    */

   /** void map::swap(map& x)
    * Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
   */
    map<char,int> foo,bar;
    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
    foo.swap(bar);
    DisplayMap(foo);DisplayMap(bar);
    


    return 0;
}