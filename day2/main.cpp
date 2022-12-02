#include <iostream>


using namespace std;

int part1();
int part2();

int main() {
	int score = part1();
	cout << "Your score from part 1 is: " << score << '\n';
	
	
	score = part2();
	cout << "Your score from part 2 is: " << score << endl;
	return 0;
}


int part1() {
	/*
	 * Opponent 
	 * A = Rock
	 * B = Paper
	 * C = Scissor
	 *
	 * Player
	 * X = Rock
	 * Y = Paper
	 * Z = Scissor
	 */

	char opponent, player;
	int score;
	while (cin >> opponent >> player) {
		//Rock
		if (player == 'X') {
			score += 1;
			// Rock vs Rock
			if (opponent == 'A') {
				score += 3;
			}
			//Rock vs Paper
			else if(opponent == 'B') {
				score += 0;
			}
			// Rock vs Scissor
			else {
				score += 6;
			}
		}
		//Paper
		else if (player == 'Y') {
			score += 2;
			// vs Rock
			if (opponent == 'A')
			{
				score += 6;
			}
			// vs Paper
			else if (opponent == 'B') {
				score += 3;
			} // vs scissor
			else {
				score += 0;
			}
		}
		//Scissor
		else { 
			score += 3;
			// vs Rock
			if (opponent == 'A') {
				score += 0;
			}
			//vs Paper
			else if (opponent == 'B') {
				score += 6;
			}
			// vs Scissor
			else score += 3;
		}
	}
	return score;
}
int part2 () {
    /*
	 * Opponent 
	 * A = Rock
	 * B = Paper
	 * C = Scissor
	 *
	 * Player
	 * X = Rock
	 * Y = Paper
	 * Z = Scissor
	 */

	char opponent, player;
	int score{0};
	while (cin >> opponent >> player) {
	    //Rock
		if (player == 'X') { //lose
			score += 0;
			// Rock vs Rock
			if (opponent == 'A') {
				score += 3;
			}
			//Rock vs Paper
			else if(opponent == 'B') {
				score += 1;
			}
			// Rock vs Scissor
			else {
				score += 2;
			}
		}
		//Paper
		else if (player == 'Y') {
			score += 3;
			// vs Rock
			if (opponent == 'A')
			{
				score += 1;
			}
			// vs Paper
			else if (opponent == 'B') {
				score += 2;
			} // vs scissor
			else {
				score += 3;
			}
		}
		//Scissor
		else { 
			score += 6;
			// vs Rock
			if (opponent == 'A') {
				score += 2;
			}
			//vs Paper
			else if (opponent == 'B') {
				score += 3;
			}
			// vs Scissor
			else score += 1;
		}
	    
	}
	return score;
}
