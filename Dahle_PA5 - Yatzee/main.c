/*
	Programmer: Isaac Dahle

	Class: CptS 121; Lab Section 1

	Programming Assignment: PA 5

	Date: 10.21.21

	Description: A game of yahtzee that allows two human players to play against each other. The game follows standard yahtzee rules.
*/

/*
Dev Notes:
General:
	I don't need to check if all combos have been used bc the number of rounds will not ever exceed the choices for score combinations
10.25.21
	Put in a bucket sort function. This will be really helpful for creating functions to check the special scoring conditions.
	I also added a function to sum all the dice to help with these functions.
	Set up three of a kind scoring and debugged it
	Set up four of a kind scoring and debugged it
	Set up chance scoring and debugged it
	Set up yatzee scoring and debugged it

10.26.21
	Realized there was an issue with making dice_bucketSort one longer. It was causing my scoring functions (ex. four_of_a_kind, score_yatzee) 
	to not check the last digit in the array. I went and shortened dice_bucketSort to have only 6 indicies and now it seems to be working properly.
	Commented out roll_dice so I could test out scoring. Aslo I bookmarked it.
	Set up and debugged full house scoring
	Set up and debugged small straight scoring
	Set up and debugged large straight scoring

	Next Steps: set up adding score bonuses, printing score and declaring winner. Also need to do some thourough whole program debugging

10.28.21
	Set up score bonuses and printing score and declaring winner. I debugged and it worked however none of the players had a high enough score to 
	qualify for the bonus so I may need to hard code values to check if they would recive a bonus.

10.29.21
	Debugged bonus, found that i put = instead of += so that was a good catch
	Added a reset score card function and reset score variables before the play yhatzee loop
	Reset scoreCombination to be -1 every time play yatzee was selected
	Went through and debugged to make sure that the game worked for multiple rounds and the variables were reset each round

*/
#include "Dahle_PA5.h"

int main(void){

	int currentPlayer = 1, round = 1, rollNum = 0, menuSelection = -1, rollAgain = 0, scoreCombination = -1, roundScore = 0;

	int p1_ScoreCard[14] = { 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 }; //the first one is zero bc players cant choose a score card option of 0
	int p2_ScoreCard[14] = { 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

	int p1_bonusScore = 0;
	int p1_totalScore = 0;

	int p2_bonusScore = 0;
	int p2_totalScore = 0;

	int dice[5] = { 0, 0, 0, 0, 0 };
	int dice_bucketSort[6] = { 0, 0, 0, 0, 0, 0 };
	int diceToKeep[5] = { 0, 0, 0, 0 ,0 };

	srand((unsigned int)time(NULL));

	//do-while for menu input
	do
	{
		print_menu();
		menuSelection = get_menu_input();
		system("cls");

		switch (menuSelection)
		{
		case PRINT_RULES:
			print_rules();
			break;
		case PLAY_GAME:
			round = 1; //starts at round 1
			reset_scoreCard(p1_ScoreCard);
			reset_scoreCard(p2_ScoreCard);
			reset_diceToKeep(diceToKeep);

			p1_bonusScore = 0;
			p1_totalScore = 0;

			p2_bonusScore = 0;
			p2_totalScore = 0;

			scoreCombination = -1;
			
			//play the game

			while (round <= 13){
				while(rollNum < MAX_ROLLS){

					printf("Round: %d, Player: %d\n", round, currentPlayer);
					system("pause");

					//roll and display dice
					roll_dice(dice, diceToKeep);
					display_dice(dice);
					reset_bucket_sort_dice(dice_bucketSort);
					bucket_sort_dice(dice, dice_bucketSort);

					rollNum++;

					//rolling again
					if (rollNum < MAX_ROLLS) {
						rollAgain = ask_player_if_they_want_to_roll_again();
					
						if (rollAgain == TRUE) {
							set_diceToKeep(diceToKeep);

							system("cls");
						}
						else {
							system("cls");
							break;
						}
					}

				}//end of rolling while loop

				printf("no more rolling\n");
				system("pause");
				system("cls");

				

				//print score combinations
				display_dice(dice);
				printf("\n");
				print_score_combos();

				//select combination
				if (currentPlayer == PLAYER_1) {
					scoreCombination = prompt_for_combination(p1_ScoreCard);
				}
				else {
					scoreCombination = prompt_for_combination(p2_ScoreCard);
				}
				
				//shouldn't have any issues bc scoreCombination should only be able to be a number 1 to 13 bc of the prompt_for_combination() function
				switch (scoreCombination) 
				{
				case SUM_OF_ONES:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_ONES);
					break;
				case SUM_OF_TWOS:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_TWOS);
					break;
				case SUM_OF_THREES:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_THREES);
					break;
				case SUM_OF_FOURS:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_FOURS);
					break;
				case SUM_OF_FIVES:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_FIVES);
					break;
				case SUM_OF_SIXES:
					roundScore = sum_of_specified_dice_value(dice, NUMBER_OF_DICE, SUM_OF_SIXES);
					break;
				case THREE_0F_A_KIND:
					roundScore = three_of_a_kind_score(dice, dice_bucketSort);
					break;
				case FOUR_OF_A_KIND:
					roundScore = four_of_a_kind_score(dice, dice_bucketSort);
					break;
				case FULL_HOUSE:
					roundScore = full_house_score(dice_bucketSort);
					break;
				case SMALL_STRAIGHT:
					roundScore = small_straight_score(dice_bucketSort);
					break;
				case LARGE_STRAIGHT:
					roundScore = large_straight_score(dice_bucketSort);
					break;
				case YAHTZEE:
					roundScore = yatzee_score(dice_bucketSort);
					break;
				case CHANCE:
					roundScore = sum_dice(dice);
					break;
				}

				//adds round score to player's scorecard
				if (currentPlayer == PLAYER_1) {
					p1_ScoreCard[scoreCombination] = roundScore;
				}
				else {
					p2_ScoreCard[scoreCombination] = roundScore;
				}
				

				system("cls");

				//alternate players
				printf("Changing players\n");
				system("pause");
				system("cls");

				if (currentPlayer == PLAYER_1) {
					currentPlayer = PLAYER_2;	//this is correct bc it is switching the players
				}
				else {
					round++;
					currentPlayer = PLAYER_1;
				}

				//this way the second player won't accidentaly keep some of the other players dice when their turn starts
				reset_diceToKeep(diceToKeep);
				roundScore = 0;
				rollNum = 0;
			} //end of yatzee game

			//check for bonuses
			p1_bonusScore = bonus_score(p1_ScoreCard);
			p2_bonusScore = bonus_score(p2_ScoreCard);

			//get player's total scores
			p1_totalScore = p1_bonusScore + total_of_scoreCard(p1_ScoreCard);
			p2_totalScore = p2_bonusScore + total_of_scoreCard(p2_ScoreCard);

			//print scores
			printf("Player One's Score: %d\n", p1_totalScore);
			printf("Player Two's Score: %d\n", p2_totalScore);

			//print winner
			if (p1_totalScore > p2_totalScore){
				printf("The Winner is Player 1!\n");
			}
			else if (p1_totalScore < p2_totalScore) {
				printf("The Winner is Player 2!\n");
			}
			else {
				printf("It was a tie!\n");
			}

			break;
		case EXIT:
			printf("Goodbye user! Thank you for playing!\n");
			break;
		}
	} while (menuSelection != EXIT);


	return 0;
}