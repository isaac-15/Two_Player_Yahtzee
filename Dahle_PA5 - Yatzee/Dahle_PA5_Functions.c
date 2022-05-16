/*
	Programmer: Isaac Dahle

	Class: CptS 121; Lab Section 1

	Programming Assignment: PA 5

	Date: 10.21.21

	Description: A game of yahtzee that allows two human players to play against each other. The game follows standard yahtzee rules.
*/
#include "Dahle_PA5.h"

/*
Function: print_menu
Date Created: 10.21.21
Date Last Modified:
Description: prints out the game menu
Input Parameters: none
Returns: n/a
Preconditions: none
Postconditions: rules are printed to the consol
*/

void print_menu(void) {
	printf("1. Print Game Rules\n");
	printf("2. Start Game of Yahtzee\n");
	printf("3. Exit\n");
}

/*
Function: get_menu_input
Date Created: 10.21.21
Date Last Modified:
Description: gets input for menu
Input Parameters: none
Returns: the user's menu selection
Preconditions: an integer is entered
Postconditions: returns number from 1 to 3
*/
int get_menu_input(void) {
	
	int menu_input = -1;

	do {
		printf("Please enter your selection:\n");
		scanf("%d", &menu_input);
	} while (!(menu_input > 0 && menu_input < 4));

	return menu_input;
}

/*
Function: print_rules
Date Created: 10.21.21
Date Last Modified:
Description: prints the rules of yahtzee
Input Parameters: none
Returns: none
Preconditions: none
Postconditions: the rules of yahtzee are printed
*/
void print_rules(void) {
	printf("The Rules of Yahtzee:\n\n\
The scorecard used for Yahtzee is composed of two sections. An upper section and a lower section. \n\
A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. \n\n");
	printf("\
The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. \n\
If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. \n\
Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. \n\
If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n\n");
	printf("\
The lower section contains a number of poker like combinations.\n\n\
Three-of-a-kind:\t Three dice with the same face.\t\tScore: Sum of all 5 dice\n\
Four-of-a-kind:\t\t Four dice with the same face.\t\tScore: Sum of all 5 dice\n\
Full House:\t\t One pair and a three-of-a-kind.\tScore: 25\n\
Small Straight:\t\t A sequence of 4 dice.\t\t\tScore: 30\n\
Large Straight:\t\t A sequence of 5 dice.\t\t\tScore: 40\n\
Yahtzee:\t\t Five dice with the same face.\t\tScore: 50\n\
Chance:\t\t\t Can be used for any combination.\tScore: Sum of all 5 dice\n\n");
}

/*
Function: roll_dice
Date Created: 10.21.21
Date Last Modified:
Description: takes an array of dice and rolls the selected ones
Input Parameters: pointer to an array of dice to be rolled, pointer to a parallel array which says which dice to keep
Returns: adress of the dice array
Preconditions: none
Postconditions: the unkept dice in diceArray are changed to a new random roll
*/
int* roll_dice(int* diceArray, int* diceToKeep) {

	for (int index = 0; index < NUMBER_OF_DICE; index++) {

		if (diceToKeep[index] == 0) {
			diceArray[index] = rand() % 6 + 1;
		}
	}
}

/*
Function: display_dice
Date Created: 10.21.21
Date Last Modified:
Description: Displays all of the dice
Input Parameters: adress of the dice array
Returns: nothing
Preconditions: none
Postconditions: all values of diceArray are printed
*/
void display_dice(int* diceArray) {

	for (int index = 0; index < NUMBER_OF_DICE; index++) {
		printf("Die %d: %d\n", index + 1, diceArray[index]);
	}
}

/*
Function: set_diceToKeep()
Date Created: 10.21.21
Date Last Modified:
Description: asks the user what dice they would like to keep and updates the diceToKeep array
Input Parameters: adress to the diceToKeep array
Returns: the adress to the diceToKeep array
Preconditions: none
Postconditions: the user is prompted for each die if they would like to keep it and the diceToKeep array is updated
*/
int* set_diceToKeep(int* diceToKeep) {

	char keepDie = '\0';

	for (int index = 0; index < NUMBER_OF_DICE; index++) {

		printf("Do you want to keep die %d (y/n): ", index + 1);
		scanf(" %c", &keepDie);

		if (keepDie == 'y') {
			diceToKeep[index] = 1;
		}
		else if (keepDie == 'n') {
			diceToKeep[index] = 0;
		}
		else {
			index--;
		}

	}

}

/*
Function: reset_diceToKeep
Date Created: 10.21.21
Date Last Modified:
Description: resets it so diceToKeep only contains 0s
Input Parameters: address of diceToKeep
Returns: the address of diceToKeep
Preconditions: none
Postconditions: diceToKeep only contains 0s
*/
int* reset_diceToKeep(int* diceToKeep) {

	for (int index = 0; index < NUMBER_OF_DICE; index++) {
		diceToKeep[index] = 0;
	}
}

/*
Function: ask_player_if_they_want_to_roll_again()
Date Created: 10.21.21
Date Last Modified:
Description: asks player if they want to roll again
Input Parameters: none
Returns: if the player wants to roll again, returns 1 else 0
Preconditions: none
Postconditions: user is prompted by printing text to the screen and returns integer
*/
int ask_player_if_they_want_to_roll_again(void) {

	char rollAgain = '\0';
	do {
		printf("Do you want to roll again (y/n): ");
		scanf(" %c", &rollAgain);
	} while (!(rollAgain == 'y' || rollAgain == 'n'));
	
	if (rollAgain == 'y') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
Function: print_score_combos()
Date Created: 10.23.21
Date Last Modified:
Description: prints out the score combinations
Input Parameters: none
Returns: nothing
Preconditions: none
Postconditions: prints out score combinations
*/

void print_score_combos(void) {
	printf("\
1. Sum of Ones:\t\t Score: Sum of all ones\n\
2. Sum of Twos:\t\t Score: Sum of all twos\n\
3. Sum of Threes:\t Score: Sum of all threes\n\
4. Sum of Fours:\t Score: Sum of all fours\n\
5. Sum of Fives:\t Score: Sum of all fives\n\
6. Sum of Sixes:\t Score: Sum of all sixes\n\n");
	printf("\
7. Three-of-a-kind:\t Three dice with the same face.\t\tScore: Sum of all 5 dice\n\
8. Four-of-a-kind:\t Four dice with the same face.\t\tScore: Sum of all 5 dice\n\
9. Full House:\t\t One pair and a three-of-a-kind.\tScore: 25\n\
10. Small Straight:\t A sequence of 4 dice.\t\t\tScore: 30\n\
11. Large Straight:\t A sequence of 5 dice.\t\t\tScore: 40\n\
12. Yahtzee:\t\t Five dice with the same face.\t\tScore: 50\n\
13. Chance:\t\t Can be used for any combination.\tScore: Sum of all 5 dice\n\n");
}

/*
Function: prompt_for_combination
Date Created: 10.23.21
Date Last Modified:
Description: prompts the user for what combination they want to use
Input Parameters: none
Returns: the number of the unused combination, if the combination has already been used then the function returns -1
Preconditions: none
Postconditions: text is printed to screen and returns a value
*/
int prompt_for_combination(int* playerScoreCard) {

	int comboNum = -1;

	do {
		printf("Please select which scoring combination you would like to use: ");
		scanf("%d", &comboNum);
	} while (playerScoreCard[comboNum] != -1);


	return comboNum;
}

/*
Function: sum_of_specified_dice_value()
Date Created: 10.23.21
Date Last Modified:
Description: finds the sum of all dice of a specified number
Input Parameters: dice array and a number to add up
Returns: the sum of the specified number in the dice array
Preconditions: dice are rolled
Postconditions: a value is returned
*/

int sum_of_specified_dice_value(int* dice, int dice_length, int number) {

	int occurencesOfNum = 0, sumOfNumber = 0;

	for (int index = 0; index < dice_length; index++) {
		if (dice[index] == number) {
			occurencesOfNum++;
		}
	}

	sumOfNumber = number * occurencesOfNum;
	return sumOfNumber;
}

/*
Function: update_diceValues()
Date Created: 10.25.21
Date Last Modified:
Description: records the number of ones, twos, threes, fours, fives, and sixes rolled
Input Parameters: diceValues array and the dice array
Returns: the adress to the array with the frequency values
Preconditions: dice have been rolled
Postconditions: the bucket sort array is updated
*/

int* bucket_sort_dice(int* dice, int* bucketSortArr) {

	int diceVal = 0;

	for (int index = 0; index < NUMBER_OF_DICE; index++) {

		diceVal = dice[index];
		bucketSortArr[diceVal - 1] += 1;
	}

	return bucketSortArr;
}

/*
Function:reset_bucket_sort_dice()
Date Created: 10.25.21
Date Last Modified:
Description: sets all values of the dice bucket sort array to 0
Input Parameters: the bucket sort array
Returns: the adress of the bucket sort array
Preconditions: none
Postconditions: all values in the bucket sort array equal 0
*/

int* reset_bucket_sort_dice(int* bucketSortArr) {


	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		bucketSortArr[index] = 0;

	}

}

/*
Function: sum_dice()
Date Created: 10.25.21
Date Last Modified:
Description: sums all the rolled dice
Input Parameters: the dice array
Returns: the sum of all dice
Preconditions: the dice have been rolled
Postconditions: returns the sum of the dice
*/
int sum_dice(int* diceArr) {

	int sum = 0;

	for (int index = 0; index < NUMBER_OF_DICE; index++) {

		sum += diceArr[index];

	}

	return sum;
}

/*
Function: three_of_a_kind_score()
Date Created: 10.25.21
Date Last Modified:
Description: returns the score the player gets for the three of a kind combination
Input Parameters: the dice array, a bucket sort array of the dice
Returns: the score the player recives, 0 if they don't have 3 of a kind and the sum of all dice if they do
Preconditions: the dice are rolled and the bucketSortDice array has been set up
Postconditions: returns a score value
*/

int three_of_a_kind_score(int* dice, int* bucketSortDice) {

	int has_combination = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		if (bucketSortDice[index] >= 3) {
			has_combination = 1;
		}

	}

	if (has_combination) {
		score = sum_dice(dice);
	}

	return score;

}

/*
Function: four_of_a_kind_score()
Date Created: 10.25.21
Date Last Modified:
Description: returns the score the player gets for the four of a kind combination
Input Parameters: the dice array, a bucket sort array of the dice
Returns: the score the player recives, 0 if they don't have 4 of a kind and the sum of all dice if they do
Preconditions: the dice are rolled and the bucketSortDice array has been set up
Postconditions: returns a score value
*/
int four_of_a_kind_score(int* dice, int* bucketSortDice) {

	int has_combination = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		if (bucketSortDice[index] >= 4) {
			has_combination = 1;
		}

	}

	if (has_combination) {
		score = sum_dice(dice);
	}

	return score;

}

/*
Function: yatzee_score()
Date Created: 10.25.21
Date Last Modified:
Description: checks to see if a player has yatzee and returns the appropriate score
Input Parameters: the bucket sorted array for dice
Returns: the score the player recives, 0 if they don't have yatzee and the yatzee score if they do
Preconditions: dice have been rolled and bucket sorted
Postconditions: score value is returned
*/
int yatzee_score(int* bucketSortDice) {

	int has_combination = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		if (bucketSortDice[index] == 5) {
			has_combination = 1;
		}

	}

	if (has_combination) {
		score = YATZEE_SCORE;
	}

	return score;

}

/*
Function: full_house_score()
Date Created: 10.26.21
Date Last Modified:
Description: checks to see if the player has a full house and returns the appropriate score
Input Parameters: the bucket sorted array for dice
Returns: 0 if the player doesn't have a full house and the full house score if they do
Preconditions: dice are rolled and have been bucket sorted into an array
Postconditions: score value is returned
*/

int full_house_score(int* bucketSortDice) {

	int has_three_of_a_kind = 0, has_pair = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

 		if (bucketSortDice[index] >= 3) //works because there is only five dice
		{
			has_three_of_a_kind = 1;
		}
		else if (bucketSortDice[index] >= 2) 
		{
			has_pair = 1;
		}
	}

	if (has_three_of_a_kind && has_pair) {
		score = FULL_HOUSE_SCORE;
	}

	return score;

}

/*
Function: small_straight_score
Date Created: 10.26.21
Date Last Modified:
Description: checks to see if the player has a straight of 4
Input Parameters: an array of the dice bucket sorted
Returns: 0 if the player doesn't have a straight, the small straight score if it does
Preconditions: dice are rolled and bucket sorted
Postconditions: score is returned
*/
int small_straight_score(int* bucketSortDice) {

	int currentRun = 0, longestRun = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		if (bucketSortDice[index] != 0) {
			currentRun++;
		}
		else {
			currentRun = 0;
		}

		if (currentRun > longestRun) {
			longestRun = currentRun;
		}

	}

	if (longestRun >= 4) {
		score = SMALL_STRAIGHT_SCORE;
	}

	return score;


}

/*
Function: large_straight_score
Date Created: 10.26.21
Date Last Modified:
Description: checks to see if the player has a straight of 5
Input Parameters: an array of the dice bucket sorted
Returns: 0 if the player doesn't have a straight, the large straight score if it does
Preconditions: dice are rolled and bucket sorted
Postconditions: score is returned
*/
int large_straight_score(int* bucketSortDice) {

	int currentRun = 0, longestRun = 0, score = 0;

	for (int index = 0; index < DICE_BUCKET_SORT_LENGTH; index++) {

		if (bucketSortDice[index] != 0) {
			currentRun++;
		}
		else {
			currentRun = 0;
		}

		if (currentRun > longestRun) {
			longestRun = currentRun;
		}

	}

	if (longestRun >= 5) {
		score = LARGE_STRAIGHT_SCORE;
	}

	return score;
}

/*
Function: bonus_score
Date Created: 10.28.21
Date Last Modified:
Description: checks to see if the player should recive a bonus
Input Parameters: a player's score card
Returns: 0 if the player dosn't qualify for a bonus and a bonus score if they do
Preconditions: the score card is completely filled out
Postconditions: none
*/
int bonus_score(int* playerScoreCard) {

	int total_of_sum_of = 0, bonus = 0;

	for (int i = 1; i < 7; i++) {
		total_of_sum_of += playerScoreCard[i];
	}

	if (total_of_sum_of >= 63) {
		bonus = 35;
	}

	return bonus;
}

/*
Function: total_of_scoreCard()
Date Created: 10.28.21
Date Last Modified:
Description: totals a player's scorecard
Input Parameters: a player's scorecard
Returns: the sum of all the values in the score card
Preconditions: the score card has been filled out
Postconditions: none
*/
int total_of_scoreCard(int* playerScoreCard)
{
	int sum_of_scoreCard = 0;

	for (int index = 1; index < 14; index++) {
		sum_of_scoreCard += playerScoreCard[index];
	}

	return sum_of_scoreCard;
}

/*
Function: reset_scoreCard()
Date Created:10.29.21
Date Last Modified:
Description: resets a player's score card
Input Parameters: a player's score card
Returns: the adress of the first item in the player's score card
Preconditions: none
Postconditions: the player score card has a -1 at each index except at index 0 where it has a 0
*/
int* reset_scoreCard(int* playerScoreCard) {
	for (int index = 1; index < SCORECARD_LENGTH; index++) {
		playerScoreCard[index] = -1;
	}

	return playerScoreCard;
}
