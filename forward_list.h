#include <iostream>
#include "iterators_tag.h"

template <typename T>
class List
{
    
private:  

class Node
{
public:
 
    
	Node() {}
	Node(T data = T(), Node* pnext = nullptr)
		{
			this -> pnext = pnext;
			this -> data = data;
		}

	T data {};
	Node* pnext {};
};

 
public:
  class Iterator {
    public:
      Iterator() {}
      Iterator(Node* ptr){this->ptr = ptr;}
      typedef forward_iterator_tag category;
      typedef T value_type;
      Iterator operator++(int) { 
                                Node* tmp = ptr;
                                ptr = ptr->pnext; 
                                return tmp; }
      Iterator operator++() {ptr = ptr->pnext; return ptr;}
      T operator*() {return ptr->data;} 
      
    private:
        Node* ptr;
        
    };

    
public:
	List(){}
	List(const List<T>&);
	List(List&&);
	~List() {clear();}

public:
	List& operator=(const List<T>&);
	List& operator=(List&&);
	void push_front(const T&);
	T& front() {return head -> data;}
	void pop_front();
	void insert(int, const T&);
	void removeAt(int);
	void sort();
	void merge(List<T>&);
	void traverse(void(*print)()) {print();}
	bool is_cycle();
	int Size() const {return size;}
	void print() const;
	void clear();
	bool empty() const;
	Node* get_head() {return head;}
	Iterator begin() {Iterator it(head); return it;}
	void reverse_with_functions();
	void iterative_reverse();
	Node* recursive_reverse(Node* p) 
{
    if(p->pnext == nullptr)
    {
        head = p;
        return p;
    }  
    Node* tmp = recursive_reverse(p->pnext);
    tmp->pnext = p;
    p->pnext = nullptr;
   
    return tmp->pnext;
}

private:
    int size = 0;
	Node* head {};
	T& operator[](int) const;
    void push_back(const T&);
    void pop_back();

 };
