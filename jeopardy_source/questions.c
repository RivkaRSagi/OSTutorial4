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
    strcpy(questions[0].category, "animated movies");
    strcpy(questions[0].question,"a movie about an ogre and a donkey who go on an adventure to save a swamp");
    strcpy(questions[0].answer, "Shrek");
    questions[0].value = 100; //lowest level question
    questions[0].answered = false;

    strcpy(questions[1].category, "animated movies");
    strcpy(questions[1].question,"a disney movie about a flying house, an old man, a boy, and a dog");
    strcpy(questions[1].answer, "Up");
    questions[1].value = 200; //second lowest level 
    questions[1].answered = false;

    strcpy(questions[2].category, "animated movies");
    strcpy(questions[2].question, "a pet chameleon who thinks he is a famous actor goes to the wild west and becomes the sheriff");
    strcpy(questions[2].answer, "Rango");
    questions[2].value = 300;
    questions[2].answered = false;

    strcpy(questions[3].category, "animated movies");
    strcpy(questions[3].question, "a movie about a society of animals that coexist in a city that does not discriminate between predator and prey");
    strcpy(questions[3].answer, "Zootopia");
    questions[3].value = 400; //highest difficulty question
    questions[3].answered = false;

    //second category: animals
    strcpy(questions[4].category, "animals");
    strcpy(questions[4].question, "it has very muscley arms and carries its children in a pouch on its stomach");
    strcpy(questions[4].answer, "Kangaroo");
    questions[4].value = 100; //lowest level question
    questions[4].answered = false;

    strcpy(questions[5].category, "animals");
    strcpy(questions[5].question, "it's nocturnal, can turn its head 360 degrees, and brings hogwarts students their acceptance letters");
    strcpy(questions[5].answer, "Owl");
    questions[5].value = 200;
    questions[5].answered = false;

    strcpy(questions[6].category, "animals");
    strcpy(questions[6].question, "it has 3 hearts and is said to be as intelligent as humans");
    strcpy(questions[6].answer, "Octopus");
    questions[6].value = 300;
    questions[6].answered = false;

    strcpy(questions[7].category, "animals");
    strcpy(questions[7].question, "it is very slow on land, but can be very fast in the water. It is protected by a hard shell on its back.");
    strcpy(questions[7].answer, "Turtle");
    questions[7].value = 400;
    questions[7].answered = false;

    //third category: vehicles
    strcpy(questions[8].category, "vehicles");
    strcpy(questions[8].question, "it has two wheels and is very loud, you need a special license to drive it");
    strcpy(questions[8].answer, "Motorcycle");
    questions[8].value = 100;
    questions[8].answered = false;

    strcpy(questions[9].category, "vehicles");
    strcpy(questions[9].question, "it is used to rush injured people to hospitals in an emergency");
    strcpy(questions[9].answer, "Ambulance");
    questions[9].value = 200;
    questions[9].answered=false;

    strcpy(questions[10].category, "vehicles");
    strcpy(questions[10].question, "it is used to fly people from one place to another, can be expensive around holiday season");
    strcpy(questions[10].answer, "Airplane");
    questions[10].value = 300;
    questions[10].answered = false;

    strcpy(questions[11].category, "vehicles");
    strcpy(questions[11].question, "used on farms to assist with agricultural tasks");
    strcpy(questions[11].answer, "Tractor");
    questions[11].value = 400;
    questions[11].answered = false;

    //fourth category: professions
    strcpy(questions[12].category, "professions");
    strcpy(questions[12].question, "they diagnose you and prescribe you medicine when you are sick");
    strcpy(questions[12].answer, "Doctor");
    questions[12].value = 100;
    questions[12].answered=false;

    strcpy(questions[13].category, "professions");
    strcpy(questions[13].question, "they prepare your food");
    strcpy(questions[13].answer, "Chef");
    questions[13].value = 200;
    questions[13].answered = false;

    strcpy(questions[14].category, "professions");
    strcpy(questions[14].question, "they design your buildings");
    strcpy(questions[14].answer, "Architect");
    questions[14].value = 300;
    questions[14].answered=false;

    strcpy(questions[15].category, "professions");
    strcpy(questions[15].question, "they fix your back problems");
    strcpy(questions[15].answer, "Chiropractor");
    questions[15].value = 400;
    questions[15].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array

    int[16] render;
    int row = 0;
    for (int i=0; i<16; i++){
	int row = i / 4; 
	int x = i % 4;
	if(x=0)
    	render[4*row] = i;
    	else if(x=1)
        render[4*row+1] = i;
        else if(x=2)
        render[4*row+2] = i;
        else if(x=3)
        render[4*row+3] = i;
    }
    // render the categories first
    printf("\033[35mCategories: %s, %s, %s, %s\n",questions[0].category,questions[4].category,questions[8].category,questions[12].category); 
    // lookup the question to compare the answer
    for(int i=0; i<16; i+=4){
       printf("\033[1;31m[\033[0;33m%d\033[1;31m]\033[0   ",question[i].value);
       printf("\033[1;31m[\033[0;33m%d\033[1;31m]\033[0   ",question[i+1].value);
       printf("\033[1;31m[\033[0;33m%d\033[1;31m]\033[0   ",question[i+2].value);
       printf("\033[1;31m[\033[0;33m%d\033[1;31m]\033[0\n",question[i+3].value);
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{//figure out how to fetch the question string
printf("\033[5;33m%s\033[0m", question_string);//displays question in flashing yellow text
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    bool answer;
    //lookup the question to compare the answer
    for(int i=0; i<16; i++){
        if (category == questions[i].category && value == questions[i].value){
            // use the strncasecmp to check if the answer is correct while disregarding case sensitivity
            answer = (strncasecmp(questions[i].answer, answer) == 0)? true: false;
        }
    }
    return answer;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int i=0; i<16; i++){
        if (category == questions[i].category && value == questions[i].value){
            //return the status of the question
            return questions[i].answered;
        }
    }
}
