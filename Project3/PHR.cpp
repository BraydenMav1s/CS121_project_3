#include <iostream>
#include <random>    // Needed for std::random_device and std::uniform_int_distribution
#include <limits>    // Needed for std::numeric_limits and for std::cin.ignore()

const int NUM_HORSES   = 5;
const int TRACK_LENGTH = 15;

// Function prototypes
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

// Creating the random device and coin-flip.
std::random_device rd;
std::uniform_int_distribution<int> dist(0, 1);

int main() {
    // Array created for 5 horses
    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};

    bool keepGoing = true;

    while (keepGoing) {

        for (int hn = 0; hn < NUM_HORSES; hn++) {
            advance(hn, horses);
            printLane(hn, horses);

            if (isWinner(hn, horses)) {
                std::cout << "Horse " << hn << " WINS!!!\n";
		   keepGoing = false;
            }
        }

        // If still no winner, wait for Enter before the next turn
        if (keepGoing) {
            std::cout << "Press enter for another turn.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Someones lucky horse won!
    std::cout << "Race finished!\n";

    return 0;
}



void advance(int horseNum, int* horses) {
    int random_number = dist(rd);
    // Advance the horse by 1 if flip is heads (1)
    if (random_number == 1) {
        horses[horseNum]++;
    }
}



void printLane(int horseNum, int* horses) {
    // Print a 15 character lane, placing the horse number at the horse’s position
    for (int pos = 0; pos < TRACK_LENGTH; pos++) {
        if (pos == horses[horseNum]) {
            std::cout << horseNum;
        } else {
            std::cout << ".";
        }
    }
    // If the horse has actually passed the finish line, show it at the end
    if (horses[horseNum] >= TRACK_LENGTH) {
        std::cout << horseNum;
    }
    std::cout << "\n";
}


bool isWinner(int horseNum, int* horses) {
    // Returns true if the horse’s position is at or beyond the finish line
    return (horses[horseNum] >= TRACK_LENGTH);
}

