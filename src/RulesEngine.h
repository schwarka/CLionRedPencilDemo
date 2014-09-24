#pragma once
#include <time.h>

namespace RedPencilPromotion {
    class RulesEngine {

    public:
        static bool const IsPriceReducedByAtLeastFivePercent(double const &standardPrice, double const &salePrice);
        static bool const IsPriceReducedByAtMostThirtyPercent(double const &standardPrice, double const &salePrice);
        static bool const IsPriceStable(time_t const &priceLastUpdated);

    private:
        static time_t const GetCurrentDate();
    };
}

