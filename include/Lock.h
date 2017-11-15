//
// Created by fiorentinoing on 15/11/17.
//

#ifndef MUTEX_LOCK_LOCK_H
#define MUTEX_LOCK_LOCK_H

#include <mutex>
#include <memory>
///
namespace mutex_lock
{
    ///
    std::mutex mutex;

    ///
    namespace detail
    {
        ///
        void unlock(std::mutex* pm)
        {
           pm->unlock();
        }

        ///
        void lock(std::mutex *pm)
        {
            pm->lock();
        }
    }

    ///
    class Lock
    {
    public:
        ///
        /// \param pm
        explicit Lock(std::mutex *pm)
                : mutexPtr(pm, detail::unlock)
        {
            detail::lock(mutexPtr.get());
        }

    private:
        std::shared_ptr<std::mutex> mutexPtr;
    };
}

#endif //MUTEX_LOCK_LOCK_H
