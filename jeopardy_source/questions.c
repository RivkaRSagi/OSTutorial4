/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Julian Olano Medina, Rivka Sagi, Rhea Mathias, Korede>
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  // Added for bool type
#include "questions.h"

char categories[NUM_CATEGORIES][MAX_LEN] = {  // Definition
    "animated movies", 
    "animals", 
    "vehicles",
    "professions"
};

question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Initialize questions, 4 per category (total: 16)
    
    // First category: Animated Movies
    strcpy(questions[0].category, "animated movies");
    strcpy(questions[0].question, "A movie about an ogre and a donkey who go on an adventure to save a swamp");
    strcpy(questions[0].answer, "Shrek");
    questions[0].value = 100;
    questions[0].answered = false;

    strcpy(questions[1].category, "animated movies");
    strcpy(questions[1].question, "A Disney movie about a flying house, an old man, a boy, and a dog");
    strcpy(questions[1].answer, "Up");
    questions[1].value = 200;
    questions[1].answered = false;

    strcpy(questions[2].category, "animated movies");
    strcpy(questions[2].question, "A pet chameleon who thinks he is a famous actor goes to the wild west and becomes the sheriff");
    strcpy(questions[2].answer, "Rango");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "animated movies");
    strcpy(questions[3].question, "A movie about a society of animals that coexist in a city that does not discriminate between predator and prey");
    strcpy(questions[3].answer, "Zootopia");
    questions[3].value = 400;
    questions[3].answered = false;

    // Second category: Animals
    strcpy(questions[4].category, "animals");
    strcpy(questions[4].question, "It has very muscular arms and carries its children in a pouch on its stomach");
    strcpy(questions[4].answer, "Kangaroo");
    questions[4].value = 100;
    questions[4].answered = false;

    strcpy(questions[5].category, "animals");
    strcpy(questions[5].question, "It's nocturnal, can turn its head 360 degrees, and brings Hogwarts students their acceptance letters");
    strcpy(questions[5].answer, "Owl");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "animals");
    strcpy(questions[6].question, "It has 3 hearts and is said to be as intelligent as humans");
    strcpy(questions[6].answer, "Octopus");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "animals");
    strcpy(questions[7].question, "It is very slow on land, but can be very fast in the water. It is protected by a hard shell on its back.");
    strcpy(questions[7].answer, "Turtle");
    questions[7].value = 400;
    questions[7].answered = false;

    // Third category: Vehicles
    strcpy(questions[8].category, "vehicles");
    strcpy(questions[8].question, "It has two wheels and is very loud, you need a special license to drive it");
    strcpy(questions[8].answer, "Motorcycle");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "vehicles");
    strcpy(questions[9].question, "It is used to rush injured people to hospitals in an emergency");
    strcpy(questions[9].answer, "Ambulance");
    questions[9].value = 200;
    questions[9].answered = false;

    strcpy(questions[10].category, "vehicles");
    strcpy(questions[10].question, "It is used to fly people from one place to another, can be expensive around holiday season");
    strcpy(questions[10].answer, "Airplane");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "vehicles");
    strcpy(questions[11].question, "Used on farms to assist with agricultural tasks");
    strcpy(questions[11].answer, "Tractor");
    questions[11].value = 400;
    questions[11].answered = false;

    // Fourth category: Professions
    strcpy(questions[12].category, "professions");
    strcpy(questions[12].question, "They diagnose you and prescribe you medicine when you are sick");
    strcpy(questions[12].answer, "Doctor");
    questions[12].value = 100;
    questions[12].answered = false;

    strcpy(questions[13].category, "professions");
    strcpy(questions[13].question, "They prepare your food");
    strcpy(questions[13].answer, "Chef");
    questions[13].value = 200;
    questions[13].answered = false;

    strcpy(questions[14].category, "professions");
    strcpy(questions[14].question, "They design your buildings");
    strcpy(questions[14].answer, "Architect");
    questions[14].value = 300;
    questions[14].answered = false;

    strcpy(questions[15].category, "professions");
    strcpy(questions[15].question, "They fix your back problems");
    strcpy(questions[15].answer, "Chiropractor");
    questions[15].value = 400;
    questions[15].answered = false;
}

// Displays categories and available questions
void display_categories(void)
{
    printf("\033[35mCategories: %s, %s, %s, %s\n\033[0m",
        questions[0].category, questions[4].category, questions[8].category, questions[12].category);

    for (int i = 0; i < 16; i += 4) {
        for (int j = 0; j < 4; j++) {
            if (!questions[i + j].answered)
                printf("\033[1;31m[\033[0;33m%d\033[1;31m]\033[0m   ", questions[i + j].value);
            else
                printf("\033[1;31m[%s]\033[0m   ", "XXX");
        }
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < 16; i++) {
        if (strcmp(category, questions[i].category) == 0 && value == questions[i].value) {
            printf("\033[5;33m%s\033[0m\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the answer is correct
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < 16; i++) {
        if (strcmp(category, questions[i].category) == 0 && value == questions[i].value) {
            return strncasecmp(questions[i].answer, answer, strlen(questions[i].answer)) == 0;
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < 16; i++) {
        if (strcmp(category, questions[i].category) == 0 && value == questions[i].value) {
            return questions[i].answered;
        }
    }
    return false;
}
