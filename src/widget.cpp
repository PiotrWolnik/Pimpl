//
// Created by user on 30.06.2022.
//

#include "widget.hpp"

struct Widget::Impl {
    Gadget gadget;
    ID id_number;
    explicit Impl(std::string brand_ = "Noname", int year_of_production_ = 1900, bool daily_utility_ = false, ID id_num = 0)
        : gadget(std::move(brand_), year_of_production_, daily_utility_), id_number(id_num) {}
};

Widget::Widget() : ptr(std::make_unique<Impl>()) {}
