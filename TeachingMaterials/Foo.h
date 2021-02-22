#pragma once

namespace stuff
{
    class Foo
    {
    public:
        Foo() = default;
        //Foo(const Foo&) = default;
        //Foo(Foo&&) = default;
        ~Foo() = default;

        int get() const;
    private:
        int m_I{};
    };

    inline void bar() {}
}