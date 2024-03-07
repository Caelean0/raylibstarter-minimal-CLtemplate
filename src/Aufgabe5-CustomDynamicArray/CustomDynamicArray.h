//
// Created by keanu on 20.02.2024.
//
#include <memory>
#include <stdexcept>
#include <iostream>

#ifndef RAYLIBSTARTER_CUSTOMDYNAMICARRAY_H
#define RAYLIBSTARTER_CUSTOMDYNAMICARRAY_H


    namespace game::memory
    {
        template<typename T, typename Alloc = std::allocator<T>>
        class CustomVector
        {
        private:
            T *data;
            int size = 0;
            int writtenSize = 0;
            Alloc alloc;

            CustomVector() = delete;

            bool typeIsArithmetic = false;

            bool isOutOfWrittenRange(int index);

            bool isOutOfAllocatedRange(int index);

        public:
            class iterator
            {
            private:
                T *ptr_;
            public:
                iterator(T *ptr);

                T &operator*() const;

                iterator &operator++();

                iterator operator++(int);

                bool operator==(const iterator &compare) const;

                bool operator!=(const iterator &compare) const;
            };

            iterator begin();

            iterator end();

            CustomVector(int size);

            CustomVector(std::initializer_list<T> list);

            ~CustomVector();

            T operator[](int index) const;

            T &operator[](int index);

            void add(T elem);

            void remove(int index);

            T getMax();

            T getMax(int start, int end);

            T getMin();

            T getMin(int start, int end);

            CustomVector<int> getValueIndices(T value);

            CustomVector<int> getValueIndices(T value, int start, int end);

            int getWrittenSize();

            int getAllocatedSize();

            void consoleOut();



            /*class iterator {
            private:
                T *ptr_;
            public:
                iterator(T *ptr);

                T& operator*() const;

                iterator& operator++();
                iterator operator++(int);

                bool operator==(const iterator& compare) const;
                bool operator!=(const iterator& compare) const;
            };

            iterator begin();
            iterator end();*/

        };
    }




#endif //RAYLIBSTARTER_CUSTOMDYNAMICARRAY_H
