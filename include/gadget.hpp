//
// Created by user on 18.06.2022.
//

#ifndef PIMPL_GADGET_HPP
#define PIMPL_GADGET_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using ID = std::size_t;

enum class ShopaholicRate {NO = 5, MAYBE = 10, YES = 15};

class Gadget {
    friend std::ostream & operator<<(std::ostream & os, const Gadget & gadget);
    friend bool operator==(const Gadget & rhs, const Gadget & lhs);
public:
    static std::vector<Gadget> cart;
    // Constructors and assignment operators for Gadget class
    explicit Gadget(std::string brand_ = "Noname", int year_of_production_ = 1900, bool daily_utility_ = false) :
        brand(std::move(brand_)), year_of_production(year_of_production_),  daily_utility(daily_utility_) {}
    Gadget(const Gadget & gadget) = default;
    Gadget & operator=(const Gadget & gadget) = default;
    Gadget(Gadget && gadget) = default;
    Gadget & operator=(Gadget && gadget) = default;
    ~Gadget() = default;

    //Methods
    void add_useful_gadget_to_cart();
    template <typename T>
    static void remove_gadget_from_cart(T&& index);
    static void view_cart_contents();

    // Attributes
private:
    std::string brand;
    int year_of_production;
    bool daily_utility;
};

// Error is thrown when index is not within the range 0-cart.size()
class IndexCartException : public std::exception {
public:
    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Index given is bigger than the amount of elements in cart\n";
    }
};

// Error is thrown when user gives a value that is not an index (an integral number)
class NoIndexError : public std::exception {
public:
    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "No index was given\n";
    }
};

// Error is thrown when we try to remove object from empty cart
class EmptyCart : public std::exception {
public:
    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Cart is already empty\n";
    }
};

// Function responsible for erasing
template <typename T>
void Gadget::remove_gadget_from_cart(T&& index) {
    try {
        // We use std::remove_reference in case reference to l-value is returned
        // what happens when l-value is sent as an argument to remove_gadget_from_cart
        if (cart.empty()) {
            throw EmptyCart();
        }
        if (std::is_integral<std::remove_reference_t<T>>()) {

            try {
                // If index given
                if (static_cast<std::size_t>(index) >= cart.size())
                    throw IndexCartException();

                else {
                    auto gadget_to_match = cart[static_cast<std::size_t>(index)];
                    erase_if(cart,[&](const auto& gadget){return gadget == gadget_to_match; });
                }
            }
            catch(const EmptyCart & cart_ex) {
                std::cout << cart_ex.what();
            }
            catch(const IndexCartException & cart_ex) {
                std::cout << cart_ex.what();
            }
        }
        else {
            throw NoIndexError();
        }
    }

    catch (const EmptyCart & cart_ex) {
        std::cout << cart_ex.what();
    }

    catch(const NoIndexError & ex) {
        std::cout << ex.what();
    }
}

#endif //PIMPL_GADGET_HPP
