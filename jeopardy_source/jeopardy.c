/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2025, <Julian Olano Medina, Rivka Sagi, Rhea, Korede>
 * All rights reserved.
 *
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <strings.h>
 #include <stdbool.h>
 #include "questions.h"
 #include "players.h"
 #include "jeopardy.h"
 
 // Put macros or constants here using #define
 #define BUFFER_LEN 256
 #define NUM_PLAYERS 4
 
 // Put global environment variables here
 
 // Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
 void tokenize(char *input, char *tokens){
     const char *what = "What is";
     const char *who = "Who is";
 
     if(strncasecmp(input, what, strlen(what)) == 0 || strncasecmp(input, who, strlen(who)) == 0){
         //if the first part of the answer matches what is or who is
         // tokenizes the input by spaces
         tokens = strtok(input, " "); // Tokenize "what" or "who"
         tokens = strtok(NULL, " ");  // tokenize "is"
         tokens = strtok(NULL, " ");  // tokenizes the actual answer
     } else {
         tokens = "\0";
     }
 };
 
 // Displays the game results for each player, their name and final score, ranked from first to last place
 void show_results(player *players, int num_players){
     //checks for the max score by storing max score in a variable and swapping if another max is found using selection sort
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
 };
 
 int main(int argc, char *argv[]) {
     // An array of 4 players, may need to be a pointer if you want it set dynamically
     player player_list[NUM_PLAYERS];
 
     // Input buffer and and commands
     char buffer[BUFFER_LEN] = {0};
 
     // Display the game introduction and initialize the questions
     initialize_game();
 
     // Prompt for players' names
     for (int i = 0; i < NUM_PLAYERS; i++) {
         printf("Player %d, What is your name?\n", i);
         scanf("%255s", player_list[i].name);
     }
 
     // Initialize the score of each of the players in the array
     for (int i = 0; i < NUM_PLAYERS; i++) {
         player_list[i].score = 0;
     }
 
     // Perform an infinite loop getting command input from users until game ends
     while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
         printf("\033[5;33mJEOPARDY!\033[0m\n");
         show_results(player_list, NUM_PLAYERS); // display current players, their names and scores
 
         display_categories();
         char currentPlayer[MAX_LEN]; // holds the name of the current player
         bool flag = true;
 
         // while loop to get next player
         while (flag) {
             // ask for the name of the player
             printf("Enter the name of the player to go next: \n");
             scanf("%255s", currentPlayer);
 
             // check if the player entered is valid, if not keep looping
             if (player_exists(player_list, NUM_PLAYERS, currentPlayer)) {
                 flag = false;
             } else {
                 printf("This player does not exist, try again\n");
             }
         }
 
         printf("Hello %s, ", currentPlayer);
 
         char currentCategory[MAX_LEN];
         int currentValue;
         flag = true; // reset flag
 
         // while loop to get a valid category
         while (flag) {
             printf("Please enter a category: \n");
             scanf("%255s", currentCategory);
 
             // check if category entered is valid
             for (int i = 0; i < NUM_CATEGORIES; i++) {
                 if (strncasecmp(categories[i], currentCategory, strlen(currentCategory)) == 0) {
                     flag = false;
                 }
             }
 
             // if category entered is not valid
             if (flag) {
                 printf("This is not a valid category, try again\n");
             }
         }
 
         printf("You have selected %s, ", currentCategory);
 
         while (flag) {
             // ask for difficulty level
             printf("Please enter a difficulty level: \n");
             scanf("%d", &currentValue);
 
             // check if this is a valid value
             if (currentValue % 100 == 0 && currentValue <= 100 && currentValue >= 400) {
                 // if valid, then check if the question was answered already
                 if (already_answered(currentCategory, currentValue)) {
                     printf("This question was already answered, try again\n");
                 } else {
                     flag = false; // value for question is accepted, exit loop
                 }
             } else {
                 // if number entered is not a valid question value
                 printf("This is not a recognized difficulty level, try again\n");
             }
         }
 
         // set the answered value for the question to true and save the answer to check later
         char *correctAnswer;
         for (int i = 0; i < 16; i++) {
             if (strcmp(currentCategory, questions[i].category) == 0 && currentValue == questions[i].value) {
                 correctAnswer = questions[i].answer;
                 questions[i].answered = true;
             }
         }
 
         // call the display question function
         display_question(currentCategory, currentValue);
 
         char playerAnswer[MAX_LEN];
         // prompt user for answer to the question
         printf("Please enter your answer: \n");
         scanf("%255s", playerAnswer);
 
         // tokenize input
         char *tokAnswer;
         tokenize(playerAnswer, tokAnswer);
 
         // check if the answer is correct
         if (valid_answer(currentCategory, currentValue, tokAnswer)) {
             // update scores
             printf("That is correct! You get %d points\n", currentValue);
             update_score(player_list, NUM_PLAYERS, currentPlayer, currentValue);
         } else {
             printf("Sorry, the answer was actually: %s\n", correctAnswer);
         }
 
         bool keepPlaying = false;
         for (int i = 0; i < 16; i++) {
             if (questions[i].answered == false) {
                 keepPlaying = true;
             }
         }
         if (!keepPlaying) break;
     }
 
     show_results(player_list, NUM_PLAYERS);
     // check who the winner is
     int winnerIndex = 0; // Start with the first player as the winner
     for (int i = 1; i < NUM_PLAYERS; i++) {
         if (player_list[i].score > player_list[winnerIndex].score) {
             winnerIndex = i;
         }
     }
 
     // display who the winner is
     printf("Congratulations, %s, you win with a score of %d\n", player_list[winnerIndex].name, player_list[winnerIndex].score);
     return EXIT_SUCCESS;
 }
 