int main()  
{    
    List<int> lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);  
    lst.push_front(4);
    lst.recursive_reverse(lst.get_head());
    lst.print();
    
    std::cout << '\n';
    
    List<int> lst2;
    lst2.push_front(4);
    lst2.push_front(77);
    lst2.push_front(99);
    lst2.sort();
    lst2.print();
    
    List<int>::Iterator it = lst.begin();
    iterator_traits<List<int>::Iterator>::value_type i = *it;
    i += 99;
}
