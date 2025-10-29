#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to get computer's move
char getComputerMove() {
    int move;
    move = rand() % 3; // generates 0, 1, or 2
    if (move == 0) return 'r'; // Rock
    else if (move == 1) return 'p'; // Paper
    else return 's'; // Scissors
}

// Function to determine game result
int getResult(char playerMove, char compMove) {
    if (playerMove == compMove) return 0; // Draw
    if ((playerMove == 'r' && compMove == 's') ||
        (playerMove == 'p' && compMove == 'r') ||
        (playerMove == 's' && compMove == 'p'))
        return 1; // Player wins
    return -1; // Computer wins
}

int main() {
    srand(time(0)); // Seed RNG
    char playerMove;
    cout << "Welcome to Rock, Paper, Scissors Game!\n";
    cout << "Enter r for ROCK, p for PAPER, and s for SCISSORS: ";

    // Input validation loop
    while (true) {
        cin >> playerMove;
        if (playerMove == 'r' || playerMove == 'p' || playerMove == 's')
            break;
        cout << "Invalid Move! Enter r, p, or s: ";
    }

    char compMove = getComputerMove();
    int result = getResult(playerMove, compMove);

    cout << "Your Move: " << (playerMove == 'r' ? "Rock" : playerMove == 'p' ? "Paper" : "Scissors") << endl;
    cout << "Computer's Move: " << (compMove == 'r' ? "Rock" : compMove == 'p' ? "Paper" : "Scissors") << endl;

    if (result == 0)
        cout << "Game Draw!\n";
    else if (result == 1)
        cout << "Congratulations! You won the game!\n";
    else
        cout << "Oh! Computer won the game!\n";

    return 0;
}
