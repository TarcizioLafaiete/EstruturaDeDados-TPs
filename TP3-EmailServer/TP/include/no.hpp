#ifndef NO_HPP
#define NO_HPP

#include "email.hpp"
class no{
    public:
        no();
    private:
        email item;
        no *esq;
        no *dir;
        friend class arvoreEmail;
};   
#endif