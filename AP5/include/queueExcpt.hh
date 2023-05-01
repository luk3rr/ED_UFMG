#ifndef QUEUEEXCPT_H_
#define QUEUEEXCPT_H_

#include <exception>

namespace queexcpt {
    class QueueOverflow : public std::exception {
            public:
            const char *what() const throw();
    };

    class QueueIsEmpty : public std::exception {
          public:
            const char *what() const throw();
    };
} // namespace queexcpt

#endif // QUEUEEXCPT_H_
