#include <string>
#include <iostream>

#include "include/run.h"
#include "include/mutex_lock.h"
#include <memory>

namespace
{
    void solution1()
    {
        std::string* ps = new std::string;
        std::lock_guard<std::mutex> ml(mutex_lock::mutex);
        ps->insert(0, "ciao!");

                // here is an exception-raising function call
        throw std::runtime_error("prevent to printout and clean the heap");

        delete ps; // because the runtime never reach this point, we have resource leak
    }

    void solution2()
    {
        std::shared_ptr<std::string> ps = std::shared_ptr<std::string>(new std::string);
        std::lock_guard<std::mutex> ml(mutex_lock::mutex);
        ps->insert(0, "ciao!");

        // here is an exception-raising function call
        throw std::runtime_error("prevent to printout and clean the heap");

        // because of the resource-manager object `shared_ptr`,
        // one doesn't need to delete the string pointed by ps.
    }

}

void run(std::istream& in)
{
    int solutionNumber = -1;
    in >> solutionNumber;

    switch (solutionNumber)
    {
        case 1:
            ::solution1();
            break;
        case 2:
            ::solution2();
            break;
        default:
            throw std::runtime_error("Only solution 1 and 2 are available.");
    }

    std::cout << solutionNumber << std::endl;
}
