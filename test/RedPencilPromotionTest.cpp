#include <gtest/gtest.h>
#include "../src/Product.h"

using namespace RedPencilPromotion;
using namespace testing;
using namespace std;

class RedPencilPromotionTest : public Test {

public:
    RedPencilPromotionTest() : Test(), TheProduct(100.00) {
    }

    virtual ~RedPencilPromotionTest() {
    }

    time_t GetDate(const int &daysAgo) {
        time_t t = time(0);
        tm* date = localtime(&t);

        date->tm_hour = 0;
        date->tm_min = 0;
        date->tm_sec = 0;
        date->tm_mday -= daysAgo;

        return mktime(date);
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

TEST_F(RedPencilPromotionTest, GivenThePriceHasChangedWithinTheLastThirtyDaysWhenThePriceIsReducedThenAPromotionIsNotStarted) {
    TheProduct.SalePrice = 90.00;
    TheProduct.PriceLastUpdated = GetDate(29);
    EXPECT_FALSE(TheProduct.IsPromotion());
}
