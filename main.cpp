#include <string>
#include <iostream>

#include "include/Lock.h"

namespace
{
    void solution1()
    {
        std::string* ps = new std::string;
        mutex_lock::Lock ml(&mutex_lock::mutex);
        ps->insert(0, "ciao!");

        // here is an exception-raising function call
        throw std::runtime_error("prevent to printout and clean the heap");

        delete ps; // because the runtime never reach this point, we have resource leak
    }

    void solution2()
    {
        std::shared_ptr<std::string> ps = std::shared_ptr<std::string>(new std::string);
        mutex_lock::Lock ml(&mutex_lock::mutex);
        ps->insert(0, "ciao!");

        // here is an exception-raising function call
        throw std::runtime_error("prevent to printout and clean the heap");

        // because of the resource-manager object `shared_ptr`,
        // no need to delete the string pointed by ps.
    }
}

int main()
{
    try
    {
        ::solution1();
    }
    catch(std::runtime_error const& exp) {}

    try
    {
        ::solution2();
    }
    catch(std::runtime_error const& exp) {}

    return 0;
}