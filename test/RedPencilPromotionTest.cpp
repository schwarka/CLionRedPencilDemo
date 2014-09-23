#include <gtest/gtest.h>
#include "../src/Product.h"

using namespace RedPencilPromotion;
using namespace testing;

class RedPencilPromotionTest : public Test {

public:
    RedPencilPromotionTest() : Test(), TheProduct(100.00) {
    }

    virtual ~RedPencilPromotionTest() {
    }

    Product TheProduct;
};


TEST_F(RedPencilPromotionTest, WhenThePriceIsReducedByFivePercentThenAPromotionIsStarted) {
    TheProduct.SalePrice = 95.00;
    EXPECT_TRUE(TheProduct.IsPromotion());
}

TEST_F(RedPencilPromotionTest, WhenThePriceIsReducedByLessThanFivePercentThenAPromotionIsNotStarted) {
    TheProduct.SalePrice = 95.01;
    EXPECT_FALSE(TheProduct.IsPromotion());
}

TEST_F(RedPencilPromotionTest, WhenThePriceIsReducedByThirtyPercentThenAPromotionIsStarted) {
    TheProduct.SalePrice = 70.00;
    EXPECT_TRUE(TheProduct.IsPromotion());
}

TEST_F(RedPencilPromotionTest, WhenThePriceIsReducedByMoreThanThirtyPercentThenAPromotionIsNotStarted) {
    TheProduct.SalePrice = 69.99;
    EXPECT_FALSE(TheProduct.IsPromotion());
}
