/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2025, <Julian Olano Medina, Rivka Sagi, Rhea, Korebe>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens){
    
    // tokenizes the input by spaces
    *tokens = strtok(input, " "); //Tokenizes "what" or "who"
    *tokens = strtok(NULL, " "); // tokenizes "is"
    *tokens = strtok(NULL, " "); // tokenizes the actual answer
    
    // const char *what = "What is";
    // const char *who = "Who is";

    // if (strncasecmp(input, what, strlen(what)) == 0) {
    //     input += strlen(what);
    // }
    // else if (strncasecmp(input, who, strlen(who)) == 0) {
    //     input += strlen(who);
    // }

    // *tokens = input;
};

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players){
    //checks for the max score by storing max score in a variable and swapping if another max is found using selection sort
    for (int i=0; i <num_players -1; i++){
        int max = i; //stores current player as max
        for (int j= i+1; j < num_players; j++){
            if (players[j].score > players[max].score){
                max = j;//stores the player after i as max if it has a greater score
            }
        }
        // swaps player into "hold"
        if (max != i){
            players hold= player[i];
            players[i] = player[max];
            players[max] = hold;
            
        }
    }

    //displays player result
    printf("Player scoreboard: \n");
    for (int i=0; i< num_players; i++){
        printf("%s: %d \n", players[i].name, players[i].score);
    }
};


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    players player_list[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i=0; i < NUM_PLAYERS; i++){
    printf("Player %d,What is your name?\n", i);
    scanf("%s", player_list[i].name);
    }

    // initialize each of the players in the array
    for(int i=0; i < NUM_PLAYERS; i++){
        player_list[i].score = 0;
    }

    //questions game

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
	printf("/033[5;33mJEOPARDY!/033[0m");
	show_results();
        // Call functions from the questions and players source files
	display_categories();
	printf("Enter Player to Select Category:/n");
	char[] name = scanf(%s)
	while(!player_exists(player_list, NUM_PLAYERS, name)){
	printf("Incorrect Name.\nEnter Player to Select Category:/n");
	name = scanf(%s);
	}
	printf("Select Category");
	// To do: extract selection from user.
	printf("\033[5mAnswer:");
	scanf("%s", buffer);
	buffer = tokenize(buffer);
	while(!valid_input){
	printf("Wrong Answer!\n\033[5mNew Answer:")
	fgets(buffer, sizeof(buffer), stdin);
	buffer = tokenize(buffer)
	}
	

        // Execute the game until all questions are answered

        // Display the final results and exit
       show_results();
    }
    return EXIT_SUCCESS;
}
