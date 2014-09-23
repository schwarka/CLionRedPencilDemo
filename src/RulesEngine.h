#pragma once

namespace RedPencilPromotion {
    class RulesEngine {

    public:
        static bool const IsPriceReducedByAtLeastFivePercent(double const &standardPrice, double const &salePrice);
        static bool const IsPriceReducedByAtMostThirtyPercent(double const &standardPrice, double const &salePrice);
    };
}

