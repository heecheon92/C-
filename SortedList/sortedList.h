// File:    sortedList.h
// Name:    Heecheon Park
// Program: prog
// Date:    March 25th, 2019

/*  
This file contains declarations of templated sortedList class (modified singly linkedlist) and its implementation.
Since this is a templated class, there is no description in the main.cpp
*/

#ifndef _SORTED_LIST_H
#define _SORTED_LIST_H
#include <iostream>
#include <cassert>
using namespace std;

namespace sortedListSpace
{
    enum listStructure {ASCENDING, DESCENDING};

    template <typename T>
    struct nodeType
    {
        T info;
        nodeType<T> *link;
    };

    template <typename T>
    class sortedList
    {
        public:
            /*
            method - constructor.
            description - construct a new sortedList instance.
            preconditions - This file must be included in a main file.
            postconditions - sortedList object will be created.
            method input - none 
                         - enum (sorting type: ASCENDING / DESCENDING)
                         - sortedList (As a copy constructor)
            method output - sortedList object
            */
            sortedList();
            sortedList(listStructure);
            sortedList(const sortedList<T>& otherSortedList);
            /*
            method - destructor.
            description - deallocate heap memory from a sortedList instance.
            preconditions - This file must be included in a main file.
            postconditions - Allocated memory will be freed.
            method input - void
            method output - void
            */
            ~sortedList();
            /*
            method - accessor.
            description - returns the number of items in the list.
            preconditions - sortedList object must exist.
            postconditions - length of the object will return.
            method input - void
            method output - int (size or length)
            */
            int length() const;
            /*
            method - sort, mutator.
            description - sorts the sortedList.
            preconditions - sorting type must be specified.
            postconditions - sorts the list based on the sorting type.
            method input - enum (ASCENDING / DESCENDING)
            method output - void
            */
            void sort(listStructure);
            /*
            method - swap, mutator.
            description - swap two nodes in the sortedList.
            preconditions - two nodes to be swapped must exist.
            postconditions - swaps the nodes by info not by links.
            method input - nodeType<T> *, nodeType<T> *
            method output - void
            */
            void swap(nodeType<T>*, nodeType<T>*);
            /*
            method - insertItem, mutator.
            description - insert an item to the sortedList.
            preconditions - A sortedList must exist and item to be inserted should be specified.
            postconditions - It will add an item to the list.
            method input - T& (item to be inserted)
            method output - void
            */
            void insertItem(const T&);
            /*
            method - deleteItem, mutator.
            description - delete an item from the sortedList.
            preconditions - A sortedList must exist and item to be deleted should be specified.
            postconditions - It will remove an item from the list.
            method input - T& (item to be deleted)
            method output - void
            */
            void deleteItem(const T&);
            /*
            method - deleteAll, mutator.
            description - delete all items matching with the input parameter from the sortedList.
            preconditions - A sortedList must exist and item to be deleted should be specified.
            postconditions - It will remove all matching items from the list.
            method input - T& (item to be deleted)
            method output - void
            */
            void deleteAll(const T&);
            /*
            method - traverse, accessor / mutator.
            description - traverse through the sortedList.
            preconditions - A input function and its parameter must exist.
            postconditions - Postcondition depends on the input function pointer.
            method input - void (*fp)(T&)
            method output - void
            */
            void traverse(void (*)(T&));
            /*
            method - merge, mutator.
            description - merge two sortedList into one.
            preconditions - 2 sortedLists must exist.
            postconditions - append the input sortedList to an existing sortedList.
            method input - sortedList<T>
            method output - void
            */
            void merge(const sortedList<T>&);
            /*
            method - removeDuplicates, mutator.
            description - delete all duplicates from the sortedList.
            preconditions - A sortedList must exist.
            postconditions - All duplicates in the sortedList will be removed.
            method input - void
            method output - void
            */
            void removeDuplicates();
            /*
            method - setOrder, mutator.
            description - sets the sorting type.
            preconditions - A sortedList must exist.
            postconditions - The sortedList will be sorted based on the input sorting type.
            method input - enum (ASCENDING / DESCENDING)
            method output - void
            */
            void setOrder(listStructure);
            /*
            method - destroyList, mutator.
            description - deallocate heap memory from a sortedList instance.
            preconditions - This file must be included in a main file.
            postconditions - Allocated memory will be freed.
            method input - void
            method output - void
            */
            void destroyList();
            /*
            method - isEmptyList, accessor.
            description - check if the list is empty.
            preconditions - A sortedList object must exist.
            postconditions - Shows if the list has 0 item.
            method input - void
            method output - bool
            */
            bool isEmptyList() const;
            /*
            method - inList, accessor.
            description - check if an input item exist in the list.
            preconditions - A sortedList object must exist.
            postconditions - Shows if the list has the input item.
            method input - void
            method output - bool
            */
            bool inList(const T&) const;
            //T& operator[](int);
            /*
            method - subscript/index operator, valueAt, accessor.
            description - accessing a value through an index.
            preconditions - A sortedList object must exist.
            postconditions - an item with corresponding index will return.
            method input - int (index)
            method output - const T& (item)
            */
            const T& operator[](int) const;
            const T& valueAt(int) const;
            /*
            method - Assignment operator
            description - Allows to assign a sortedList<T> instance to another sortedList<T> instance.
            preconditions - A sortedList object must exist to call this function
            postconditions - sortedList<T> is assigned
            method input - sortedList<T>
            method output - sortedList<T>
            */
            const sortedList<T>& operator=(const sortedList<T>&);

        protected:
            int count;
            nodeType<T> *first;
            nodeType<T> *last;
            T *nodeAsArray;
            listStructure structure;
            

    };     
    template <typename T>
    sortedList<T>::sortedList()
    {
        first = NULL;
        last = NULL;
        count = 0;
        structure = ASCENDING;
    }

    template <typename T>
    sortedList<T>::sortedList(listStructure paramStructure)
    {
        first = NULL;
        last = NULL;
        count = 0;
        structure = paramStructure;
    }

    template <typename T>
    sortedList<T>::sortedList(const sortedList<T>& param_sortedList)
    {
        first = NULL;
        if (this != & param_sortedList)
        {
            nodeType<T> *newNode;
            nodeType<T> *current;

            if(first != NULL)
            {
                nodeType<T> *temp;
                while (first != NULL)
                {
                    temp = first;
                    first = first->link;
                    delete temp;
                }
                last = NULL;
                count = 0;
            }

            if (param_sortedList.first == NULL)
            {
                first = NULL;
                last = NULL;
                count = 0;
            }
            else
            {
                current = param_sortedList.first;
                count = param_sortedList.count;
                first = new nodeType<T>;
                assert(first != NULL);
                first->info = current->info;
                first->link = NULL;
                last = first;
                current = current->link;

                while (current != NULL)
                {
                    newNode = new nodeType<T>;
                    assert(newNode != NULL);
                    newNode->info = current->info;
                    newNode->link = NULL;

                    last->link = newNode;
                    last = newNode;

                    current = current->link;
                }
            }
        }
    }

    template <typename T>
    sortedList<T>::~sortedList()
    {
        nodeType<T> *temp;

        while(first != NULL)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = NULL;
        count = 0;
    }


    template <typename T>
    int sortedList<T>::length() const
    {
        return count;
    }
    
    // Since this is a sorted linked list, it shouldn't allow to insert an item at a given index.
    // template <typename T>        
    // T& sortedList<T>::operator[](int index)
    // {
    //     nodeType<T> *current;
    //     current = first;

    //     if (index < 0 || index >= length())
    //         throw std::out_of_range("Index out of range!");

    //     for (int i = 0; i < index; i++)
    //     {
    //         if (index == 0)
    //             return current->info;
    //         else
    //             current = current->link;
    //     }
    //     return current->info;
    // }

    template <typename T>        
    const T& sortedList<T>::operator[](int index) const
    {
        nodeType<T> *current;
        current = first;

        if (index < 0 || index >= length())
            throw std::out_of_range("Index out of range!");

        for (int i = 0; i < index; i++)
        {
            if (index == 0)
                return current->info;
            else
                current = current->link;
        }
        return current->info;
    }   
    
    template <typename T>        
    const T& sortedList<T>::valueAt(int index) const
    {
        nodeType<T> *current;
        current = first;

        if (index < 0 || index >= length())
            throw std::out_of_range("Index out of range!");

        for (int i = 0; i < index; i++)
        {
            if (index == 0)
                return current->info;
            else
                current = current->link;
        }
        return current->info;
    }

    template <typename T>
    bool sortedList<T>::isEmptyList() const
    {
        return count == 0;
    }

    template <typename T>
    void sortedList<T>::insertItem(const T& newInfo)
    {
        nodeType<T> *newNode, *current;
        newNode = new nodeType<T>;
        
        assert(newNode != NULL);
        newNode->info = newInfo;
        newNode->link = NULL;
        current = first;

        if (structure == ASCENDING)
        {
            if (first == NULL)
            {
                newNode->link = first;
                first = newNode;
                last = newNode;
            }
            else if (newNode->info < first->info)
            {
                newNode->link = first;
                first = newNode;
            }
            else if (newNode->info > last->info)
            {
                last->link = newNode;
                last = newNode;
            }
            else //if (first->info <= newNode->info && newNode->info <= last->info)
            {
                while (current->link != NULL && current->link->info < newNode->info)
                {
                    current = current->link;
                }
                newNode->link = current->link;
                current->link = newNode;
            }
        }
        else if (structure == DESCENDING)
        {
            if (first == NULL)
            {
                newNode->link = last;
                first = newNode;
                last = newNode;
            }
            else if (newNode->info > first->info)
            {
                newNode->link = first;
                first = newNode;
            }
            else if (newNode->info < last->info)
            {
                last->link = newNode;
                last = newNode;
            }
            else //if (first->info <= newNode->info && newNode->info <= last->info)
            {
                while (current->link != NULL && current->link->info > newNode->info)
                {
                    current = current->link;
                }
                newNode->link = current->link;
                current->link = newNode;
            }
        }
        count++;
    }

    // This insertItem adds item regardless of order and sort at the end of the function.
    // This is not an efficient way of implementing sorted linked list but still can be used.
    // Please use insertItem above for better performace.

    // template <typename T>
    // void sortedList<T>::insertItem(const T& newInfo)
    // {
    //     nodeType<T> *newNode;
    //     newNode = new nodeType<T>;

    //     assert(newNode != NULL);
    //     newNode->info = newInfo;
    //     newNode->link = NULL;

    //     if (first == NULL)
    //     {
    //         newNode->link = first;
    //         first = newNode;
    //         last = newNode;
    //     }
    //     else
    //     {
    //         last->link = newNode;
    //         last = newNode;
    //     }
    //     count++;
    //     sort(structure);
    // }

    template <typename T>
    void sortedList<T>::sort(listStructure param_structure)
    {
        bool swapped;
        nodeType<T> *tmpPtr;
        nodeType<T> *tmpPtr2 = NULL;

        if (first == NULL)
            return;
        if (param_structure == ASCENDING)
        {
            do
            {
                swapped = false;
                tmpPtr = first;
                while (tmpPtr->link != tmpPtr2)
                {
                    if (tmpPtr->info > tmpPtr->link->info)
                    {
                        swap(tmpPtr, tmpPtr->link);
                        swapped = true;
                    }
                    tmpPtr = tmpPtr->link;
                }
                tmpPtr2 = tmpPtr;
            } while (swapped);
        }
        else if (param_structure == DESCENDING)
        {
            do
            {
                swapped = false;
                tmpPtr = first;
                while (tmpPtr->link != tmpPtr2)
                {
                    if (tmpPtr->info < tmpPtr->link->info)
                    {
                        swap(tmpPtr, tmpPtr->link);
                        swapped = true;
                    }
                    tmpPtr = tmpPtr->link;
                }
                tmpPtr2 = tmpPtr;
            } while (swapped);
        }
    }

    template <typename T>
    void sortedList<T>::swap(nodeType<T> *a, nodeType<T> *b)
    {
        /*
            While researching about swap for a linked list,
            I found it is not efficient to swap by data but by links.
            But I am afraid to reimplement to get it working again.
            I will try to swap with links next time.
        */
        T tmpValue = a->info;
        a->info = b->info;
        b->info = tmpValue;
    }

    template <typename T>
    bool sortedList<T>::inList(const T& itemToCheck) const
    {
        nodeType<T> *current;
        current = first;
        bool found = false;

        for (int i = 0; i < length()-1; i++)
        {
            current = current->link;
            if (itemToCheck == current->info)
                found = true;
        }

        return found;

    }

    template <typename T>
    const sortedList<T>& sortedList<T>::operator=(const sortedList<T>& param_sortedList)
    {
        if (this != &param_sortedList)
        {
            nodeType<T> *newNode;
            nodeType<T> *current;

            if(first != NULL)
            {
                nodeType<T> *temp;
                while (first != NULL)
                {
                    temp = first;
                    first = first->link;
                    delete temp;
                }
                last = NULL;
                count = 0;
            }

            if (param_sortedList.first == NULL)
            {
                first = NULL;
                last = NULL;
                count = 0;
            }
            else
            {
                current = param_sortedList.first;
                count = param_sortedList.count;
                first = new nodeType<T>;
                assert(first != NULL);
                first->info = current->info;
                first->link = NULL;
                last = first;
                current = current->link;

                while (current != NULL)
                {
                    newNode = new nodeType<T>;
                    assert(newNode != NULL);
                    newNode->info = current->info;
                    newNode->link = NULL;

                    last->link = newNode;
                    last = newNode;

                    current = current->link;
                }
            }
        }
        return *this;
    }

    template <typename T>
    void sortedList<T>::deleteItem(const T& itemToDelete)
    {
        nodeType<T> *current;
        nodeType<T> *trailCurrent;
        current = first;
        bool found;

        if (first == NULL)
        {
            cout << "Cannot delete from an empty list." << endl;
        }
        else
        {
            if (first->info == itemToDelete)
            {
                current = first;
                first = first->link;
                count --;
                if (first == NULL)
                {
                    last = NULL;
                }
                delete current;
            }
            else
            {
                found = false;
                trailCurrent = first;
                current = first->link;

                while (current != NULL && !found)
                {
                    if (current->info != itemToDelete)
                    {
                        trailCurrent = current;
                        current = current->link;
                    }
                    else
                        found = true;
                }

                if (found)
                {
                    trailCurrent->link = current->link;
                    count --;

                    if (last == current)
                        last = trailCurrent;

                    delete current;
                }
                else
                {
                    throw std::logic_error("The item to be deleted is not in the list.");
                }
            }
        }
        
    }
    
    template <typename T>
    void sortedList<T>::deleteAll(const T& itemToDelete)
    {
        bool found;
        if (inList(itemToDelete))
            found = true;
        else
        {
            found = false;
            throw std::logic_error("The item to be deleted is not in the list.");
        }
        
        while(found)
        {
            deleteItem(itemToDelete);
            if(!inList(itemToDelete))
                found = false;
        }
    }

    template <typename T>
    void sortedList<T>::setOrder(listStructure param_structure)
    {
        structure = param_structure;
        sort(param_structure);
    }

    template <typename T>
    void sortedList<T>::traverse(void (*fp) (T&))
    {
        nodeType<T> *current = first;
        current->info = first->info;
        for (int i = 0; i < count; i++)
        {    
            fp(current->info);
            current = current->link;
        }
        delete current;
    }

    template <typename T>
    void sortedList<T>::merge(const sortedList<T>& param_sortedList)
    {
        nodeType<T> *current = param_sortedList.first;
        current->info = param_sortedList.first->info;
        for (int i = 0; i < param_sortedList.count; i++)
        {
            insertItem(current->info);
            current = current->link;
        }
        delete current;
    }

    template <typename T>
    void sortedList<T>::removeDuplicates()
    {
        nodeType<T> *current = first;
        current->info = first->info;
        while (current->link != NULL)
        {
            if (current->info == current->link->info)
            {
                deleteItem(current->info);
            }
            current = current->link;
        }
    }

    template <typename T>
    void sortedList<T>::destroyList()
    {
        nodeType<T> *temp;

        while(first != NULL)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = NULL;
        count = 0;
    }
}

#endif
