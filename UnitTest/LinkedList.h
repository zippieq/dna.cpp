#pragma once
template<class T>
struct Node {
    T m_data;
    Node<T>* m_previous;
    Node<T>* m_next;
};

 

template<class T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int size();
    bool isEmpty();
    T valueAt(int index);
    void pushFront(const T& item);
    void popFront();
    void pushBack(const T& item);
    void popBack();
    T front();
    T back();
    void insert(const T& item, int index);
    void remove(int index);

 

private:
    Node<T> *m_head, *m_tail;
    int m_size;
private:
    void checkIndex(int index);
};

 

template<class T>
LinkedList<T>::LinkedList() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

 

 

template<class T>
LinkedList<T>::~LinkedList() {
    delete m_head;
    m_head = nullptr;
    delete m_tail;
    m_tail = nullptr;
    m_size = 0;
}

 

 

template<class T>
int LinkedList<T>::size() {
    return m_size;
}

 


template<class T>
bool LinkedList<T>::isEmpty() {
    return m_size == 0;
}

 

 

template<class T>
T LinkedList<T>::valueAt(int index) {
    checkIndex(index);
    Node<T>* current = m_head;
    int count = 0;
    while(count != index)
    {
        current = current->m_next;
        count++;
    }
    return current->m_data;
}

 

 

template<class T>
void LinkedList<T>::pushFront(const T& item) {
        Node<T>* newHead = new Node<T>;
        newHead->m_data = item;
        newHead->m_previous = nullptr;
        newHead->m_next = m_head;
        if (m_head != nullptr)
            m_head->m_previous = newHead;
        m_head = newHead;
        if (m_tail == nullptr) m_tail = m_head;
        m_size++;
}

 

template<class T>
void LinkedList<T>::popFront() {
    if(m_head!=nullptr)
    { 
    if(m_size>1)
    m_head = m_head->m_next;
    m_size--;
    }
}

 

template<class T>
void LinkedList<T>::pushBack(const T& item) {

 

    Node<T>* newTail = new Node<T>;
    newTail->m_data = item;
    newTail->m_next = nullptr;

 

    newTail->m_previous = m_tail;
    m_tail = newTail;
    if (m_head == nullptr) m_head = newTail;
    m_size++;
}

 

template<class T>
void LinkedList<T>::popBack() {
    if (m_tail->m_previous != nullptr)
        m_tail = m_tail->m_previous;
    m_tail->m_next = nullptr;
    m_size--;

 

}

 

template<class T>
void LinkedList<T>::checkIndex(int index) {
    if (index<0 || index >= m_size)
    {
        std::out_of_range oor("index is out of range");
        throw oor;
    }
}

 

template<class T>
T LinkedList<T>::front()
{
    if(m_head!=nullptr)
    return m_head->m_data;
    else {
        T a; return a;
    }
}

 

template<class T>
T LinkedList<T>::back() {
    if (m_tail != nullptr)
    return m_tail->m_data;
    else {
        T a; return a;
    }
}

 

template<class T>
void LinkedList<T>::insert(const T& item, int index) {
    checkIndex(index);

 

    Node<T>* current = m_head;
    int count = 0;
    while (count != index)
    {
        current = current->m_next;
        count++;
    }

 

    if (current == m_head)
    {
        m_head->m_next = current;
        m_head->m_previous = nullptr;
    }
    else if (current == m_tail)
    {
        m_tail->m_previous = current;
        m_tail->m_next = nullptr;
    }
    else
    {
        Node<T>* newNode = new Node<T>();
        newNode->m_next = current;
        newNode->m_previous = current->m_previous;
        current->m_previous = newNode;
        newNode->m_data = item;
    }
    m_size++;
}

 

template<class T>
void LinkedList<T>::remove(int index) {
    checkIndex(index);
    Node<T>* current = m_head;
    int count = 0;
    while (count != index)
    {
        current = current->m_next;
        count++;
    }
    if(current!=m_head)
    current->m_next->m_previous = current->m_previous;
    if (current != m_tail)
    current = current->m_next;
    m_size--;
}
















