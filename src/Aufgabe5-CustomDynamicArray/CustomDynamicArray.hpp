//
// Created by keanu on 20.02.2024.
//


#ifndef RAYLIBSTARTER_CUSTOMDYNAMICARRAY_HPP
#define RAYLIBSTARTER_CUSTOMDYNAMICARRAY_HPP


#include "CustomDynamicArray.h"

template<typename T, typename Alloc>
game::memory::CustomVector<T, Alloc>::CustomVector(int size): size(size), writtenSize(0), data(nullptr)
{
    data = alloc.allocate(size);
    typeIsArithmetic = std::is_arithmetic<T>::value;
};

template<typename T, typename Alloc>
game::memory::CustomVector<T, Alloc>::CustomVector(std::initializer_list<T> list) : size(list.size()), writtenSize(list.size()), data(nullptr)
{
    data = alloc.allocate(size);
    int i = 0;
    for (auto &elem: list)
    {
        alloc.construct(data + i, elem);
        ++i;
    }
    typeIsArithmetic = std::is_arithmetic<T>::value;
}

template<typename T, typename Alloc>
game::memory::CustomVector<T, Alloc>::~CustomVector()
{
    for (int i = 0; i < writtenSize; ++i)
    {
        alloc.destroy(data + i);
    }
    alloc.deallocate(data, size);
    data = nullptr;
}

template<typename T, typename Alloc>
bool game::memory::CustomVector<T, Alloc>::isOutOfAllocatedRange(int index)
{
    if (index < 0 || index >= size)
    {
        return true;
    } else {
        return false;
    }
}

template<typename T, typename Alloc>
bool game::memory::CustomVector<T, Alloc>::isOutOfWrittenRange(int index)
{
    if (index < 0 || index >= writtenSize)
    {
        return true;
    } else {
        return false;
    }
}

template<typename T, typename Alloc>
T game::memory::CustomVector<T, Alloc>::operator[](int index) const
{
    if (isOutOfAllocatedRange(index))
    {
        throw std::out_of_range("Index out of allocated range");
    }
    return data[index];
}

template<typename T, typename Alloc>
T& game::memory::CustomVector<T, Alloc>::operator[](int index)
{
    if (isOutOfAllocatedRange(index))
    {
        throw std::out_of_range("Index out of allocated range");
    }
    if (index >= writtenSize)
    {
        writtenSize++;
    }

    return data[index];
}

template<typename T, typename Alloc>
void game::memory::CustomVector<T, Alloc>::add(T elem)
{
    if (writtenSize < size)
    {
        alloc.construct(data + writtenSize, elem);
        writtenSize++;
        return;
    }

    T temp[size];
    for (int i = 0; i < size; ++i)
    {
        temp[i] = data[i];
        alloc.destroy(data + i);
    }
    alloc.deallocate(data, size);
    size++;
    writtenSize++;
    data = alloc.allocate(size);
    for (int i = 0; i < size; ++i)
    {
        if (i < size - 1)
        {
            alloc.construct(data + i, temp[i]);
        } else
        {
            alloc.construct(data + i, elem);
        }
    }
}

template<typename T, typename Alloc>
void game::memory::CustomVector<T, Alloc>::remove(int index)
{
    if (isOutOfAllocatedRange(index))
    {
        throw std::out_of_range("Index out of allocated range");
    }
    for (int i = index; i < writtenSize - 1; ++i)
    {
        alloc.construct(data + i, data[i + 1]);
    }
    alloc.destroy(data + writtenSize - 1);
    writtenSize--;
}

template<typename T, typename Alloc>
int game::memory::CustomVector<T, Alloc>::getWrittenSize()
{
    return writtenSize;
}

template<typename T, typename Alloc>
int game::memory::CustomVector<T, Alloc>::getAllocatedSize()
{
    return size;
}


template<typename T, typename Alloc>
T game::memory::CustomVector<T, Alloc>::getMax()
{
    if (!typeIsArithmetic)
    {
        throw std::logic_error("Type is not arithmetic");
    }
    
    T comp = data[0];
    for (int i = 0; i < writtenSize; ++i)
    {
        (comp < data[i]) ? (comp = data[i]) : (comp);
    }
    return comp;
}
template<typename T, typename Alloc>
T game::memory::CustomVector<T, Alloc>::getMax(int start, int end)
{
    if (!typeIsArithmetic)
    {
        throw std::logic_error("Type is not arithmetic");
    } else if (isOutOfWrittenRange(start) || isOutOfWrittenRange(end))
    {
        throw std::out_of_range("Index out of written range");
    }
    
    T comp = data[start];
    for (int i = start; i <= end; ++i)
    {
        (comp < data[i]) ? (comp = data[i]) : (comp);
    }
    return comp;
}

template<typename T, typename Alloc>
T game::memory::CustomVector<T, Alloc>::getMin()
{
    if (!typeIsArithmetic)
    {
        throw std::logic_error("Type is not arithmetic");
    }
    
    T comp = data[0];
    for (int i = 0; i < writtenSize; ++i)
    {
        (comp > data[i]) ? (comp = data[i]) : (comp);
    }
    return comp;
}
template<typename T, typename Alloc>
T game::memory::CustomVector<T, Alloc>::getMin(int start, int end)
{
    if (!typeIsArithmetic)
    {
        throw std::logic_error("Type is not arithmetic");
    } else if (isOutOfWrittenRange(start) || isOutOfWrittenRange(end))
    {
        throw std::out_of_range("Index out of written range");
    }
    
    T comp = data[start];
    for (int i = start; i <= end; ++i)
    {
        (comp > data[i]) ? (comp = data[i]) : (comp);
    }
    return comp;
}

template<typename T, typename Alloc>
game::memory::CustomVector<int> game::memory::CustomVector<T, Alloc>::getValueIndices(T value)
{
    game::memory::CustomVector<int> ret(0);
    for (int i = 0; i < size; ++i)
    {
        if (data[i] == value)
        {
            ret.add(i);
        }
    }
    return ret;
}
template<typename T, typename Alloc>
game::memory::CustomVector<int> game::memory::CustomVector<T, Alloc>::getValueIndices(T value, int start, int end)
{
    if (isOutOfWrittenRange(start) || isOutOfWrittenRange(end))
    {
        throw std::out_of_range("Index out of written range");
    }

    game::memory::CustomVector<int> ret(0);
    for (int i = start; i <= end; ++i)
    {
        if (data[i] == value)
        {
            ret.add(i);
        }
    }
    return ret;
}

template<typename T, typename Alloc>
void game::memory::CustomVector<T, Alloc>::consoleOut()
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << data[i] << " ";
    }
}


template<typename T, typename Alloc>
game::memory::CustomVector<T, Alloc>::iterator::iterator(T *ptr): ptr_(ptr){}

template<typename T, typename Alloc>
T &game::memory::CustomVector<T, Alloc>::iterator::operator*() const
{
    return *ptr_;
}

template<typename T, typename Alloc>
typename game::memory::CustomVector<T, Alloc>::iterator &game::memory::CustomVector<T, Alloc>::iterator::operator++()
{
    ++ptr_;
    return *this;
}

template<typename T, typename Alloc>
typename game::memory::CustomVector<T, Alloc>::iterator game::memory::CustomVector<T, Alloc>::iterator::operator++(int)
{
    iterator temp = *this;
    ++ptr_;
    return temp;
}

template<typename T, typename Alloc>
bool game::memory::CustomVector<T, Alloc>::iterator::operator==(const CustomVector::iterator &compare) const
{
    return ptr_ == compare.ptr_;
}

template<typename T, typename Alloc>
bool game::memory::CustomVector<T, Alloc>::iterator::operator!=(const CustomVector::iterator &compare) const
{
    return ptr_ != compare.ptr_;
}


template<typename T, typename Alloc>
typename game::memory::CustomVector<T, Alloc>::iterator game::memory::CustomVector<T, Alloc>::begin()
{
    return iterator(data);
}

template<typename T, typename Alloc>
typename game::memory::CustomVector<T, Alloc>::iterator game::memory::CustomVector<T, Alloc>::end()
{
    return iterator(data + writtenSize);
}

#endif //RAYLIBSTARTER_CUSTOMDYNAMICARRAY_HPP
