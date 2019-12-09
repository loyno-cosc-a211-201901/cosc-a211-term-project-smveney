//Program Name: Hangman
//Purpose: Allows the player to play a game of Hangman
//Author: Sydney Veney
//Date Last Modified: 12/8/2019

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    char start {};
    //start screen
    cout << "Welcome to Hangman!\n";
    cout << "_____________   " << endl;
    cout << "|      }        " << endl;
    cout << "|      O        " << endl;
    cout << "|      |        " << endl;
    cout << "|    / | \\     " << endl;
    cout << "|   /  |  \\    " << endl;
    cout << "|     / \\      " << endl;
    cout << "|    /   \\     " << endl;
    cout << "|               " << endl;
    cout << "|____________   " << endl;
    cout << "Press any key and then enter to start\n";
    cin >> start;

    //start of game
    //declare variables
    int numOfGuesses = 6; //number of guesses the player gets
    char playerGuess; //letter guessed by the player
    bool correctGuess = false;
    char previousGuesses[7]; //array of guesses
    previousGuesses[0] = '\0';
    for (int s = 1; s < 6; s++)
    {
        previousGuesses[s] = '-'; 
    }
    previousGuesses[6] = '\0';
    string word; //word the player has to guess
    string wordList[99]; //array of the random 90 words
    
    //get random word
    srand(time(NULL)); //get random word from the array
    ifstream randomWord;
    randomWord.open("/Users/sydneyveney/Documents/GitHub/cosc-a211-term-project-smveney/build/RandomWords.txt"); //reads in random words file

    for (int i = 0; i < 99; i++)
    {
        randomWord >> wordList[i]; //filling array with the random words
    }
    int randomNum = rand() % 100; //returns random number between 0 and 99
    word = wordList[randomNum];
    randomWord.close();

    //make word unkown to player
    string unknownWord (word.length(), '_'); //replaces each letter of the word with "_" and stores it in unkownWord

    while (numOfGuesses >= 0)
    {
        //reset bool
        correctGuess = false;

        //display information related to the word for the player
        cout << "\nThe word you have to guess is: \n";
        cout << unknownWord << endl;
        cout << "There are: " << unknownWord.length() << " letters in the word\n";
        cout << "You have " << numOfGuesses << " guesses left\n";
        if (previousGuesses[0] == '\0')
        {
            cout << endl;
        }
        else
        {
            cout << "You have guessed: " << previousGuesses << endl;
        }
        //get player guess
        cout << "Guess a letter: " << endl;
        cin >> playerGuess; 

        //check if playerGuess in a correct letter in unkownWord
        for (int j = 0; j < unknownWord.length(); j++) //do the following for the length of the unkownWord
        {
            if (word[j] == playerGuess) //check if the word has the guessed letter in it
            {
                unknownWord[j] = playerGuess;
                correctGuess = true;
            }
        }
        if (word == unknownWord)
        {
            cout << "Congratulations! You guessed the word: " << unknownWord << ", correct!\n";
            break;
        }
        if (correctGuess == false)
        {
            numOfGuesses--;
            cout << "Sorry, " << playerGuess << " is not a letter in the word\n";
        }
        else
        {
            cout << "Congratualtions! " << playerGuess << " is one of the letters\n";
        }

        switch (numOfGuesses)
        {
            //6 guesses left
            case 6:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;  
                cout << "\n\n\n\n";
                break;
            }
            //5 guesses left
            case 5:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl; 
                cout << "\n\n\n\n";
                if (correctGuess == false)
                {
                    previousGuesses[0] = playerGuess;
                } 
                break;
            }
            //4 guesses left
            case 4:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|      |        " << endl;
                cout << "|      |        " << endl;
                cout << "|      |        " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;
                cout << "\n\n\n\n";
                if (correctGuess == false)
                {
                    previousGuesses[1] = playerGuess;
                } 
                break;
            }
            //3 guesses left
            case 3:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|      |        " << endl;
                cout << "|    / |        " << endl;
                cout << "|   /  |        " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;
                cout << "\n\n\n\n";
                if (correctGuess == false)
                {
                    previousGuesses[2] = playerGuess;
                } 
                break;
            }
            //2 guesses left
            case 2:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|      |        " << endl;
                cout << "|    / | \\     " << endl;
                cout << "|   /  |  \\    " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;
                cout << "\n\n\n\n";
                if (correctGuess == false)
                {
                    previousGuesses[3] = playerGuess;
                } 
                break;
            }
            //1 guess left
            case 1:
            {
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|      |        " << endl;
                cout << "|    / | \\     " << endl;
                cout << "|   /  |  \\    " << endl;
                cout << "|     /         " << endl;
                cout << "|    /          " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;
                cout << "\n\n\n\n";
                if (correctGuess == false)
                {
                    previousGuesses[4] = playerGuess;
                } 
                break;
            }
            //game over
            case 0:
            {
                cout << "GAME OVER!\n"; 
                cout << "_____________   " << endl;
                cout << "|      }        " << endl;
                cout << "|      O        " << endl;
                cout << "|      |        " << endl;
                cout << "|    / | \\      " << endl;
                cout << "|   /  |  \\     " << endl;
                cout << "|     / \\       " << endl;
                cout << "|    /   \\      " << endl;
                cout << "|               " << endl;
                cout << "|____________   " << endl;
                cout << "The word was: " << word << endl;
                cout << "\n\n\n\n";
                numOfGuesses--; 
                break;
            }
            default: 
            cout << "Error!\n";
        }
    }
    return 0;
}