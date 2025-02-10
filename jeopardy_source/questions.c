/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Julian Olano Medina, Rivka Sagi, Rhea, Korede>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    //first allocate memory for the questions array, 
    //in our project we are using 4 categories, so there are 16 questions total
    question questions[16];

    //initialize questions, 4 per category:

    //first category: movies
    strcpy(questions[1].category, "animated movies");
    strcpy(questions[1].question,"a movie about an ogre and a donkey who go on an adventure to save a swamp");
    strcpy(questions[1].answer, "what is Shrek");
    questions[1].value = 100; //lowest level question
    questions[1].answered = false;

    strcpy(questions[2].category, "animated movies");
    strcpy(questions[2].question,"a disney movie about a flying house, an old man, a boy, and a dog");
    strcpy(questions[2].answer, "what is up");
    questions[2].value = 200; //second lowest level 
    questions[2].answered = false;

    strcpy(questions[3].category, "animated movies");
    strcpy(questions[3].question, "a pet chameleon who thinks he is a famous actor goes to the wild west and becomes the sheriff");
    strcpy(questions[3].answer, "who is Rango");
    questions[3].value=300;
    questions[3].answered = false;

    strcpy(questions[4].category, "animated movies");
    strcpy(questions[4].question, "a movie about a society of animals that coexist in a city that does not discriminate between predator and prey");
    strcpy(questions[4].answer, "what is zootopia");
    questions[4].value=400; //highest difficulty question
    questions[4].answered=false;

    //second category: animals
    strcpy(questions[5].category, "animals");
    strcpy(questions[5].question, "it has very muscley arms and carries its children in a pouch on its stomach");
    strcpy(questions[5].answer, "what is kangaroo");
    questions[5].value = 100; //lowest level question
    questions[5].answered = false;

    strcpy(questions[6].category, "animals");
    strcpy(questions[6].question, "it's nocturnal, can turn its head 360 degrees, and brings hogwarts students their acceptance letters");
    strcpy(questions[6].answer, "what is owl");
    questions[6].value = 200;
    questions[6].answered=false;

    strcpy(questions[7].category, "animals");
    strcpy(questions[7].question, "it has 3 hearts and is said to be as intelligent as humans");
    strcpy(questions[7].answer, "what is octopus");
    questions[7].value = 300;
    questions[7].answered=false;

    strcpy(questions[8].category, "animals");
    strcpy(questions[8].question, "it is very slow on land, but can be very fast in the water. It is protected by a hard shell on its back.");
    strcpy(questions[8].answer, "what is turtle");
    questions[8].value = 400;
    questions[8].answered=false;

    //third category: vehicles
    strcpy(questions[9].category, "vehicles");
    strcpy(questions[9].question, "it has two wheels and is very loud, you need a special license to drive it");
    strcpy(questions[9].answer, "what is motorcycle");
    questions[9].value = 100;
    questions[9].answered=false;

    strcpy(questions[10].category, "vehicles");
    strcpy(questions[10].question, "it is used to rush injured people to hospitals in an emergency");
    strcpy(questions[10].answer, "what is ambulance");
    questions[10].value = 200;
    questions[10].answered=false;

    strcpy(questions[11].category, "vehicles");
    strcpy(questions[11].question, "it is used to fly people from one place to another, can be expensive around holiday season");
    strcpy(questions[11].answer, "what is airplane");
    questions[11].value = 300;
    questions[11].answered=false;

    strcpy(questions[12].category, "vehicles");
    strcpy(questions[12].question, "used on farms to assist with agricultural tasks");
    strcpy(questions[12].answer, "what is tractor");
    questions[12].value = 400;
    questions[12].answered=false;

    //fourth category: professions
    strcpy(questions[13].category, "professions");
    strcpy(questions[13].question, "they diagnose you and prescribe you medicine when you are sick");
    strcpy(questions[13].answer, "what is doctor");
    questions[13].value = 100;
    questions[13].answered=false;

    strcpy(questions[14].category, "professions");
    strcpy(questions[14].question, "they prepare your food");
    strcpy(questions[14].answer, "what is chef");
    questions[14].value = 200;
    questions[14].answered=false;

    strcpy(questions[15].category, "professions");
    strcpy(questions[15].question, "they design your buildings");
    strcpy(questions[15].answer, "what is architect");
    questions[15].value = 300;
    questions[15].answered=false;

    strcpy(questions[16].category, "professions");
    strcpy(questions[16].question, "they fix your back problems");
    strcpy(questions[16].answer, "what is chiropractor");
    questions[16].value = 400;
    questions[16].answered=false;


    // initialize each question struct and assign it to the questions array
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{//figure out how to fetch the question string
printf("\033[5;33m%s\033[0m", question_string);//displays question in flashing yellow text
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
