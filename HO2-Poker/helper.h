/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This file contains convenience functions that you can use in your solution.
 * You are free to use when implementing, testing, or debugging your solution.
 ******************************************************************************/
#include "defs.h"

/**
 * Returns a null card (rank 0, suit 'x')
 * @return A null card
 */
Card nullCard();

/**
 * Converts a card's rank from integer to its string representation
 * @param result The string where to store the string representation
 * @param cardRank The card rank to convert
 */
void cardRankToString(String40 result, int cardRank);

/**
 * Displays a card
 * @param c The card to display
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayCard(Card c, int colorOn);

/**
 * Displays an array of cards
 * @param c The array of cards to display
 * @param size The size of the array
 * @param colorOn Flag whether to enable/disable printing colors to the
 *          terminal; 1 means enable colors, 0 means disable colors
 */
void displayCards(Card c[], int size, int colorOn);

/**
 * Checks if the card is a null card or not
 * @param c The card to check
 * @return 1 if the card is a null card, 0 otherwise
 */
int isNullCard(Card c);

/**
 * Counts how many cards are actually present in an array.
 * It stops counting the moment it sees a null card (similar to strlen).
 * @param cards The array of cards
 * @param size The max size of the array
 * @return The number of cards actually present in the array
 */
int countCards(Card cards[], int size);
