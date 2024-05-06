#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <sstream>
#include <limits>

// Function to clear screen
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear screen
}

// Function to display ASCII art
void displayTitle() {
    std::cout << "=====================================================\n";
    std::cout << "       Welcome to the Number Guessing Game!\n";
    std::cout << "=====================================================\n";
}

// Function to display game over message
void displayGameOver() {
    std::cout << "\n\n===========================================\n";
    std::cout << "              Game Over!\n";
    std::cout << "===========================================\n";
}

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int maxNumber;
    int difficulty;
    int maxAttempts;
    int highScoreEasy = INT_MAX; // Initialize high scores with maximum integer value
    int highScoreMedium = INT_MAX;
    int highScoreHard = INT_MAX;

    char playAgain;

    do {
        clearScreen(); // Clear the screen
        displayTitle(); // Display title and ASCII art

        std::cout << "\nSelect difficulty level:\n";
        std::cout << "1. Easy (1-50, 10 attempts)\n";
        std::cout << "2. Medium (1-100, 8 attempts)\n";
        std::cout << "3. Hard (1-200, 6 attempts)\n";
        std::cout << "Enter your choice: ";
        std::cin >> difficulty;

        switch (difficulty) {
            case 1:
                maxNumber = 50;
                maxAttempts = 10;
                break;
            case 2:
                maxNumber = 100;
                maxAttempts = 8;
                break;
            case 3:
                maxNumber = 200;
                maxAttempts = 6;
                break;
            default:
                std::cout << "Invalid choice. Please select again.\n";
                continue; // Continue the loop to prompt for difficulty level again
        }

        int randomNumber = rand() % maxNumber + 1; // Generate random number within selected range
        int guess;
        int attempts = 0;

        std::cout << "\n\nTry to guess the number between 1 and " << maxNumber << ". You have " << maxAttempts << " attempts.\n";

        do {
            std::cout << "\nEnter your guess: ";
            std::cin >> guess;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input. Please enter a number.\n";
                continue; // Continue the loop to prompt for input again
            }

            attempts++;

            if (guess == randomNumber) {
                std::cout << "\nCongratulations! You guessed the number in " << attempts << " attempts.\n";
                if (attempts < highScoreEasy && difficulty == 1) {
                    highScoreEasy = attempts;
                    std::cout << "New high score for Easy difficulty!\n";
                } else if (attempts < highScoreMedium && difficulty == 2) {
                    highScoreMedium = attempts;
                    std::cout << "New high score for Medium difficulty!\n";
                } else if (attempts < highScoreHard && difficulty == 3) {
                    highScoreHard = attempts;
                    std::cout << "New high score for Hard difficulty!\n";
                }
                break;
            } else if (guess < randomNumber) {
                std::cout << "\nToo low!";
            } else {
                std::cout << "\nToo high!";
            }

            if (attempts < maxAttempts) {
                std::cout << " You have " << maxAttempts - attempts << " attempts left.\n";
            } else {
                std::cout << " You have used all your attempts. The correct number was " << randomNumber << ".\n";
                break;
            }

        } while (attempts < maxAttempts);

        displayGameOver();

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    clearScreen(); // Clear the screen before exiting
    std::cout << "Thanks for playing!\n\n";
    return 0;
}

