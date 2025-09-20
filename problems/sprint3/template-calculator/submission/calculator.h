#pragma once

#include <optional>
#include <string>
#include <cmath>
#include "rational.h"
#include "pow.h"

using Error = std::string;

template<class T>
class Calculator {
public:
    Calculator() = default;

    void Set(T number) {
        number_ = number;
    }

    T GetNumber() const {
        return number_;
    }

    std::optional<Error> Add(T n) {
        number_ += n;
        return std::nullopt;
    }

    std::optional<Error> Sub(T n) {
        number_ -= n;
        return std::nullopt;
    }

    std::optional<Error> Mul(T n) {
        number_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Div(T n) {
        if constexpr (std::is_floating_point_v<T>) {
            if (n == static_cast<T>(0)) {
                return "Division by zero";
            }
            number_ /= n;
            return std::nullopt;
        } else {
            if (n == 0) {
                return "Division by zero";
            }
            number_ /= n;
            return std::nullopt;
        }
    }

    std::optional<Error> Pow(T n) {
        if constexpr (std::is_same_v<T, Rational>) {
            if (n.GetDenominator() != 1) {
                return "Fractional power is not supported";
            }
            auto pow = n.GetNumerator();
            auto number = number_.GetNumerator();
            if (pow == 0 && number == 0) {
                return "Zero power to zero";
            }
            number_ = ::Pow(number_, n);
            return std::nullopt;

        } else if constexpr (std::is_floating_point_v<T>) {
            if (n == 0 && number_ == 0) {
                return "Zero power to zero";
            }
            number_ = std::pow(number_, n);
            return std::nullopt;

        } else {
            if (n < 0) {
                return "Integer negative power";
            }
            if (number_ == 0 && n == 0) {
                return "Zero power to zero";
            }
            number_ = IntegerPow(number_, n);
            return std::nullopt;
        }
    }
    void  Save() {
        memory_ = number_;
    }

    void  ClearMemory() {
        memory_.reset();
    }

    void  Load() {
        if (memory_) {
            number_ = *memory_;
        }
    }
    bool  GetHasMem() const {
        if (memory_.has_value()) {
            return true;
        }
        return false;
    }

private:
    std::string operation_;
    T number_;
    std::optional<T> memory_;
};
