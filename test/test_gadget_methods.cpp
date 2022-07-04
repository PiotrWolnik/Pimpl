//
// Created by user on 18.06.2022.
//

#include "gtest/gtest.h"
#include "gadget.hpp"

static Gadget gadget1{"Nike", 1990, true};

TEST(checkGadget, gadget_eq_test) {
    Gadget gadget2{"Nike", 1990, true};
    Gadget gadget3{"Adidas", 1990, false};
    gadget1.add_useful_gadget_to_cart();

    ASSERT_EQ(gadget1, gadget2);
    EXPECT_NE(gadget3, gadget1);
}

TEST(checkGadget, printGadgetViaOstreamObject) {
    std::ostringstream expected_output{"Brand: Nike\nYear of production: 1990\n"};
    std::ostringstream actual_output;
    actual_output << gadget1;
    ASSERT_EQ(expected_output.str(), actual_output.str());
}

TEST(checkGadget, gadget_add_to_cart_test) {
    Gadget gadget2{"Nike", 1990, true};
    gadget2.add_useful_gadget_to_cart();
    EXPECT_EQ(Gadget::cart[0], gadget2);
    Gadget::cart.clear();
}

// Here I've checked if correct exceptions were thrown
//TEST(checkGadget, gadget_remove_from_cart_test) {
//    Gadget gadget3{"Adidas", 1990, false};
//    gadget3.add_useful_gadget_to_cart();
//    Gadget::view_cart_contents();
//    EXPECT_THROW(Gadget::remove_gadget_from_cart(0), EmptyCart);
//
//    gadget1.add_useful_gadget_to_cart();
//    if (!Gadget::cart.empty())
//        EXPECT_THROW(Gadget::remove_gadget_from_cart(1), IndexCartException);
//
//    if (!Gadget::cart.empty())
//        EXPECT_THROW(Gadget::remove_gadget_from_cart(11.2343232), NoIndexError);
//}

// Here I checked if catches block were working properly
TEST(checkGadget, gadget_remove_from_cart_test) {
    Gadget gadget3{"Adidas", 1990, false};
    gadget3.add_useful_gadget_to_cart();
    Gadget::view_cart_contents();
    EXPECT_NO_THROW(Gadget::remove_gadget_from_cart(0));

    gadget1.add_useful_gadget_to_cart();
    if (!Gadget::cart.empty())
        EXPECT_NO_THROW(Gadget::remove_gadget_from_cart(1));

    if (!Gadget::cart.empty())
        EXPECT_NO_THROW(Gadget::remove_gadget_from_cart(11.2343232));
}
