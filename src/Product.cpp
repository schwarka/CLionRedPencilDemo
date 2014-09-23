#include "Product.h"
#include "RulesEngine.h"

using namespace RedPencilPromotion;

Product::Product(const double &standardPrice)
        : StandardPrice(standardPrice), SalePrice(0.00) {

}

Product::~Product() {
}

bool const Product::IsPromotion() const {
    return RulesEngine::IsPriceReducedByAtLeastFivePercent(StandardPrice, SalePrice) &&
            RulesEngine::IsPriceReducedByAtMostThirtyPercent(StandardPrice, SalePrice);
}
