/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2025, <Julian Olano Medina, Rivka Sagi, Rhea, Korede>
 * All rights reserved.
 *
 */
 #include "jeopardy.h"
 #include "players.h"
 #include "questions.h"
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <strings.h>
 
 // Put macros or constants here using #define
 #define BUFFER_LEN 256
 #define NUM_PLAYERS 4
 
 // Put global environment variables here
 
 // Processes the answer from the user containing what is or who is and tokenizes
 // it to retrieve the answer.
 void tokenize(char *input, char *tokens) {
   const char *what = "What is";
   const char *who = "Who is";
 
   // Make a copy of the input to avoid modifying the original
   char input_copy[MAX_LEN];
   strncpy(input_copy, input, MAX_LEN - 1);
   input_copy[MAX_LEN - 1] = '\0';
 
   if (strncasecmp(input_copy, what, strlen(what)) == 0 ||
       strncasecmp(input_copy, who, strlen(who)) == 0) {
     // Skip "What is" or "Who is"
 
     // Tokenize safely
     strtok(input_copy, " ");           // "What" or "Who"
     strtok(NULL, " ");                 // "is"
     char *answer = strtok(NULL, "\n"); // Get the actual answer
 
     if (answer) {
       // Safely copy the answer to tokens using snprintf
       snprintf(tokens, MAX_LEN, "%s", answer);
     } else {
       tokens[0] = '\0'; // Empty string if no valid answer
     }
   } else {
     tokens[0] = '\0'; // Properly clear tokens instead of modifying pointer
   }
 }
 
 // Displays the game results for each player, their name and final score, ranked
 // from first to last place
 void show_results(player *players, int num_players) {
   // checks for the max score by storing max score in a variable and swapping if
   // another max is found using selection sort
   for (int i = 0; i < num_players - 1; i++) {
     int max = i; // stores current player as max
     for (int j = i + 1; j < num_players; j++) {
       if (players[j].score > players[max].score) {
         max = j; // stores the player after i as max if it has a greater score
       }
     }
     // swaps player into "hold"
     if (max != i) {
       player hold = players[i];
       players[i] = players[max];
       players[max] = hold;
     }
   }
 
   // displays player result
   printf("Player scoreboard: \n");
   for (int i = 0; i < num_players; i++) {
     printf("%s: %d \n", players[i].name, players[i].score);
   }
 }
 
 // New Function Definitions
 void get_player_names(player player_list[NUM_PLAYERS]) {
   for (int i = 0; i < NUM_PLAYERS; i++) {
     printf("Player %d, What is your name?\n", i + 1);
     fgets(player_list[i].name, MAX_LEN, stdin);
     player_list[i].name[strcspn(player_list[i].name, "\n")] = 0;
   }
 }
 
 void get_next_player(player player_list[NUM_PLAYERS], char currentPlayer[MAX_LEN]) {
   bool flag = true;
   while (flag) {
     printf("Enter the name of the player to go next: \n");
     fgets(currentPlayer, MAX_LEN, stdin);
     currentPlayer[strcspn(currentPlayer, "\n")] = 0;
 
     if (player_exists(player_list, NUM_PLAYERS, currentPlayer)) {
       flag = false;
     } else {
       printf("This player does not exist, try again\n");
     }
   }
 }
 
 void get_category(char currentCategory[MAX_LEN]) {
   bool flag = true;
   while (flag) {
     printf("Please enter a category: \n");
     fgets(currentCategory, MAX_LEN, stdin);
     currentCategory[strcspn(currentCategory, "\n")] = 0;
 
     for (int i = 0; i < NUM_CATEGORIES; i++) {
       if (strncasecmp(categories[i], currentCategory, strlen(currentCategory)) == 0) {
         flag = false;
         break;
       }
     }
 
     if (flag) {
       printf("This is not a valid category, try again\n");
     }
   }
 }
 
 int get_difficulty_level() {
   int currentValue;
   char buffer[BUFFER_LEN];
   bool flag = true;
   while (flag) {
     printf("Please enter a difficulty level: \n");
     fgets(buffer, BUFFER_LEN, stdin);
 
     if (sscanf(buffer, "%d", &currentValue) == 1 && (currentValue == 100 || currentValue == 200 || currentValue == 300 || currentValue == 400)) {
       flag = false;
     } else {
       printf("This is not a recognized difficulty level, try again\n");
     }
   }
   return currentValue;
 }
 
 void ask_question(char *currentCategory, int currentValue, char *correctAnswer, player player_list[NUM_PLAYERS], char *currentPlayer) {
   display_question(currentCategory, currentValue);
   
   char playerAnswer[MAX_LEN];
   printf("Please enter your answer: \n");
   fgets(playerAnswer, MAX_LEN, stdin);
   playerAnswer[strcspn(playerAnswer, "\n")] = 0;
 
   // tokenize input
   char tokAnswer[BUFFER_LEN];
   tokenize(playerAnswer, tokAnswer);
 
   // check if the answer is correct
   if (strlen(tokAnswer) == 0) {
     printf("Invalid input format! Please answer in the form 'What is ...'\n");
   } else if (valid_answer(currentCategory, currentValue, tokAnswer)) {
     printf("That is correct! You get %d points\n", currentValue);
     update_score(player_list, NUM_PLAYERS, currentPlayer, currentValue);
   } else {
     printf("Sorry, the answer was actually: %s\n", correctAnswer);
   }
 }
 
 int find_winner(player player_list[NUM_PLAYERS]) {
   int winnerIndex = 0;
   for (int i = 1; i < NUM_PLAYERS; i++) {
     if (player_list[i].score > player_list[winnerIndex].score) {
       winnerIndex = i;
     }
   }
   return winnerIndex;
 }
 
 // Main Function
 int main(int argc, char *argv[]) {
   player player_list[NUM_PLAYERS];
   char buffer[BUFFER_LEN] = {0};
 
   // Display the game introduction and initialize the questions
   initialize_game();
 
   // Prompt for players' names
   get_player_names(player_list);
 
   // Initialize the score of each of the players in the array
   for (int i = 0; i < NUM_PLAYERS; i++) {
     player_list[i].score = 0;
   }
 
   // Perform an infinite loop getting command input from users until game ends
   while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
     printf("\033[H\033[J"); // ANSI escape sequence to clear screen.
     fflush(stdout); // force the output
     printf("\033[5;33mJEOPARDY!\033[0m\n");
     show_results(player_list, NUM_PLAYERS); // display current players, their names and scores
 
     display_categories();
     char currentPlayer[MAX_LEN]; // holds the name of the current player
 
     // Get next player
     get_next_player(player_list, currentPlayer);
     printf("Hello %s, ", currentPlayer);
 
     char currentCategory[MAX_LEN];
     int currentValue;
 
     // Get valid category
     get_category(currentCategory);
     printf("You have selected %s, ", currentCategory);
 
     // Get valid difficulty level
     currentValue = get_difficulty_level();
 
     // set the answered value for the question to true and save the answer to check later
     char *correctAnswer;
     for (int i = 0; i < 16; i++) {
       if (strcmp(currentCategory, questions[i].category) == 0 && currentValue == questions[i].value) {
         correctAnswer = questions[i].answer;
         questions[i].answered = true;
       }
     }
 
     // Ask the question and handle the answer
     ask_question(currentCategory, currentValue, correctAnswer, player_list, currentPlayer);
 
     // Check if there are unanswered questions left
     bool keepPlaying = false;
     for (int i = 0; i < 16; i++) {
       if (!questions[i].answered) {
         keepPlaying = true;
         break;
       }
     }
 
     if (!keepPlaying) break;
   }
 
   show_results(player_list, NUM_PLAYERS);
 
   // Determine the winner
   int winnerIndex = find_winner(player_list);
 
   // Display the winner
   printf("Congratulations, %s, you win with a score of %d\n", player_list[winnerIndex].name, player_list[winnerIndex].score);
   return EXIT_SUCCESS;
 }