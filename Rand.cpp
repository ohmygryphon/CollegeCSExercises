#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

// --- Class notes ---
// rand()
// returns random number between 0 and the largest int computer can hold
// number = rand() % (max - min + 1) + 1;
// srand()
// set seed for rand() to an unsigned integer
// srand(time(0))
// set seed for rand() to an unsigned integer, unique each runtime

// --- Exercise ---
// Lvl 1: generate, store, and output a series of random numbers between 1 and 100;
//        show the purpose of using srand() and time(), and what happens when misused
// Lvl 2: basic guessing game; generate a random number between 1 and 100, have the user guess the
//        number until they guess correctly, and tell them if it is too high / too low each time
//        (implement rand construct within loops/conditionals)
// Lvl 3: intermediate guessing game; add functionality (custom bounds, counters, interface, input validation)

int main() {

	// Declare common variables
	int randNum; // Random integer
	int guess; // User input
	int guesses; // Counter, total guesses user has made
	int lowBound, highBound; // Custom bounds
	int repeat; // Replay or exit game




	// --- Lvl 1 ---
	std::cout << "Lvl 1:" << std::endl << std::endl;

	// Generate, store and output a "random" number between 1 and 100
	randNum = rand() % 100 + 1;
	std::cout << "randNum is " << randNum << std::endl << std::endl; // Will always output 42
	
	// Set seed to 0
	srand(0);
	randNum = rand() % 100 + 1;
	std::cout << "randNum is " << randNum << std::endl << std::endl; // Will output 39
	
	// Repeat
	srand(0);
	randNum = rand() % 100 + 1;
	std::cout << "randNum is " << randNum << std::endl << std::endl; // Will output 39 again, as the seed was reset

	// Set seed to time(), resulting in a different seed each runtime, therefore generating a more random number
	srand(time(0));
	randNum = rand() % 100 + 1;
	std::cout << "randNum is " << randNum << std::endl << std::endl; // Will output different number each time program executes

	system("pause");





	// --- Lvl 2 ---
	std::cout << "\n\n\nLvl 2:" << std::endl << std::endl;

	randNum = rand() % 100 + 1;

	std::cout << "Basic guessing game! A random integer has been generated between 1 and 100." << std::endl;
	std::cout << "Guess the number until correct, and I'll tell you if you guess high or low." << std::endl << std::endl;

	std::cout << "Guess: ";
	std::cin >> guess;
	while (guess != randNum) {
		if (guess > randNum) {
			std::cout << "Too high! Guess again." << std::endl << std::endl;
		}
		else {
			std::cout << "Too low! Guess again." << std::endl << std::endl;
		}

		std::cout << "Guess: ";
		std::cin >> guess;
	}

	std::cout << guess << " is correct!" << std::endl << std::endl;

	system("pause");





	// --- Lvl 3 ---
	std::cout << "\n\n\nLvl 3:" << std::endl << std::endl;

	std::cout << "Intermediate guessing game!" << std::endl;
	std::cout << "Please enter a lower bound and upper bound for a random value." << std::endl;

	// Menu loop, allow game to be replayed
	repeat = 1;
	do {
		if (repeat == 1) {
			// Allow user to create custom bounds
			do {
				std::cout << "\nLower bound: ";
				std::cin >> lowBound;
				std::cout << "Higher bound: ";
				std::cin >> highBound;

				if (lowBound >= highBound)
					std::cout << "\nPlease enter new bounds; the higher bound must be greater than the lower bound." << std::endl << std::endl;
			} while (lowBound >= highBound);
		}

		// Generate/store random number using custom bounds, initialize guesses counter
		randNum = rand() % (highBound - lowBound + 1) + lowBound;
		guesses = 1;

		std::cout << "\nA random number between " << lowBound << " and " << highBound << std::endl;
		std::cout << "has been generated. Begin guessing, and I'll tell" << std::endl;
		std::cout << "you if you guess too high, too low, or correctly." << std::endl << std::endl;

		// User guesses number until correct
		std::cout << "Guess 1: ";
		std::cin >> guess;
		while (guess != randNum) {
			if (guess > randNum) {
				std::cout << "Too high! Guess again." << std::endl << std::endl;
			}
			else {
				std::cout << "Too low! Guess again." << std::endl << std::endl;
			}

			guesses++;
			std::cout << "Guess " << guesses << ": ";
			std::cin >> guess;
		}

		std::cout << guess << " is correct!" << std::endl;
		std::cout << "You made " << guesses << " guesses." << std::endl << std::endl;

		// Prompt user with options to play again or exit game
		do {
			std::cout << "1: Play again, different bounds" << std::endl;
			std::cout << "2: Play again, same bounds" << std::endl;
			std::cout << "3: End game ";
			std::cin >> repeat;

			if (repeat < 1 || repeat > 3) {
				std::cout << "Invalid response. Please try again." << std::endl;
			}
		} while (repeat < 1 || repeat > 3);
	} while (repeat != 3);

	system("pause");

	return 0;
}
