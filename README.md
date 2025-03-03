# OSTutorial4

```mermaid
classDiagram
    class Jeopardy {
        - Player players[] //and array containing the play structs
        - char* input_buffer //buffer for processing the command-line input from users
        + void main() //process the input buffer, tokenizes, then calls show results, updates player state
        + void tokenize(string input, string tokens[]) //processes the answer from the user to confirm
        + void show_results()//displays the game results for each player, from first to last place
    }

    class Player {
        - char* name //string containing the player's name
        - int score //the player's score (money)
        + void update_score(int points) //updates the score for that player given their name
        + bool player_exists(string name) //returns true if the player name matches one of the existing players
    }

    class Question["question struct"] {
        - char* category //string containing the category, taken from a list
        - char* question //string containing question
        - char* answer
        - int value //the dollar value of the question
        - bool answered //tracks if question has been answerd
        + bool validate_answer(string userAnswer)
        + bool already_answered()
    }

    class Questions["Game"] {
        - char categories[][] //the list containing the valid question categories
        - Question questions[] //array of question structs
        + void initialize_game() //initializes the array of questions for the game
        + void display_categories() //displays each of the remaining categories and questions that have not been answered
        + void display_question(string category, int value)//displays the question for the cateogry and dollar value
        + bool valid_answer(string category, int value, string answer)//returns if answer is correct for the question at that category and dollar value
    }

    Jeopardy --> Player : manages
    Jeopardy --> Questions : uses
    Questions --> Question : contains
```

## Rendering Logic Flow
```mermaid
graph TD
refresh('JEOPARDY! in bolded, flashing yellow')-->show_results
show_results('Displays each of the players, in underlined white text')-->display_categories('Displays the game grid, bolded green boxes with yellow score value inside)
display_categories-->answer(flash white text)
answer-->refresh
```


A project meant to satisfy the following requirements:

1. Your program must have a command line prompt that is used for all interactions with the Jeopardy system.
2. The program must ask for the names of the four players who will be playing Jeopardy, each player must enter their name and have it recorded in the system and their initial earnings set as 0.
3. The program then starts the game of Jeopardy and prints out each of the question categories and displays the dollar values for each question.
4. The program must accept the name of the person selected to pick the category and question.
    1. You can select the person any way you choose (first person to raise their hand, random selection, etc.).
    2. The program must validate that the name of the person entered is correct and matches to one of the players.
5. Once the player’s name has been entered the program must prompt the player for the category and dollar amount question.
    1. The program must verify that the category and dollar amount question has not already been answered.
6. The program must then display the question for the player to then answer.
    1. The questions and answers can be defined for each category and for each dollar amount for each category.
    2. However, if you want to make the game more interesting for multiple playthroughs you can have a bank of question and randomly select each question for each category from this question bank.
7. After the question is displayed, the program must prompt the player for the answer, the player must enter the answer starting with one of the following: what is or who is.
    1. You will need to use string tokenization to parse the answer, use the resources above to help.
    2. To make the game easier to program you can have every question only required a one word answer.
8. After the player answers the question the program must display whether they got it correct or incorrect.
    1. If the player answered the question correctly the program must update their score.
    2. If they answered incorrectly the program will display the answer and no user will receive any points.
    3. The question must then be marked as answered so it cannot be used again.
9. After the question has been completed, the program must print the remaining categories and question dollar amounts, then repeat requirements 4 to 9, until all of the questions have been completed.
10. Once the players have completed all of the questions the game must then print each of the players from the first place to last place and print their total earnings.
    1. The player with the highest earnings is the winner.
11. Bonus marks will be awarded to the group with the best project, feel free to add any enhancements to your project to improve it (e.g. randomly chosen categories and questions, double jeopardy, coloured terminal output, etc.) The class will use the group’ project to play Jeopardy at the start of the next tutorial. Please, describe what additional contributions you have made for bonus mark!
