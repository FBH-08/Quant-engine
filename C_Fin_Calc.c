#include <stdio.h>
#include <math.h>

// Function to simple compound interest
double simple_interest(double principal, double rate, float time) 
    {
    return (principal * rate * time) / 100;
    }

// Function to calculate compound interest
double compound_interest(double principal, double rate, float time, float compounds_per_year) 
    {
    return principal * (pow((1 + (rate / (compounds_per_year * 100))), compounds_per_year * time)-1);
    }

// Function to calculate time value of money
double TVM(double future_value, double rate, float time) 
    {
    return future_value / pow((1 + rate / 100), time);
    }

// Function for pricing a bond
double bond_pricing(double face_value, double coupon_rate, double market_yield, float years_to_maturity, int frequency)
    {
        double coupon_payment = face_value * (coupon_rate / 100);
        double total_value = 0;
        double coupon_payment_per_period = coupon_payment / frequency;

        double market_yield_per_period = market_yield / frequency;

        //calculating present value of coupon payments
        for(int payment =1; payment<= years_to_maturity*frequency; payment++)
        {
            double discount = pow((1+market_yield_per_period/100), payment);
            double present_value = coupon_payment_per_period / discount;
            total_value += present_value;
        }
        
        //calculating present value of face value
        double pv_face = face_value / pow((1+market_yield_per_period/100), years_to_maturity*frequency);

        total_value += pv_face;

        return total_value;
    }

    int main()
    {
        printf("Financial Calculator\n");
        
        for(;;)
        {
            printf("What would you like to calculate?\n");
            printf("1. Simple Interest\n2. Compound Interest\n3. Time Value of Money\n4. Bond Pricing\n5.EXIT\n");

            int choice;
            scanf("%d", &choice);

            switch(choice)
            {
                case 1:
                    {
                        double principal, rate;
                        float time;
                        printf("Enter principal amount: ");
                        scanf("%lf", &principal);
                        printf("Enter rate of interest: ");
                        scanf("%lf", &rate);
                        printf("Enter time in years: ");
                        scanf("%f", &time);
                        printf("\n");
                        double si = simple_interest(principal, rate, time);
                        printf("Simple Interest: %.2lf\n", si);
                        printf("total amount: %.2lf\n\n", principal + si);
                        break;
                    }
                case 2:
                    {
                        double principal, rate;
                        float time, compounds_per_year;
                        printf("Enter principal amount: ");
                        scanf("%lf", &principal);
                        printf("Enter rate of interest: ");
                        scanf("%lf", &rate);
                        printf("Enter time in years: ");
                        scanf("%f", &time);
                        printf("Enter number of times interest is compounded per year: ");
                        scanf("%f", &compounds_per_year);
                        printf("\n");
                        double ci = compound_interest(principal, rate, time, compounds_per_year);
                        printf("Compound Interest: %.2lf\n", ci);
                        printf("total amount: %.2lf\n\n", principal + ci);
                        break;
                    }
                case 3:
                    {
                        double future_value, rate;
                        float time;
                        printf("Enter future value: ");
                        scanf("%lf", &future_value);
                        printf("Enter rate of interest: ");
                        scanf("%lf", &rate);
                        printf("Enter time in years: ");
                        scanf("%f", &time);
                        printf("\n");
                        double tvm = TVM(future_value, rate, time);
                        printf("Time Value of Money: %.2lf\n\n", tvm);
                        break;
                    }
                case 4:
                    {
                        double face_value, coupon_rate, market_yield;
                        float years_to_maturity;
                        printf("Enter face value of the bond: ");
                        scanf("%lf", &face_value);
                        printf("Enter coupon rate (in %): ");
                        scanf("%lf", &coupon_rate);
                        printf("Enter market yield (in %): ");
                        scanf("%lf", &market_yield);
                        printf("Enter years to maturity: ");
                        scanf("%f", &years_to_maturity);
                        printf("Enter compounding frequency per year: ");
                        int frequency;
                        scanf("%d", &frequency);
                        printf("\n");
                        double bond_price = bond_pricing(face_value, coupon_rate, market_yield, years_to_maturity, frequency);
                        printf("Bond Price: %.2lf\n\n", bond_price);
                        break;
                    }
                case 5:
                    {
                        printf("Exiting the program.\n");
                        printf("\n");
                        return 0;
                }

            }
            
        }

        return 0;
    }