# OSTutorial4

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
