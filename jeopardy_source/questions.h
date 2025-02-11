#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 4
#define NUM_QUESTIONS 16

// List of 4 categories as an array of strings
extern char categories[NUM_CATEGORIES][MAX_LEN];  // Remove static to make this accessible across translation units

// Questions struct for each question
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// An array of 12 questions (4 for each category), initialized in initialize_game
extern question questions[NUM_QUESTIONS];  // Extern declaration for questions

// Function declarations
extern void initialize_game(void);
extern void display_categories(void);
extern void display_question(char *category, int value);
extern bool valid_answer(char *category, int value, char *answer);
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
