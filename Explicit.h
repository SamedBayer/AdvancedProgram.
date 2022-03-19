#ifndef EXPLICIT_H
#define EXPLICIT_H

#include "Euler.h"

class Explicit : public Euler {
    public:
        // Add constructor
        Explicit(const std::vector<double> y_0, const double dt, const double t_end, const std::function<std::vector<double>(std::vector<double>)> func);
        // Override solve method
        void solve() override;
};

#endif // EXPLICIT_H