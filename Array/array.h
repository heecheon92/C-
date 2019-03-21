// File:    array.h
// Name:    Heecheon Park
// Program: prog
// Date:    March 14th, 2019

/*  
This file contains declaration of templated Array class, its implementation.
Since this is a template class, there is no description in the main.cpp
*/

#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>
#include <string>

using namespace std;

namespace ArrayNameSpace
{
    template <typename T>
    class Array
    {
        public:
            /*
            method - constructor.
            description - construct a new Array instance.
            preconditions - This file must be included in a main file.
            postconditions - Array object will be created.
            method input - none (Default array size is 0)
                         - int (array size)
                         - int, int (start index, end index)
                         - Array object (As a copy constructor)
            method output - Array object
            */
            Array();
            Array(int size);
            Array(int, int);
            Array(const Array&);
            /*
            method - destructor.
            description - deallocate heap memory from an Array instance.
            preconditions - This file must be included in a main file.
            postconditions - Allocated memory will be freed.
            method input - void
            method output - void
            */
            ~Array();
            /*
            method - accessor
            description - returns the size of an array.
            preconditions - Array object must exist to call this function.
            postconditions - array size will return.
            method input - void 
            method output - int
            */
            int Size() const;
            /*
            method - mutator.
            description - Changes the size of an array.
            preconditions - Array object must exist to call this function.
            postconditions - array size will change.
            method input - int
            method output - void
            */
            void Resize(int);
            /*
            method - accessor
            description - returns the startIndex of an array.
            preconditions - Array object must exist to call this function.
            postconditions - startIndex will return.
            method input - void
            method output - int
            */
            int getStartIndex() const;
            /*
            method - accessor
            description - returns the endIndex of an array.
            preconditions - Array object must exist to call this function.
            postconditions - endIndex will return.
            method input - void
            method output - int
            */
            int getEndIndex() const;
            /*
            method - mutator.
            description - Changes its startIndex and endIndex accordingly.
            preconditions - Array object must exist to call this function.
            postconditions - startIndex will change.
            method input - int
            method output - void
            */
            void setStartIndex(int);
            /*
            method - accessor + mutator
            description - creates and returns an Array<T> and copies values from *this in reverse order.
            preconditions - Array object must exist to call this function.
            postconditions - returns a new instance of Array<T>.
            method input - void 
            method output - Array<T>
            */
            Array<T> Reverse();
            /*
            method - accessor + mutator
            description - creates and returns an Array<T> and copies values from *this in ascending order. (Bubble sort)
            preconditions - Array object must exist to call this function.
            postconditions - returns a new instance of Array<T>.
            method input - none 
            method output - Array<T>
            */
            Array<T> Ascending();
            /*
            method - accessor + mutator
            description - creates and returns an Array<T> and copies values from *this in descending order. (Bubble sort)
            preconditions - Array object must exist to call this function.
            postconditions - returns a new instance of Array<T>.
            method input - none 
            method output - Array<T>
            */
            Array<T> Descending();
            /*
            method - Equal operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator==(const Array&) const;
            /*
            method - Not Equal operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator!=(const Array&) const;
            /*
            method - Less than operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator<(const Array&) const;
            /*
            method - Less than or equal to operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator<=(const Array&) const;
            /*
            method - Greater than operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator>(const Array&) const;
            /*
            method - Greater than or equal to operator
            description - compares an Array object to other values
            preconditions - Array object must exist to call this function
            postconditions - returns a bool based on a comparison
            method input - Array reference
            method output - bool
            */
            bool operator>=(const Array&) const;
            /*
            method - Index / Subscript operator, mutator
            description - Allows user defined index based on start and end index, linked to the logical indices.
            preconditions - Array object must exist to call this function
            postconditions - a value of an array is assigned to a variable based on user defined index, linked to the logical indices.
            method input - int (index)
            method output - T, Array[index]
            */
            T& operator[](int);
            /*
            method - Index / Subscript operator, accessor
            description - Allows user defined index based on start and end index, linked to the logical indices.
            preconditions - Array object must exist to call this function
            postconditions - Returns a value of an array is based on user defined index, linked to the logical indices.
            method input - int (index)
            method output - T, Array[index]
            */
            const T& operator[](int) const;
            /*
            method - Assignment operator
            description - Allows to assign a Array<T> instance to another Array<T> instance.
            preconditions - Array object must exist to call this function
            postconditions - Array<T> is assigned
            method input - Array<T>
            method output - Array<T>
            */
            const Array& operator= (const Array&);
        
        private:
            int size;
            int startIndex;
            int endIndex;
            T *theArray;

    };

    template <typename T>
    Array<T>::Array()
    {
        theArray = new T[0]();
        size = 0;
        startIndex = -1;
        endIndex = 0;
    }

    template <typename T>
    Array<T>::Array(int s)
    {
        theArray = new T[s]();
        size = s;
        startIndex = 0;
        if (s == 0)
            endIndex = 0;
        else
            endIndex = s - 1;
    }

    template <typename T>
    Array<T>::Array(int sIndex, int eIndex)
    {
        size = eIndex - sIndex + 1;
        theArray = new T[size]();
        startIndex = sIndex;
        endIndex = eIndex;
    }

    template <typename T>
    Array<T>::~Array()
    {
        delete [] theArray;
        theArray = NULL;
    }

    template <typename T>
    Array<T>::Array(const Array& paramArray)
    {
        size = paramArray.Size();
        theArray = new T[size]();
        startIndex = paramArray.startIndex;
        endIndex = paramArray.endIndex;
        for (int i = 0; i < size; i++)
        {
            theArray[i] = paramArray.theArray[i];
        }
    }

    // Mutator. i.e. int numbers[0] = 999;
    template <typename T>
    T& Array<T>::operator[](int index)
    {
        index = index - startIndex;
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range Exception");
        }
        return theArray[index];
    }

    // Accessor. i.e. int tmpValue = numbers[0];
    template <typename T>
    const T& Array<T>::operator[](int index) const
    {
        index = index - startIndex;
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range Exception");
        }
        return theArray[index];
    }

    template <typename T>
    int Array<T>::getStartIndex() const
    {
        return startIndex;
    }

    template <typename T>
    int Array<T>::getEndIndex() const
    {
        return endIndex;
    }

    template <typename T>
    void Array<T>::setStartIndex(int newIndex)
    {
        int gap = newIndex - startIndex;
        startIndex = newIndex;
        endIndex = endIndex + gap;
    }

    template <typename T>
    int Array<T>::Size() const
    {
        return endIndex - startIndex +1;
    }

    template <typename T>
    void Array<T>::Resize(int sizeInput)
    {
        if (sizeInput < 0)
        {
            throw std::out_of_range("New size cannot be less than 0.");
        }
        else
        {
            T *tmpArray = new T[sizeInput]();
            if (sizeInput > Size())
            {
                for (int i = 0; i < Size(); i++)
                {
                    tmpArray[i] = theArray[i];
                }
                for (int j = Size()+1; j < sizeInput; j++)
                {
                    tmpArray[j] = 0;
                }
            }
            else
            {
                for (int i = 0; i < sizeInput; i++)
                {
                    tmpArray[i] = theArray[i];
                }
            }
            //int tmpArraySize = sizeof(tmpArray)/sizeof(tmpArray[0]);
            for (int i = 0; i < sizeInput; i++)
            {
                theArray[i] = tmpArray[i];
            }
            size = sizeInput;
            endIndex = startIndex + size - 1;
            //delete [] tmpArray;
        }
    }

    template <typename T>
    const Array<T>& Array<T>::operator=(const Array<T>& paramArray)
    {
        if (&paramArray != this)
        {
            delete [] theArray;
            theArray = new T[paramArray.Size()]();
            size = paramArray.size;
            startIndex = paramArray.startIndex;
            endIndex = paramArray.endIndex;
            for (int i = 0; i < paramArray.Size(); i++)
            {
                // Learned from a silly mistake with hours of debugging!
                // No more same mistakes!
                // paramArray[i] != paramArray.theArray[i];
                // paramArray[i] follows the indices from the overloaded operator[]
                // paramArray.theArray[i] follows the logical indices
                theArray[i] = paramArray.theArray[i];
            }
        }
        return *this;
    }

    template <typename T>
    Array<T> Array<T>::Reverse()
    {
        Array<T> tmpContainer(size);
        tmpContainer.theArray = new T[size];
        tmpContainer.size = size;
        tmpContainer.startIndex = startIndex;
        tmpContainer.endIndex = endIndex;
        //T *tmpArray = new T[size];
        T valueHolder;
        int count = Size() - 1;
        
        for (int j = 0; j < Size(); j++)
        {
            valueHolder = theArray[count];
            tmpContainer.theArray[j] = valueHolder;
            count--;
        }
        return tmpContainer;
    }

    template <typename T>
    Array<T> Array<T>::Ascending()
    {
        Array<T> tmpContainer(size);
        tmpContainer.theArray = new T[size];
        //T initialValue;
        T tempValue;
        //int index;
        int tmpStartIndex = getStartIndex();
        tmpContainer.setStartIndex(tmpStartIndex);

        for (int i = 0; i < Size(); i++)
        {
            tmpContainer.theArray[i] = theArray[i];
        }
        for (int i = 0; i < Size(); i++)
        {
            //initialValue = 999999;
            for (int j = 0; j < Size()-1-i; j++)
            {
                if(tmpContainer.theArray[j] > tmpContainer.theArray[j+1])
                {
                    tempValue = tmpContainer.theArray[j];
                    tmpContainer.theArray[j] = tmpContainer.theArray[j+1];
                    tmpContainer.theArray[j+1] = tempValue;
                }
            }
        }
        return tmpContainer;
    }

    template <typename T>
    Array<T> Array<T>::Descending()
    {
        Array<T> tmpContainer(size);
        tmpContainer.theArray = new T[size];
        T tempValue;
        int tmpStartIndex = getStartIndex();
        tmpContainer.setStartIndex(tmpStartIndex);

        for (int i = 0; i < Size(); i++)
        {
            tmpContainer.theArray[i] = theArray[i];
        }
        for (int i = 0; i < Size(); i++)
        {
            for (int j = 0; j < Size()-1-i; j++)
            {
                if(tmpContainer.theArray[j] < tmpContainer.theArray[j+1])
                {
                    tempValue = tmpContainer.theArray[j];
                    tmpContainer.theArray[j] = tmpContainer.theArray[j+1];
                    tmpContainer.theArray[j+1] = tempValue;
                }
            }
        }
        return tmpContainer;
    }
    template <typename T>
    bool Array<T>::operator==(const Array& paramArray) const
    {
        bool flag = false;
        if (Size() == paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] == paramArray.theArray[i])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
        }
        return flag;
    }

    template <typename T>
    bool Array<T>::operator!=(const Array& paramArray) const
    {
        bool flag = false;
        if (Size() == paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] != paramArray.theArray[i])
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
        }
        else if (Size() != paramArray.Size())
        {
            flag = true;
        }
        return flag;
    }

    template <typename T>
    bool Array<T>::operator<(const Array& paramArray) const
    {
        if (Size() == paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] < paramArray.theArray[i])
                    return theArray[i] < paramArray.theArray[i];
            }
            return false;
        }
        else if(Size() > paramArray.Size())
        {
            for (int i = 0; i < paramArray.Size(); i++)
            {
                if (theArray[i] < paramArray.theArray[i])
                    return theArray[i] < paramArray.theArray[i];
            }
            return false;
        }
        else if(Size() < paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] < paramArray.theArray[i])
                    return theArray[i] < paramArray.theArray[i];
            }
            return true;
        }
        return false;
    }

    template <typename T>
    bool Array<T>::operator<=(const Array& paramArray) const
    {
        return *this == paramArray || *this < paramArray;
    }

    template <typename T>
    bool Array<T>::operator>(const Array& paramArray) const
    {
        if (Size() == paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] > paramArray.theArray[i])
                    return theArray[i] > paramArray.theArray[i];
            }
            return false;
        }
        else if(Size() > paramArray.Size())
        {
            for (int i = 0; i < paramArray.Size(); i++)
            {
                if (theArray[i] > paramArray.theArray[i])
                    return theArray[i] > paramArray.theArray[i];
            }
            return true;
        }
        else if(Size() < paramArray.Size())
        {
            for (int i = 0; i < Size(); i++)
            {
                if (theArray[i] > paramArray.theArray[i])
                    return theArray[i] > paramArray.theArray[i];
            }
            return false;
        }
        return false;
    }

    template <typename T>
    bool Array<T>::operator>=(const Array& paramArray) const
    {
        return *this == paramArray || *this > paramArray;
    }
}


#endif
