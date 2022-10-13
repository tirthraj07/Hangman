#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "game.h"
#include "HangmanGraphics.h"
using namespace std;

game::game(){
    Player1();
    Player2();

}
string game::Player1(){
    do{
        system("CLS");
        cout << "Player 1: \nPlease Enter the no of words in desired phrase" << endl;
        cin >> no_words;

        for (int i = 1; i <= no_words; i++) {
            cout << "Word " << i << ": ";
            cin >> tempString;
            tempString = lowercase(tempString,tempString.length());
            word = word + tempString;
            if (i == 1) {
                wordDisplay = wordDisplay + tempString;
            } else {
                wordDisplay = wordDisplay + ' ' + tempString;
            }
        }
        if(illegalWordcheck(word,word.length())==1){
            cout<<"You have used an symbol, which is an illegal move, Please 'restart' to select the phrase again"<<endl;
            cin>>tempString;
            retryPlayer1 = 1;
        }
        if(illegalWordcheck(word,word.length())==0){
            retryPlayer1 = 0;
        }
    }while(retryPlayer1==1);   

}


string game::lowercase(string stringName, int length){
    for(int i = 0; i<length;i++){
        for(int j=0; j<=27;j++){
            if(stringName[i]==cap_alphabets[j]){
                stringName[i]=alphabets[j];
            }
        }

    }
    return stringName;

}

int game::illegalWordcheck(std::string word, int length){
    for(int i=0;i<length;i++){
        for(int j=0;j<=(sizeof(sym)/sizeof(char));j++){
            if(word[i]==sym[j]){
                return 1;
            }
        }

    }
    return 0;

}


int game::gameFinished(int win){
    cout<<"\n\n\n\n----------Game Over----------"<<endl;
    cout<<"Player "<<win<<" Wins!"<<endl;
    if(win==1){
        cout<<"The phrase/word was :"<<wordDisplay<<endl;
    }
    if(win==2){
        cout<<"The word was guessed correctly!"<<endl;
    }
    cout<<"\n----------THE END----------"<<endl;
    //system("pause");
    exit;

}

string game::Player2(){
    system("CLS");
    cout<<"Welcome Player 2"<<endl;
    cout<<"Your Objective now is to guess the pharse/word correctly within 5 tries"<<endl;
    hangmangraphics hangman;
    hangman.error0();
    cout<<endl<<endl;
    

    
    cout<<"Player 1's word/pharse : ";
    for(int i = 0; i<wordDisplay.length();i++){
        if(wordDisplay[i]==' '){
            guessedWord = guessedWord + " ";
        }else{
            guessedWord = guessedWord + "_";
        }
    }
    while(error<5 && wordDisplay!=guessedWord){    
        cout<<guessedWord<<endl;
        cout<<"Used Letters: ";
        for(int i = 0; i<=used_letters.length();i++){
            cout<<used_letters[i];
        }

        cout<<endl;

        tempInt = 0;
        cout<<"Guess a letter ";
        cin>>guessedletter;
        if((used_letters.length())>=1){
            for(int i = 0; i<=(used_letters.length());i++){
                if(used_letters[i]==guessedletter){
                    tempInt = 1;
                }      
            }
        }
        
        
        if(tempInt==1){
            cout<<"\nYou have already used "<<guessedletter<<endl;
        }
        if(tempInt==0){
            used_letters = used_letters + guessedletter;
            tempInt2 = 0;
            for(int i=0; i<=(wordDisplay.length());i++){
                if(wordDisplay[i]==guessedletter){
                    guessedWord[i]=guessedletter;
                    tempInt2++;
                }

            }
            if(tempInt2>0){
                cout<<"\n\nCongrats! '"<<guessedletter<<"' was in phrase!"<<endl;
            }
            if (tempInt2==0){
                system("CLS");
                cout<<"Oops! The letter '"<<guessedletter<<"' was not in the pharse"<<endl;
                error++;
                switch (error)
                {
                case 1:
                    cout<<"Incorrect! The Letter "<<guessedletter<<" is not in the phrase Try again"<<endl;
                    cout<<"Remaining lives "<<(5-error)<<endl;
                    hangman.error1();
                    break;
                case 2:
                    cout<<"Incorrect! The Letter "<<guessedletter<<" is not in the phrase Try again"<<endl;
                    cout<<"Remaining lives "<<(5-error)<<endl;
                    hangman.error2();
                    break;
                case 3:
                    cout<<"Incorrect! The Letter "<<guessedletter<<" is not in the phrase Try again"<<endl;
                    cout<<"Remaining lives "<<(5-error)<<endl;
                    hangman.error3();
                    break;
                case 4:
                    cout<<"Incorrect! The Letter "<<guessedletter<<" is not in the phrase Try again"<<endl;
                    cout<<"Remaining lives "<<(5-error)<<endl;
                    hangman.error4();
                    break;

                }
            
            

            }
        }
    }
    if(wordDisplay==guessedWord){
        winner = 2;
        game::gameFinished(winner);  
    }
    if(error==5){
        cout<<"Incorrect! The Letter "<<guessedletter<<" is not in the phrase Try again"<<endl;
        cout<<"Remaining lives "<<(5-error)<<endl;
        hangman.error5();
        winner = 1;
        game::gameFinished(winner);
    }


}