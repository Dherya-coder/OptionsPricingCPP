#include "Factory/PricingModelFactory.hpp"
#include "domain/Option.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>

int main(int argc, char* argv[]) {

    // === Default Option Parameters ===
    double spotPrice = 100.0;
    double strikePrice = 100.0;
    double riskFreeRate = 0.05;
    double volatility = 0.2;
    double timeToMaturity = 1.0;
    std::string optionType = "call";

    if (argc > 6) {
        try {
            spotPrice = std::stod(argv[1]);
            strikePrice = std::stod(argv[2]);
            riskFreeRate = std::stod(argv[3]);
            volatility = std::stod(argv[4]);
            timeToMaturity = std::stod(argv[5]);
            optionType = argv[6];
        } catch (const std::exception& e) {
            std::cerr << "Error parsing input arguments: " << e.what() << std::endl;
            return 1;
        }
    }

    // === Create the Option Object ===
    Option option(spotPrice, strikePrice, riskFreeRate, volatility, timeToMaturity, optionType);

    // === Print CSV Header ===
    std::cout << "Steps,BinomialPrice,MonteCarloPrice\n";

    // === Loop to Show Convergence ===
    for (int steps = 10; steps <= 1000; steps += 10) {

        // ---------------- Binomial ----------------
        auto binomialModel = PricingModelFactory::createModel("Binomial");
        binomialModel->setSteps(steps);               // calls virtual base method
        double binomialPrice = binomialModel->calculatePrice(option);

        // ---------------- Monte Carlo ----------------
        auto monteCarloModel = PricingModelFactory::createModel("MonteCarlo");
        monteCarloModel->setSimulations(steps * 100); // calls virtual base method
        double monteCarloPrice = monteCarloModel->calculatePrice(option);

        // ---------------- Output ----------------
        std::cout << steps << "," << binomialPrice << "," << monteCarloPrice << std::endl;
    }

    return 0;
}
