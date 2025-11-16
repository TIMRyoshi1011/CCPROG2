/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains some convenience functions that you can use in your
 * solution.
 ******************************************************************************/
#ifndef HELPER_C
#define HELPER_C

#include <stdio.h>
#include <string.h>
#include "helper.h"

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONVENIENCE / HELPER FUNCTIONS FOR STUDENTS
 *
 * These are convenience/helper functions which you are free to use when
 * implementing, testing, or debugging your solution. The documentation is
 * indicated in helper.h
 ******************************************************************************/

Card nullCard()
{
  Card null_card;
  null_card.rank = 0;
  null_card.suit = 'x';
  return null_card;
}

void cardRankToString(String40 result, int cardRank)
{
  char rankstr[14][3] = {"0", "A", "2", "3", "4", "5", "6",
                         "7", "8", "9", "10", "J", "Q", "K"};
  strcpy(result, rankstr[cardRank]);
}

void displayCard(Card c, int colorOn)
{
  String40 cardRankStr, cardColor;
  cardRankToString(cardRankStr, c.rank);

  if (colorOn) // Print with color
  {
    // Set card color
    if (c.suit == SUIT_HEARTS || c.suit == SUIT_DIAMONDS)
      strcpy(cardColor, RED_CARD_COLOR);
    else if (c.suit == SUIT_CLUBS || c.suit == SUIT_SPADES)
      strcpy(cardColor, BLACK_CARD_COLOR);
    else
      strcpy(cardColor, NULL_CARD_COLOR);

    printf("%s %2s%c %s ", cardColor, cardRankStr, c.suit, RESET_COLOR);
  }
  else // Print with no color
  {
    printf(" %2s%c  ", cardRankStr, c.suit);
  }
}

void displayCards(Card c[], int size, int colorOn)
{
  int i;
  for (i = 0; i < size; i++)
    displayCard(c[i], colorOn);
}

int isNullCard(Card c)
{
  int check = 0;
  Card null_card = nullCard();
  if (c.rank == null_card.rank && c.suit == null_card.suit)
    check = 1;
  return check;
}

int countCards(Card cards[], int size)
{
  int i = 0, count = 0;
  while (!isNullCard(cards[i]) && i < size)
  {
    count++;
    i++;
  }
  return count;
}

/******************************************************************************
 * [DO NOT MODIFY] Initializations
 ******************************************************************************/

/**
 * Initializes an array of cards to be all null cards
 * @param cards The array of cards to initialize
 * @param size The size of the array
 */
void initializeCards(Card cards[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    cards[i] = nullCard();
}

/**
 * Creates and partially initializes a player structure
 * @return A player structure with initialized combinedCards, cardMatrix,
 *   and bestCombiStr
 */
Player initializePlayer()
{
  Player p;
  int i;

  // Initialize combinedCards
  initializeCards(p.combinedCards, N_COMBINED_CARDS);

  // Initialize cardMatrix
  for (i = 0; i < N_SUIT_CARDS; i++)
    initializeCards(p.cardMatrix[i], N_SUITS);

  // Initialize bestCombiStr
  strcpy(p.bestCombiStr, STR_NO_COMBI);

  return p;
}

/******************************************************************************
 * [DO NOT MODIFY] Input handling
 ******************************************************************************/

/**
 * Handles populating a card structure with input from stdin
 * @return A populated card structure
 */
Card getCardInput()
{
  Card c;
  scanf("%d\n", &c.rank);
  scanf("%c", &c.suit);
  return c;
}

/**
 * Handles getting the input from stdin
 * @param commCards The array where to store the community card data input
 * @param players The array where to store the player data input
 */
void getInput(Card commCards[], Player players[])
{
  int i, j;

  // Populate community cards
  for (i = 0; i < N_COMM_CARDS; i++)
    commCards[i] = getCardInput();

  for (i = 0; i < N_PLAYERS; i++)
  {
    // Initialize player members
    players[i] = initializePlayer();

    // Populate player name and hole cards
    scanf("%s", players[i].name);
    for (j = 0; j < N_HOLE_CARDS; j++)
      players[i].holeCards[j] = getCardInput();
  }
}

/******************************************************************************
 * [DO NOT MODIFY] Display output
 ******************************************************************************/

/**
 * Displays the input
 * @param p The array of players
 * @param commCards The array of community cards
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayInput(Player p[], Card commCards[], int colorOn)
{
  int i;
  printf("+----------------+\n");
  printf("| INPUT: Players |\n");
  printf("+----------------+\n");
  for (i = 0; i < N_PLAYERS; i++)
  {
    printf("%15s: ", p[i].name);
    displayCard(p[i].holeCards[0], colorOn);
    displayCard(p[i].holeCards[1], colorOn);
    printf("\n");
  }

  printf("\n\n");
  printf("+------------------------+\n");
  printf("| INPUT: Community Cards |\n");
  printf("+------------------------+\n");
  printf("  ");
  for (i = 0; i < N_COMM_CARDS; i++)
    displayCard(commCards[i], colorOn);
}

/**
 * Displays the results of Task 1: Combine Cards
 * @param p The array of players
 * @param commCards The array of community cards
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayTask1(Player p[], Card commCards[], int colorOn)
{
  int i, j;

  for (i = 0; i < N_PLAYERS; i++)
  {
    // Call student function
    combineCards(p[i].combinedCards, p[i].holeCards, commCards);

    // Display
    printf("%15s: ", p[i].name);
    for (j = 0; j < N_HOLE_CARDS + N_COMM_CARDS; j++)
      displayCard(p[i].combinedCards[j], colorOn);
    printf("\n");
  }
}

/**
 * Displays the results of Task 2: Populate Card Matrix
 * @param p The array of players
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayTask2(Player p[], int colorOn)
{
  int i, j;

  // Call student function
  for (i = 0; i < N_PLAYERS; i++)
    populateCardMatrix(p[i].cardMatrix, p[i].combinedCards);

  // Display
  printf("%3s | %-23s | %-23s | %-23s | %-23s\n", "idx", p[0].name, p[1].name, p[2].name, p[3].name);
  printf("--- + ----------------------- + ----------------------- + ----------------------- + -----------------------\n");
  for (i = 0; i < N_SUIT_CARDS; i++)
  {
    printf("%3d | ", i);
    for (j = 0; j < N_SUITS; j++)
      displayCard(p[0].cardMatrix[i][j], colorOn);

    printf("| ");
    for (j = 0; j < N_SUITS; j++)
      displayCard(p[1].cardMatrix[i][j], colorOn);

    printf("| ");
    for (j = 0; j < N_SUITS; j++)
      displayCard(p[2].cardMatrix[i][j], colorOn);

    printf("| ");
    for (j = 0; j < N_SUITS; j++)
      displayCard(p[3].cardMatrix[i][j], colorOn);

    printf("\n");
  }
}

/**
 * Displays the results of Task 3: Has Flush Combination?
 * @param p The array of players
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayTask3(Player p[], int colorOn)
{
  int i;
  char result;

  for (i = 0; i < N_PLAYERS; i++)
  {
    // Call student function
    result = hasFlushCombination(p[i].combinedCards);

    if (colorOn &&
        (result == SUIT_CLUBS || result == SUIT_DIAMONDS ||
         result == SUIT_HEARTS || result == SUIT_SPADES))
      // Print with color
      printf("%15s: %s %c %s\n", p[i].name, RED_CARD_COLOR, result, RESET_COLOR);
    else // Print with no color
      printf("%15s:  %c \n", p[i].name, result);
  }
}

/**
 * Displays a "result cell" in the Task 4 results
 * @param result The result value to display
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void printTask4Result(int result, int colorOn)
{
  if (colorOn && 1 <= result && result <= 13) // Print with color
    printf("%s%3d %s  ", RED_CARD_COLOR, result, RESET_COLOR);
  else // Print with no color
    printf("%3d   ", result);
}

/**
 * Displays the results of Task 4: Has N-Of-A-Kind Combination?
 * @param p The array of players
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayTask4(Player p[], int colorOn)
{
  int i, result;

  printf("%15s  %4s  %4s  %4s\n", "Player Name", "N=4", "N=3", "N=2");
  printf("---------------  ----  ----  ----\n");

  // Call student function and display
  for (i = 0; i < N_PLAYERS; i++)
  {
    printf("%14s:  ", p[i].name);

    result = hasOfAKindCombination(p[i].cardMatrix, 4);
    printTask4Result(result, colorOn);

    result = hasOfAKindCombination(p[i].cardMatrix, 3);
    printTask4Result(result, colorOn);

    result = hasOfAKindCombination(p[i].cardMatrix, 2);
    printTask4Result(result, colorOn);

    printf("\n");
  }
}

/**
 * Displays the results of Task 5: Identify Combination
 * @param p The array of players
 */
void displayTask5(Player p[])
{
  int i;
  for (i = 0; i < N_PLAYERS; i++)
  {
    // Call student function
    identifyCombination(&p[i]);

    // Display
    printf("%15s: %s\n", p[i].name, p[i].bestCombiStr);
  }
}

#endif // HELPER_C