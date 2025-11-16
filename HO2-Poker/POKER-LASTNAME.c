/******************************************************************************
 * Hands-on Exam #2: POKER
 *
 * Name    : LastName, FirstName
 * Section : S##
 *
 ******************************************************************************
 *
 * 1. Encode your name and section above, as well as rename this file in the
 *    following format: POKER-LASTNAME.c
 *     - Example: POKER-DELACRUZ.c
 *
 * 2. Edit the #include "POKER-LASTNAME.c" in main.c with the updated filename.
 *
 * 3. Compile and run main.c with input redirection. Observe, trace, and
 *    understand what this skeleton code does before doing any changes. If you
 *    want to display the cards with colors in the terminal, use the "color_on"
 *    flag.
 *
 *                  compile:  prompt~> gcc -Wall -std=c99 main.c
 *      display (no colors):  prompt~> a < INPUT1.txt
 *      display (w/ colors):  prompt~> a color_on < INPUT1.txt
 *
 * 4. Implement your solution in this file. This is the C source file that you
 *    should submit/upload in AnimoSpace. Follow all the instructions in the
 *    accompanying specifications file and the instructions written (as function
 *    comments) in this file. Non-compliance may result to a reduction in score/
 *    grade for this exam.
 *
 * 5. Your program must be able to reproduce the same expected output.
 *
 *      prompt~> a < INPUT1.txt > ACTUAL-LASTNAME.txt
 *
 ******************************************************************************/
#include "helper.c"

/******************************************************************************
 * You may define any number of helper functions that you deem necessary below
 * this comment. You are free to decide on the function return type, name, and
 * parametrization of your helper functions.
 ******************************************************************************/

/**
 * TODO #1: Combine Cards
 * This function combines a player's hole cards (2 cards) with the shared
 * community cards (5 cards).
 *
 * @param playerCombinedCards The array where to store the combined player hole
 *          cards and community cards
 * @param playerHoleCards The array of player hole cards (2 cards)
 * @param commCards The array of community cards (5 cards)
 */
void combineCards(Card playerCombinedCards[], Card playerHoleCards[], Card commCards[])
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
}

/**
 * TODO #2: Populate Card Matrix
 * This function arranges a player's combined personal hole cards and community
 * cards in a card matrix. Refer to Section 1.3 of the problem specs on what a
 * card matrix is. Note that all the cards in the card matrix are already
 * initialized with a "null card" (rank 0, suit 'x').
 *
 * (Hint 1: Look at the row index of the card matrix vs. the card rank value)
 * (Hint 2: There is a convenience/helper function in helper.h that you can use)
 *
 * @param cardMatrix A player's 2D card matrix
 * @param combinedCards A player's combined hole cards and community cards
 */
void populateCardMatrix(Card cardMatrix[][N_SUITS], Card combinedCards[])
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
}

/**
 * TODO #3: Has Flush Combination?
 * Given a player's combined cards, this function identifies if a Flush
 * combination (at least 5 cards have the same suit) is present.
 *
 * @param combinedCards A player's combined hole cards and community cards
 * @return The character representing the suit ('c, 'd', 'h', and 's') if the
 *   flush combination is present, 'x' otherwise
 */
char hasFlushCombination(Card combinedCards[])
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  return 'z'; // replace with actual return value
}

/**
 * TODO #4: Has N-Of-A-Kind Combination?
 * Given a player's card matrix, this function identifies if an N-Of-A-Kind
 * combination is present
 *
 *   N = 4 for identifying a Four Of A Kind combination
 *   N = 3 for identifying a Three Of A Kind combination
 *   N = 2 for identifying a Two of A Kind (i.e., One Pair) combination
 *
 * (Hint 1: Look at the row index of the card matrix vs. the card rank value)
 * (Hint 2: There is a convenience/helper function in helper.h that you can use)
 *
 * @param cardMatrix A player's 2D card matrix
 * @param N The number of cards to check per card rank
 * @return The card rank value where the combination is present, -1 otherwise
 */
int hasOfAKindCombination(Card cardMatrix[][N_SUITS], int N)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  return 999; // replace with actual return value
}

/**
 * TODO #5: Identify Combination
 * This function identifies what poker hand combination a player has. It must
 * call and use the results of hasFlushCombination() and hasOfAKindCombination()
 * properly.
 *
 * Once a combination has been identified, the function will update the player's
 * bestCombiStr in the following format:
 *   Four Of A Kind - <card rank>
 *   Flush - <suit>
 *   Three Of A Kind - <card rank>
 *   One Pair - <card rank>
 *
 * (Hint: You may use the provided cardRankToString() convenience/helper
 * function in helper.h to get the string representation of the card rank;
 * e.g., a card whose rank is 1 has "A" as its string representation)
 *
 * @param ptrP A pointer to the player whose hand combination will be identified
 */
void identifyCombination(Player *ptrP)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */
}
