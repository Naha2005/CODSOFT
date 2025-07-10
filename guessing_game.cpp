#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Clear invalid input from the input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Get a valid integer guess from the user
int getValidGuess() {
    int guess;
    while (!(std::cin >> guess)) {
        std::cout << "🚫 Invalid input. Please enter a number: ";
        clearInputBuffer();
    }
    return guess;
}

// Ask the user if they want to play again
char playAgain() {
    char response;
    std::cout << "\n🔁 Do you want to play again? (y/n): ";
    std::cin >> response;
    clearInputBuffer();
    return response;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation

    std::cout << "🎯 Welcome to the Number Guessing Game! 🎯\n";
    std::cout << "-----------------------------------------\n";

    char again;
    do {
        int secretNumber = std::rand() % 100 + 1;
        int userGuess;
        int attempts = 0;

        std::cout << "\n🤔 I'm thinking of a number between 1 and 100.\n";

        do {
            std::cout << "🔢 Enter your guess: ";
            userGuess = getValidGuess();
            attempts++;

            if (userGuess > secretNumber) {
                std::cout << "📉 Too high! Try again.\n";
            } else if (userGuess < secretNumber) {
                std::cout << "📈 Too low! Try again.\n";
            } else {
                std::cout << "🎉 Congratulations! You guessed it in " << attempts << " attempts! 🏆\n";
            }

        } while (userGuess != secretNumber);

        again = playAgain();

    } while (again == 'y' || again == 'Y');

    std::cout << "\n🙏 Thanks for playing! Goodbye!\n";
    return 0;
} 