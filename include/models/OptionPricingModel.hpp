#ifndef OPTION_PRICING_MODEL_HPP
#define OPTION_PRICING_MODEL_HPP

#include "domain/Option.hpp"

class OptionPricingModel {
public:
    virtual ~OptionPricingModel() = default;

    // Core pricing interface
    virtual double calculatePrice(const Option& option) const = 0;

    // 🔹 Optional hooks for parameterization — default no-ops
    virtual void setSteps(int) {}
    virtual void setSimulations(int) {}
};

#endif // OPTION_PRICING_MODEL_HPP
