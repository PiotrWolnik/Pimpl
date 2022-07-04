//
// Created by user on 18.06.2022.
//

#include "gadget.hpp"

std::vector<Gadget> Gadget::cart {};

std::ostream & operator<<(std::ostream & os, const Gadget & gadget) {
    return os << "Brand: " << gadget.brand << "\nYear of production: " << gadget.year_of_production << std::endl;
}

bool operator==(const Gadget & rhs, const Gadget & lhs) {
    return (rhs.brand == lhs.brand)
        && (rhs.year_of_production == lhs.year_of_production)
        && (rhs.daily_utility == lhs.daily_utility);
}

void Gadget::add_useful_gadget_to_cart() {
    // Object is given to cart if the daily_utility attribute is true
    if (daily_utility) {
        cart.emplace_back(Gadget(*this));
    }
    else {
        std::cout << "Cannot add gadget that's not useful." << std::endl;
    }
}

void Gadget::view_cart_contents() {
    std::size_t i = 1;
    for (const auto & gadget : cart) {
        std::cout << "Gadget 1:\n" << gadget << "\n";
        i++;
    }
}