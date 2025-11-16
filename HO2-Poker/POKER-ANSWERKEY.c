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
 * This task will assess if you can:
 *   - Combine separate 1D arrays of structures into a single 1D array of structures
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

  int i;

  // append hole cards
  for (i = 0; i < N_HOLE_CARDS; i++)
    playerCombinedCards[i] = playerHoleCards[i];

  // append community cards
  for (i = 0; i < N_COMM_CARDS; i++)
    playerCombinedCards[i + N_HOLE_CARDS] = commCards[i];
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
 * This task will assess if you can:
 *   - Access structure members directly via the structure member operator
 *   - Access and manipulate a 1D and 2D array of structures
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

  int i, rowIdx, rowLen;

  // populate matrix
  for (i = 0; i < N_COMBINED_CARDS; i++)
  {
    rowIdx = combinedCards[i].rank - 1;
    rowLen = countCards(cardMatrix[rowIdx], N_SUITS);
    cardMatrix[rowIdx][rowLen] = combinedCards[i];
  }
}

/**
 * TODO #3: Has Flush Combination?
 * Given a player's combined cards, this function identifies if a Flush
 * combination (at least 5 cards have the same suit) is present.
 *
 * This task will assess if you can:
 *   - Access structure members directly via the structure member operator from
 *     a 1D array of structures
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

  int i, cardSuit = 'x';
  int suitsCtr[N_SUITS] = {0, 0, 0, 0};

  for (i = 0; i < N_COMBINED_CARDS; i++)
  {
    if (combinedCards[i].suit == SUIT_CLUBS)
      suitsCtr[0]++;
    else if (combinedCards[i].suit == SUIT_DIAMONDS)
      suitsCtr[1]++;
    else if (combinedCards[i].suit == SUIT_HEARTS)
      suitsCtr[2]++;
    else if (combinedCards[i].suit == SUIT_SPADES)
      suitsCtr[3]++;
  }

  for (i = 0; i < N_SUITS; i++)
    if (suitsCtr[i] >= N_HAND_CARDS)
      switch (i)
      {
      case 0:
        cardSuit = SUIT_CLUBS;
        break;
      case 1:
        cardSuit = SUIT_DIAMONDS;
        break;
      case 2:
        cardSuit = SUIT_HEARTS;
        break;
      case 3:
        cardSuit = SUIT_SPADES;
        break;
      default:
        cardSuit = 'x';
        break;
      }

  return cardSuit;
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
 * This task will assess if you can:
 *   - Access structure members directly via the structure member operator from
 *     a 2D array of structures
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

  int i, rankCount, cardRank = -1;

  for (i = 0; i < N_SUIT_CARDS; i++)
  {
    rankCount = countCards(cardMatrix[i], N_SUITS);
    if (rankCount == N)
      cardRank = i + 1;
  }

  return cardRank;
}

/**
 * Convenience function for building the best combination string
 * @param result The string were to store the best combination string
 * @param combinationName The combination name (i.e., "Flush", "Four Of A Kind",
 *          "Three Of A Kind", or "One Pair")
 * @param cardSuitOrRank The string representation of the card suit or rank
 */
void buildCombinationString(String40 result, char *combinationName, char *cardSuitOrRank)
{
  strcpy(result, combinationName);
  strcat(result, " - ");
  strcat(result, cardSuitOrRank);
}

/**
 * TODO #5: Identify Combination
 * This function identifies what poker hand combination a player has. It must
 * call and use the results of hasFlushCombination() and hasOfAKindCombination()
 * properly.
 *
 * Once a combination has been identified, the function will update the player's
 * bestCombiStr in the following format:
 *   Flush - <suit>
 *   Four Of A Kind - <card rank>
 *   Three Of A Kind - <card rank>
 *   One Pair - <card rank>
 *
 * (Hint: You may use the provided cardRankToString() convenience/helper
 * function in helper.h to get the string representation of the card rank;
 * e.g., a card whose rank is 1 has "A" as its string representation)
 *
 * This task will assess if you can:
 *   - Access structure members indirectly via a structure pointer variable
 *   - Properly pass structure members from a structure pointer variable as
 *     parameters to functions
 *   - Use string functions on structure members
 *
 * @param ptrP A pointer to the player whose hand combination will be identified
 */
void identifyCombination(Player *ptrP)
{ /*
    You may declare and use your own local variables
    Do NOT use printf() nor scanf() in your final solution
    Do NOT modify/change the return type nor parameters
  */

  char cardSuit;
  int cardRank;
  String40 cardSuitOrRank;

  // Flush
  cardSuit = hasFlushCombination(ptrP->combinedCards);
  if (cardSuit != 'x')
  {
    cardSuitOrRank[0] = cardSuit;
    cardSuitOrRank[1] = 0;
    buildCombinationString(ptrP->bestCombiStr, STR_FLUSH, cardSuitOrRank);
  }

  // Others
  if (strcmp(ptrP->bestCombiStr, STR_NO_COMBI) == 0)
  {
    cardRank = hasOfAKindCombination(ptrP->cardMatrix, 4);
    if (cardRank != -1)
    {
      cardRankToString(cardSuitOrRank, cardRank);
      buildCombinationString(ptrP->bestCombiStr, STR_4_OF_A_KIND, cardSuitOrRank);
    }
  }

  if (strcmp(ptrP->bestCombiStr, STR_NO_COMBI) == 0)
  {
    cardRank = hasOfAKindCombination(ptrP->cardMatrix, 3);
    if (cardRank != -1)
    {
      cardRankToString(cardSuitOrRank, cardRank);
      buildCombinationString(ptrP->bestCombiStr, STR_3_OF_A_KIND, cardSuitOrRank);
    }
  }

  if (strcmp(ptrP->bestCombiStr, STR_NO_COMBI) == 0)
  {
    cardRank = hasOfAKindCombination(ptrP->cardMatrix, 2);
    if (cardRank != -1)
    {
      cardRankToString(cardSuitOrRank, cardRank);
      buildCombinationString(ptrP->bestCombiStr, STR_ONE_PAIR, cardSuitOrRank);
    }
  }
}
