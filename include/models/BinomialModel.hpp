#ifndef BINOMIAL_MODEL_HPP
#define BINOMIAL_MODEL_HPP

#include "models/OptionPricingModel.hpp"
#include "domain/Option.hpp"

class BinomialModel : public OptionPricingModel {
public:
    BinomialModel();

    // Calculates the option price using the binomial tree method
    virtual double calculatePrice(const Option& option) const override;

    // 🔹 NEW: Setter to control number of steps dynamically
    void setSteps(int n) { numSteps_ = n; }

private:
    int numSteps_ = 100; // Default number of steps for the binomial tree
};

#endif // BINOMIAL_MODEL_HPP
