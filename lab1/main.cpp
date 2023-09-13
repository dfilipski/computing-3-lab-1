#include <iostream>
#include <format>

int main()
{
	while (true)
	{
		double interest_rate;

		std::cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
		std::cin >> interest_rate;

		if (interest_rate == 0)
		{
			break;
		}

		double amount;

		std::cout << "Please enter the amount you would like to receive: ";
		std::cin >> amount;

		int loan_duration_months;
		std::cout << "Please enter the loan period in months: ";
		std::cin >> loan_duration_months;

		auto const loan_duration_years = loan_duration_months / 12.0;
		auto const fractional_interest_rate = interest_rate / 100.0;
		auto const total_interest = (amount * fractional_interest_rate) * loan_duration_years;

		auto const total_loan_amount = amount + total_interest;

		auto const monthly_payment = total_loan_amount / loan_duration_months;

		std::cout << std::format("The total amount of your loan (including interest at {}%) is ${}.\n", interest_rate, total_loan_amount);
		std::cout << std::format("Your monthly payment for {} months will be ${:.2f}.\n", loan_duration_months, monthly_payment);
	}
	
}