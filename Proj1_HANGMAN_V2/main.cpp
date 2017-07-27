/* 
 * File:   main.cpp
 * Author: Christopher Ramirez-Alba
 * Created on July 16, 2017, 12:54 AM
 *Purpose: Project1 Hangman
 */
 
 //System Librariez
#include <iostream>  
#include <string>    
#include <vector>      
#include <algorithm>    
#include <ctime>    
using namespace std;    //Libraries using namespace standard

//User Libraries
 
 //Global Constant
const int MAX_WRONG=6; //Total tries available per game

//Function Prototypes
int main(int argc, char** argv) {
    //Declare variables
    char guess;  //Letters player chooses when game begins
    int wrong=0; //Amount of letters that where wrong
    
    //Random words that will be used for game
    vector<string> words;
    words.push_back("PAPER");    
    words.push_back("PENCIL");    
    words.push_back("SHOE");    
    words.push_back("COMPUTER");       


    //Map inputs to outputs or process the data
    srand(static_cast<unsigned int>(time(0))); 
    random_shuffle(words.begin(),words.end()); 
    const string THE_WORD=words[0];          
    string soFar(THE_WORD.size(),'*');         
    string used="";
    
    //Process where the Game begins
    cout<<"      Welcome to Hangman"<<endl;    
    cout<<"     --------------------"<<endl;
    cout<<"You have exactly "<<(MAX_WRONG-wrong)
            <<" guesses, good luck!"<<endl;    
    
    while ((wrong<MAX_WRONG)&&(soFar!=THE_WORD))
    {
        cout<<"You've used the following letters: "<<used<<endl;
        cout<<"So far, the word is "<<soFar<<endl;   
            
    cout<<"Enter your guess: "<<endl;  
    cin>>guess;
    guess=toupper(guess);
    
    while (used.find(guess)!=string::npos)
    {
        
        cout<<"So far you've already guessed "<<guess<<endl;
        cout<<"Enter a letter please: "<<endl;
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
    }
    else
    {
        //Congratulation message with Image of stick figure
        cout<<"Congratulation! You've are saved!"<<endl;
    }

    cout<<"YOUR WORD: "<<THE_WORD<<endl;//Output of word used for game

    //Exit stage right!
    return 0;
}