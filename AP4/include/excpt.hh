#ifndef EXCPT_H_
#define EXCPT_H_

#include <exception>
#include <string>

class excpt : public std::exception {
    private:
        std::string _msg;

    public:
        excpt(const std::string &mensagem) : _msg(mensagem) {}

        const char* what() const throw();
};

#endif // EXCPT_H_
