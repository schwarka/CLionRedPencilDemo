#include "RulesEngine.h"

using namespace RedPencilPromotion;

bool const RulesEngine::IsPriceReducedByAtLeastFivePercent(double const &standardPrice, double const &salePrice) {
    return salePrice <= standardPrice * 0.95;
}

bool const RulesEngine::IsPriceReducedByAtMostThirtyPercent(double const &standardPrice, double const &salePrice) {
    return salePrice >= standardPrice * 0.70;
}
