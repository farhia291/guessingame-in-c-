#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void instructions() {
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Here's how it works:\n";
    cout << "- I will pick a random number between 1 and 100.\n";
    cout << "- Your job is to guess the number.\n";
    cout << "- I'll give you hints: 'Too high' or 'Too low.'\n";
    cout << "- Try to guess the number in as few attempts as possible!\n";
    cout << "Good luck!\n\n";
}

int generateRandomNumber() {
    srand(time(0)); // Seed for randomness
    return rand() % 100 + 1; // Random number between 1 and 100
}

void playGame() {
    int randomNumber = generateRandomNumber();
    int userGuess = 0;
    int attempts = 0;
cout << "I have picked a number between 1 and 100. Start guessing!\n";

    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Input validation
        if (userGuess < 1 || userGuess > 100) {
            cout << "Please enter a number between 1 and 100.\n";
            continue;
        }

        attempts++;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    }
}

void replayOption() {
    char choice;

    do {
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'n') {
            cout << "Invalid input. Enter 'y' to play again or 'n' to quit: ";
            cin >> choice;
        }

    } while (choice == 'y');

    cout << "Thanks for playing! Goodbye!\n";
}

int main() {
    instructions(); // Display instructions
    replayOption(); // Start the game with replay functionality
    return 0;
}




