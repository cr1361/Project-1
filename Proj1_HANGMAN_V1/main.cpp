/* 
 * File:   main.cpp
 * Author: Christopher Ramirez-Alba
 * Created on July 16, 2017, 12:54 AM
 *Purpose: Project1 Hangman
 */
 
 //System Librariez
#include <iostream>     //Input/Output Library
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;    //Libraries using namespace standard

//User Libraries
 
 //Global Constant -> Physics/Math/Conversion
const int MAX_WRONG=6;

//Function Prototypes
int main(int argc, char** argv) {
    //Declare variables
    char guess;
    int wrong=0;
    
    //Initialize variables
    vector<string> words;
    words.push_back("PAPER");

    //Map inputs to outputs or process the data
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(),words.end());
    const string THE_WORD=words[0];
    string soFar(THE_WORD.size(),'*');
    string used="";
   
    //Process/Calculations Here
    cout<<"      Welcome"<<endl;
    cout<<"You have exactly "<<(MAX_WRONG-wrong)<<" guesses, good luck!"<<endl;
    
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
        ++wrong;
        cout<<"Sorry, "<<guess<<" isn't in the word."<<endl;
        cout<<"You have "<<(MAX_WRONG-wrong)<<" guesses left."<<endl;
    }
    }
        
    //Output the transformed data
    if (wrong == MAX_WRONG)
    {
        cout<<"Game over, you lost"<<endl;
    }
    else
    {
        cout<<"Congratulation! You won"<<endl;
    }

    //Exit stage right!
    return 0;
}