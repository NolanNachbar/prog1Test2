#ifndef MYLIST_
#define MYLIST_
#include "node.h"

int tempNum = 0;
int numComp = 0;
int numCompMiss = 0;
int numFound = 0;
int numNotFound = 0;

template <class T>
class myList
{
    private:
    node<T> * head;
    int size;


    public:
        myList()
        {
            head = nullptr; 
            size = 0;
        
        }
        ~myList()
        {
            while(!isEmpty())
            {
                remove();
            }
        }
        void insert(T item);
        void dictInsert(T item);
        void remove();
        T front();
        T frontMod();
        void print();
        void printNumCompares();
        bool find(T item);
        bool isEmpty()
        {
            if(size == 0)
            {
                return true;
            }
            return false;
        }
        int getSize()
        {
            return size;
        }
};
template <class T>
void myList<T>::insert(T item)
{
    node<T> * tmp = new node<T>(item);
    tmp->next=head;
    head = tmp;

    size++;
};

template <class T>
void myList<T>::printNumCompares()
{
    std::cout << " The matched words had " << numComp << " compares. Average:"  << (numComp/numFound) << "\n";
    std::cout << " The misspelled words had " << numCompMiss << " compares. Average: " << (numCompMiss/numNotFound) << "\n";
    return;
};


template <class T>
void myList<T>::print()
{
    for(node<T> * tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        std::cout << tmp->data << "\n";
    }
};

template <class T>
void myList<T>::remove()
{
    node<T> * tmp;
    if(head != nullptr)
    {
        tmp = head;
        head = head -> next;
     size--;
    }
};

template <class T>
bool myList<T>:: find (T item)
{
    node<T> * tmp;
    std::string stringTemp;

    tmp = head;
    while(tmp != nullptr)
    {
        tempNum++;
        stringTemp = tmp->data;

        int compareVal = stringTemp.compare(item);

        if(compareVal == 0)
        {
            numFound++;
            numComp = numComp + tempNum;
            tempNum = 0;
            return true;
        }

        tmp = tmp ->next;
    }
    numNotFound++;
    numCompMiss = numCompMiss + tempNum;
    tempNum = 0;
    return false;  
}

template <class T>
T myList<T>::front()
{
    if(head != nullptr)
    {
        return head -> data;
    }
    else
    {
        return T(0);
    }
}

template <class T>
T myList<T>::frontMod()
{
    std::string returnVal;
    if(head != nullptr)
    {
        returnVal = head -> data;
        head = head -> next;
        
        return returnVal;
    }
    return T(0);
}
#endif
