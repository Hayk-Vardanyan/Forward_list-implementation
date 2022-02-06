#include "forward_list.h"

template<typename iterT>
struct iterator_traits {
 
  typedef typename iterT::category category;
  typedef typename iterT::value_type value_type;    
};


template<typename T>
void List<T>::iterative_reverse()
{
    
    Node* current = head;
    Node* next{}; 
    Node* prev{};

    
    while(current != nullptr)
    {
            next = current->pnext;
            current->pnext = prev;
            
            prev = current;
            
            current = next;
    }
    head = prev;
}


template <typename T>
List<T>::List(const List<T>& rhs)
{
	this -> size = rhs.size;
    
    for(int i = 0; i < size; ++i)
        this -> push_back(rhs[i]);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& rhs)
{

	if(this == &rhs)
		{
			return *this;
		}
    
    clear();
	
 	for(int i = 0; i < rhs.size; ++i)
         this -> push_back(rhs[i]);

	return *this;
}

template <typename T>
List<T>::List(List<T>&& rhs)
{
	this -> size = rhs.size;
	this -> head = rhs.size;
	rhs.head = nullptr;
	rhs.size = 0;
}



template <typename T>
List<T>& List<T>::operator=(List<T>&& rhs)
{
	if(this == &rhs)
		{
			return *this;
		}

	this -> head = rhs.head;
	this -> size = rhs.size;
	rhs.head = nullptr;
	rhs.size = 0;

	return *this;
}



template <typename T>
void List<T>::push_back(const T& data)
{

	if(head == nullptr)
		{
			head = new Node(data);
		}

	else 
		{
			Node* current = head;
				while(current -> pnext)
					{
						current = current -> pnext;
					}
			current -> pnext = new Node(data);
		}
	++size;

}

template <typename T>
void List<T>::push_front(const T& data)
{
	if(head == nullptr)
		{
 			head = new Node(data);
		}

	else
		{
			Node* tmp = head;
			this -> head = new Node(data, head);
		}

++size;
}

template <typename T>
T& List<T>::operator[](int index) const
{
	Node* current = head;

	while(index != 0)
		{
			--index;
			current = current -> pnext;
		}
	return current -> data;
}

template <typename T>
void List<T>::pop_front()
{
	if(head == nullptr)
		{
			throw std::logic_error("List is empty");
		}

	else
		{
			Node* tmp = head;
			head = head -> pnext;
			delete tmp;
		--size;
		}
}

template <typename T>
void List<T>::pop_back()
{
	if(head == nullptr)
		{
			throw std::logic_error("List is empty");
		}

	else
		{
			int tmp = size;
			Node* current = head;
				while(tmp != 1)
					{
						--tmp;
						current = current -> pnext;
					}
			current -> pnext = nullptr;
			delete current -> pnext;
			--size;
		}
}

template <typename T>
void List<T>::insert(int index, const T& data)
{
	if(index == 0)
		{
 			push_front(data);
		}

	else if(index == size)
		{
 			push_back(data);
		}

	else
		{
			Node* current = head;

 				for(int i = 0; i < index - 1; ++i)
  					{
						current = current -> pnext;
  					}

				current -> pnext = new Node(data, current -> pnext);
				++size;
		}

}

template <typename T>
void List<T>::removeAt(int index)
{
	if(index == 0)
		{
			 pop_front();
		}

	else if(index == size - 1)
		{
 			pop_back();
		}

	else
		{
			Node* current = head;

			for(int i = 0; i < index - 1; ++i)
				{
					current = current -> pnext;
				}

			Node* del = current -> pnext;
			current -> pnext = current -> pnext -> pnext;
			delete del;
			--size;
		}
}

template <typename T>
void List<T>::reverse_with_functions()
{
	int tmp = 0;
		while(tmp != size)
			{
				this -> push_front((*this)[tmp]);
				this -> removeAt(tmp + 1);
				++tmp;
			}
}

template <typename T>
void List<T>::sort()
{
	for(int i = 0; i < size; ++i)
			{
				int min = i;

 				for(int j = i + 1; j < size; ++j)
					{
						 if((*this)[j] < (*this)[min])
							{
								min = j;
							}
					}
					std::swap((*this)[i], (*this)[min]);
			}	
}

template <typename T>
void List<T>::merge(List<T>& lst2)
{
	int size2 = lst2.Size();
	int tmp = 1;
	int inserted = 0;
	Node* current = head;
	
	while(true)
		{
			if(size2 == 0) break;
			this -> insert(tmp, lst2[inserted]);
			current = current -> pnext;
			++inserted;
			tmp += 2;
			--size2;
		}
}

template <typename T>
bool List<T>::is_cycle()
{
    int tmp_size = this -> size;
    Node* current = head;
    
    while(tmp_size--)
    {
        current = current -> pnext;
    }
    return current ? true : false;
}

template <typename T>
bool List<T>::empty() const
{
    return (size == 0);
}


template <typename T>
void List<T>::clear()
{
	while(size)
		{
			pop_front();
		}
}

template <typename T>
void List<T>::print() const
{

	for(int i = 0; i < size; ++i)
		{
		    std::cout << (*this)[i] << " ";
		}
}

template<typename iterT, typename Dist>   
void advance(iterT& it, Dist count) {
    
    
    while(count--) 
    {
    ++it;
    }

    
}
