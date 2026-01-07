# C Financial Calculator (CLI)

## Overview
A low-level command-line tool written in pure **C** to perform core quantitative finance calculations. This project demonstrates manual memory management and algorithm implementation for financial mathematics without relying on external high-level libraries.

**Key Features:**
- **Bond Pricing Engine:** Calculates the present value of fixed-income assets using discrete discounting loops.
- **TVM Solver:** Time Value of Money calculations (PV/FV) for capital budgeting.
- **Interest Models:** Modules for both Simple and Compound interest structures.

## Technical Implementation
- **Language:** C (C11 Standard)
- **Math Logic:** - Implements the discrete summation series for Bond Pricing: $P = \sum \frac{C}{(1+r)^t} + \frac{F}{(1+r)^N}$
  - Handles custom compounding frequencies (Semi-annual, Quarterly, Continuous).
- **Architecture:** Modular function design with a persistent CLI menu loop.
