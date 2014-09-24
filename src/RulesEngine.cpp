#include "RulesEngine.h"
#include <ctime>
#include <IOKit/IODataQueueClient.h>
#include <ForceFeedback/ForceFeedback.h>

using namespace RedPencilPromotion;

bool const RulesEngine::IsPriceReducedByAtLeastFivePercent(double const &standardPrice, double const &salePrice) {
    return salePrice <= standardPrice * 0.95;
}

bool const RulesEngine::IsPriceReducedByAtMostThirtyPercent(double const &standardPrice, double const &salePrice) {
    return salePrice >= standardPrice * 0.70;
}

time_t const RulesEngine::GetCurrentDate() {
    time_t t = time(0);
    tm* now = localtime(&t);

    now->tm_hour = 0;
    now->tm_min = 0;
    now->tm_sec = 0;

    time_t today = mktime(now);
    return today;
}

bool const RulesEngine::IsPriceStable(time_t const &priceLastUpdated) {
    time_t today = GetCurrentDate();
    double difference = std::difftime(today, priceLastUpdated) / (60 * 60 * 24);

    return difference >= 30;
}
