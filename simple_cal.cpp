#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getNumber(const std::string& prompt) {
    double num;
    std::cout << prompt;
    while (!(std::cin >> num)) {
        std::cout << "🚫 Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    return num;
}

char getOperation() {
    char op;
    std::cout << "\nChoose operation:\n";
    std::cout << "➕ (a) Addition\n";
    std::cout << "➖ (s) Subtraction\n";
    std::cout << "✖ (m) Multiplication\n";
    std::cout << "➗ (d) Division\n";
    std::cout << "Your choice (a/s/m/d): ";
    std::cin >> op;
    clearInputBuffer();
    return op;
}

void performCalculation() {
    double num1 = getNumber("Enter the first number: ");
    double num2 = getNumber("Enter the second number: ");
    char operation = getOperation();
    double result;
    bool valid = true;

    std::cout << "\n🔍 Processing...\n";

    switch (operation) {
        case 'a':
        case 'A':
            result = num1 + num2;
            std::cout << "➕ Result: " << result << "\n";
            break;
        case 's':
        case 'S':
            result = num1 - num2;
            std::cout << "➖ Result: " << result << "\n";
            break;
        case 'm':
        case 'M':
            result = num1 * num2;
            std::cout << "✖ Result: " << result << "\n";
            break;
        case 'd':
        case 'D':
            if (num2 == 0) {
                std::cout << "🚫 Division by zero is undefined!\n";
                valid = false;
            } else {
                result = num1 / num2;
                std::cout << "➗ Result: " << result << "\n";
            }
            break;
        default:
            std::cout << "❌ Invalid operation choice!\n";
            valid = false;
    }

    if (valid)
        std::cout << "✅ Calculation completed successfully.\n";
}

char playAgain() {
    char choice;
    std::cout << "\n🔁 Do you want to perform another calculation? (y/n): ";
    std::cin >> choice;
    clearInputBuffer();
    return choice;
}

int main() {
    std::cout << "📟 Welcome to Multi-Feature Calculator 📟\n";
    std::cout << "----------------------------------------\n";

    char again;
    do {
        performCalculation();
        again = playAgain();
    } while (again == 'y' || again == 'Y');

    std::cout << "\n👋 Thank you for using the calculator. Goodbye!\n";
    return 0;
}