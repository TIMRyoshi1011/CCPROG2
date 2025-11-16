/******************************************************************************
 * DO NOT MODIFY THIS FILE (except for #include "POKER-LASTNAME.c")
 *
 * This contains the main() function for testing your solution. This file will
 * show you the result of each function that you need to implement.
 ******************************************************************************/

/******************************************************************************
 * TODO: Modify the line below with the updated filename
 ******************************************************************************/
#include "POKER-LASTNAME.c"

/******************************************************************************
 * This is the main() function for displaying your final solution.
 *
 * You are not supposed to modify the contents and the logic of this function.
 *
 * If you need to experiment, i.e. you'd like to edit/introduce new codes, then
 * it is suggested that you copy this file, and make changes on your copy.
 *
 * Note that the teacher-in-charge of checking your solution may use another
 * set of input data and a different main() function.
 *
 * Your functions should work correctly even with a different set of input data
 * and a different main() function.
 *
 *******************************************************************************
 *
 * Compile and run main.c with input redirection. If you want to display the
 * cards with colors in the terminal, use the "color_on" flag.
 *
 *               compile:  prompt~> gcc -Wall -std=c99 main.c
 *   display (no colors):  prompt~> a < INPUT1.txt
 *   display (w/ colors):  prompt~> a color_on < INPUT1.txt
 *
 ******************************************************************************/

int main(int argc, char *argv[])
{
  Card communityCards[N_COMM_CARDS];
  Player players[N_PLAYERS];

  int colorOn = 0; // flag for enabling/disabling the color, disabled by default
  if (argc == 2 && strcmp(argv[1], "color_on") == 0)
    colorOn = 1; // enable printing with colors in terminal

  getInput(communityCards, players);
  displayInput(players, communityCards, colorOn);

  printf("\n\n\n");
  printf("+------------------------+\n");
  printf("| TASK #1: Combine Cards |\n");
  printf("+------------------------+\n");
  displayTask1(players, communityCards, colorOn);

  printf("\n\n");
  printf("+-------------------------------+\n");
  printf("| TASK #2: Populate Card Matrix |\n");
  printf("+-------------------------------+\n\n");
  displayTask2(players, colorOn);

  printf("\n\n");
  printf("+---------------------------------+\n");
  printf("| TASK #3: Has Flush Combination? |\n");
  printf("+---------------------------------+\n");
  displayTask3(players, colorOn);

  printf("\n\n");
  printf("+---------------------------------------+\n");
  printf("| TASK #4: Has N-Of-A-Kind Combination? |\n");
  printf("+---------------------------------------+\n\n");
  displayTask4(players, colorOn);

  printf("\n\n");
  printf("+-------------------------------+\n");
  printf("| TASK #5: Identify Combination |\n");
  printf("+-------------------------------+\n");
  displayTask5(players);

  return 0;
}
