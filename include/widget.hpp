//
// Created by user on 30.06.2022.
//

#ifndef PIMPL_WIDGET_HPP
#define PIMPL_WIDGET_HPP

#include <memory>
#include "gadget.hpp"

class Widget {
public:
    explicit Widget();

private:
    struct Impl;
    std::unique_ptr<Impl> ptr;

};



#endif //PIMPL_WIDGET_HPP
