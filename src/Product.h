#include <ctime>

#pragma once

namespace RedPencilPromotion {
    class Product {
    public:
        Product(const double &standardPrice);

        virtual ~Product();

        bool const IsPromotion() const;

        const double StandardPrice;
        double SalePrice;
        std::time_t PriceLastUpdated;
    };
}