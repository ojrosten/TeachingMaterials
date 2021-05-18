#pragma once

#include <iostream>

namespace stuff
{
    class Foo
    {
    public:
        Foo()
        {
            ptr = new int(5);
            std::cout << "Constructor\n";
        }

        Foo(const Foo& other)
        {
            ptr = new int(*other.ptr);
            std::cout << "Copy constructor\n";
        }


        Foo(Foo&& other)
        {
            ptr = other.ptr;
            other.ptr = nullptr;
            std::cout << "Move constructor\n";
        }
        
        ~Foo()
        {
            std::cout << "Destructor\n";
        }

        Foo& operator=(Foo const& other)
        {
            *ptr = *other.ptr;
            return *this;
        }

        Foo& operator=(Foo&& other)
        {
            ptr = other.ptr;
            other.ptr = nullptr;
            return *this;
        }
    private:
        int* ptr;
    };

    class Bar
    {
    public:
        Bar(const Bar& other) = default;
        Bar(Bar&&) = default;
    private:
        Foo b;
        int x, y, z;
    };

    inline void bar() {}
}