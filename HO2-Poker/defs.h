/******************************************************************************
 * DO NOT MODIFY THIS FILE.
 *
 * This is the header file for the POKER hands-on exam problem.
 ******************************************************************************/
#ifndef DEFS
#define DEFS

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] CONSTANTS
 ******************************************************************************/
#define RESET_COLOR "\033[0m"               // reset to default bg and fg
#define RED_CARD_COLOR "\033[47m\033[31m"   // white bg, red fg
#define BLACK_CARD_COLOR "\033[47m\033[30m" // white bg, black fg
#define NULL_CARD_COLOR "\033[45m\033[37m"  // magenta bg, white fg

#define N_COMM_CARDS 5     // Number of community cards
#define N_HOLE_CARDS 2     // Number of player hole cards
#define N_COMBINED_CARDS 7 // Number of community cards + player hole cards
#define N_HAND_CARDS 5     // Number of poker combination hand cards
#define N_PLAYERS 4        // Number of players
#define N_SUITS 4          // Number of suits
#define N_SUIT_CARDS 13    // Number of cards per suit

#define SUIT_CLUBS 'c'    // Represents the clubs suit
#define SUIT_DIAMONDS 'd' // Represents the diamonds suit
#define SUIT_HEARTS 'h'   // Represents the hearts suit
#define SUIT_SPADES 's'   // Represents the spades suit

#define STR_NO_COMBI "No combination yet" // No combination string
#define STR_4_OF_A_KIND "Four Of A Kind"  // Partial combination string for Four Of A Kind
#define STR_3_OF_A_KIND "Three Of A Kind" // Partial combination string for Three Of A Kind
#define STR_ONE_PAIR "One Pair"           // Partial combination string for One Pair
#define STR_FLUSH "Flush"                 // Partial combination string for Flush

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] TYPEDEFS and STRUCTURE TEMPLATES
 ******************************************************************************/

typedef char String40[41];

/**
 * Represents a card
 */
typedef struct CardTag
{
  int rank;
  char suit;
} Card;

/**
 * Represents a player
 */
typedef struct PlayerTag
{
  String40 name;
  Card holeCards[N_HOLE_CARDS];
  Card combinedCards[N_COMBINED_CARDS];
  Card cardMatrix[N_SUIT_CARDS][N_SUITS];
  String40 bestCombiStr;
} Player;

/******************************************************************************
 * [GIVEN / DO NOT MODIFY] FUNCTION PROTOTYPES
 *
 * These are the function prototypes for the functions that you need to
 * implement in the file POKER-LASTNAME.c
 *
 * You are not allowed to modify/change the return type nor parameters.
 ******************************************************************************/

void combineCards(Card playerCombinedCards[], Card playerHoleCards[], Card commCards[]);
void populateCardMatrix(Card cardMatrix[][N_SUITS], Card combinedCards[]);
char hasFlushCombination(Card combinedCards[]);
int hasOfAKindCombination(Card cardMatrix[][N_SUITS], int N);
void identifyCombination(Player *ptrP);

#endif // DEFS