/*
	Programmer: Isaac Dahle

	Class: CptS 121; Lab Section 1

	Programming Assignment: PA 5

	Date: 10.21.21

	Description: A game of yahtzee that allows two human players to play against each other. The game follows standard yahtzee rules.
*/
#ifndef DAHLE_PA5_H
#define DAHLE_PA5_H

#define _CRT_SECURE_NO_WARNINGS

#define PRINT_RULES 1
#define PLAY_GAME 2
#define EXIT 3
#define PLAYER_1 1
#define PLAYER_2 2
#define MAX_ROLLS 3
#define NUMBER_OF_DICE 5 //don't just change this bc the whole game is designed around 5 dice
#define DICE_BUCKET_SORT_LENGTH 6
#define SCORECARD_LENGTH 14
#define TRUE 1
#define FALSE 0

#define SUM_OF_ONES 1
#define SUM_OF_TWOS 2
#define SUM_OF_THREES 3
#define SUM_OF_FOURS 4
#define SUM_OF_FIVES 5
#define SUM_OF_SIXES 6

#define THREE_0F_A_KIND 7
#define FOUR_OF_A_KIND 8
#define FULL_HOUSE 9
#define SMALL_STRAIGHT 10
#define LARGE_STRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13

#define FULL_HOUSE_SCORE 25
#define SMALL_STRAIGHT_SCORE 30
#define LARGE_STRAIGHT_SCORE 40
#define YATZEE_SCORE 50

#include<stdio.h>
#include<stdlib.h>

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

void print_menu(void);

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
int get_menu_input(void);

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
void print_rules(void);

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
int* roll_dice(int* diceArray, int* diceToKeep);

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
void display_dice(int* diceArray);

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
int* set_diceToKeep(int* diceToKeep);

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
int* reset_diceToKeep(int* diceToKeep);

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
int ask_player_if_they_want_to_roll_again(void);

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

void print_score_combos(void);

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
int prompt_for_combination(int* playerScoreCard);

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

int sum_of_specified_dice_value(int* dice, int dice_length, int number);

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

int* bucket_sort_dice(int* dice, int* bucketSortArr);

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

int* reset_bucket_sort_dice(int* bucketSortArr);

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
int sum_dice(int* diceArr);

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
int three_of_a_kind_score(int* dice, int* bucketSortDice);

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
int four_of_a_kind_score(int* dice, int* bucketSortDice);

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
int yatzee_score(int* bucketSortDice);

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

int full_house_score(int* bucketSortDice);

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
int small_straight_score(int* bucketSortDice); 

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
int large_straight_score(int* bucketSortDice);

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
int bonus_score(int* playerScoreCard);

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
int total_of_scoreCard(int* playerScoreCard);

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
int* reset_scoreCard(int* playerScoreCard);

/*
Function:
Date Created:
Date Last Modified:
Description:
Input Parameters:
Returns:
Preconditions:
Postconditions:
*/



#endif