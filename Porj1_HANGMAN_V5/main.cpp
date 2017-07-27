/* 
 * File:   main.cpp
 * Author: Christopher Ramirez-Alba
 * Created on July 16, 2017, 12:54 AM
 *Purpose: Project1 Hangman
 */
 
 //System Librariez
#include <iostream>     //Input/Output Library
#include <string>       //Character sequence
#include <vector>       //Array size
#include <algorithm>    //Collection of funcions
#include <ctime>        //Date and time in value
#include <cmath>        //Standard math functions
using namespace std;    //Libraries using namespace standard

//User Libraries
 
 //Global Constant
const int MAX_WRONG=6; //Total tries available per game

//Function Prototypes
int main(int argc, char** argv) {
    //Declare variables
    char guess;  //Letters player chooses when game begins
    int wrong=0; //Amount of letters that where wrong
    float prcent;
    
    //Random words that will be used for game
    vector<string> words;
    words.push_back("CHEESE");     //Choice for hidden letter being "CHEESE"
    words.push_back("APPLE");      //Choice for hidden letter being "APPLE" 
    words.push_back("COOKIE");     //Choice for hidden letter being "COOKIE" 
    words.push_back("FLAN");       //Choice for hidden letter being "FLAN" 
    words.push_back("PASTA");      //Choice for hidden letter being "PASTA" 
    words.push_back("PINEAPPLE");  //Choice for hidden letter being "PINEAPPLE"
    words.push_back("SANDWHICH");  //Choice for hidden letter being "SANDWHICH"
    words.push_back("PIZZA");      //Choice for hidden letter being "PIZZA"
    words.push_back("TACOS");      //Choice for hidden letter being "TACOS" 
    words.push_back("SALAD");      //Choice for hidden letter being "SALAD" 

    //Map inputs to outputs or process the data
    srand(static_cast<unsigned int>(time(0))); //Random function for secret word
    random_shuffle(words.begin(),words.end()); //Shuffle of words from vector
    const string THE_WORD=words[0];            //Characters the word contains
    string soFar(THE_WORD.size(),'-');         //Characters switched to underscore
    string used=" ";
    
    //Process where the Game begins
    cout<<"      Welcome to Hangman"<<endl;     //Introduction to Game
    cout<<"     --------------------"<<endl;
    cout<<"You have exactly "<<(MAX_WRONG-wrong)
            <<" guesses, good luck!"<<endl;     //Amount of guesses given
    cout<<"Hint: All words will be food."<<endl;//Hint for Game
    
    while ((wrong<MAX_WRONG)&&(soFar!=THE_WORD))
    {
        cout<<"You've used the following letters: "<<used<<endl;//Letters used
        cout<<"So far, the word is "<<soFar<<endl;   //Letters used in word
            
    cout<<"Enter your guess: "<<endl;   //Enter letter to figure out word
    cin>>guess;
    guess=toupper(guess);
    
    while (used.find(guess)!=string::npos)
    {
        
        cout<<"So far you've already guessed "<<guess<<endl;//Letters used
        cout<<"Enter a letter please: "<<endl;//Enter letter to figure out word
        cin>>guess;
        guess=toupper(guess);
    }
    used+=guess;
    if (THE_WORD.find(guess)!=string::npos)
    {
        //Message give when letter is correct
        cout<<"Yes "<<guess<<" is in the word"<<endl;
        for (unsigned int i=0; i<THE_WORD.length(); ++i)
        {
            if (THE_WORD[i]==guess)
            {
                soFar[i]=guess;
            }
        }
    }
    else
    {
        //Message given when letter is not in word
        ++wrong;
        cout<<"Sorry, "<<guess<<" isn't in the word."<<endl;
        cout<<"You have "<<(MAX_WRONG-wrong)<<" guesses left."<<endl;
    }
    }
        
    //Output and image of Game ending
    if (wrong == MAX_WRONG)
    {
        //Game over message with Image of stick figure
        cout<<"Game over, you've been hanged!"<<endl;
        cout<<"    | "<<endl;
        cout<<"    0 "<<endl;
        cout<<"  /"<<" |"<<" \\ "<<endl;
        cout<<" /"<<"  |"<<"  \\ "<<endl;
        cout<<"   /"<<" \\ "<<endl;
        cout<<"  |"<<"   | "<<endl;
    }
    else
    {
        //Congratulation message with Image of stick figure
        cout<<"Congratulation! You've are saved!"<<endl;
        cout<<"   \\  "<<"0 "<<" /"<<endl;
        cout<<"    \\"<<" | "<<"/"<<endl;
        cout<<" 0"<<"    |"<<endl;
        cout<<"\\"<<"|"<<"/"<<"  / "<<"\\"<<"    0"<<endl;
        cout<<"/ "<<"\\"<<" /"<<"   \\"<<"  \\"<<"|"<<"/"<<endl;
        cout<<"           / "<<"\\"<<endl;
    }

    cout<<"YOUR WORD: "<<THE_WORD<<endl;//Output of word used for game
    
    if (wrong == MAX_WRONG)
    {
        cout<<endl;
        cout<<"Not Finished"<<endl;
        cout<<"Round Two"<<endl;
    }

    //Exit stage right!
    return 0;
}