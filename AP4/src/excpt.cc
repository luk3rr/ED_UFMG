#include "excpt.hh"

const char* excpt::what() const throw() {
    return this->_msg.c_str();
}
