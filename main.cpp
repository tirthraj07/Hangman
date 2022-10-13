#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include "game.h"
#include "HangmanGraphics.h"
using namespace std;

//Prototype Functions
string intro();
void start();
void rules();

int main() {
  string tempString,inputIntro;
  inputIntro = intro();
  if (inputIntro=="start"){
    start();
  }
  if (inputIntro=="rules"){
    rules();
    cout<<"Type start to start the game"<<endl;
    cin>>tempString;
    start();
  }
  getche();
  return 0;
}

//Functions

string intro() {
  string inputIntro;
  do {
    system ("CLS");
    cout << "Welcome to Hangman Game" << endl;
    cout << "This game was created by Tirthraj Mahajan" << endl;
    cout << "Please type \n'start' to start the game \n'rules' to know how to play \n'end' to End the Fame" << endl;
    cin >> inputIntro;
    if (inputIntro == "start" || inputIntro == "rules" || inputIntro == "end") {
      break;
    }
  } while (true);

  return inputIntro;
}

void start(){
  game NewGame;
}

void rules(){
  system ("CLS");
  cout<<"Rules & Instructions"<<endl;
  cout<<"How to Play: \n-->This is a 2-Player Game \n-->Player 1: Thinks of a Word or Pharse\n-->Player 2: is the Guesser and has to guess within the limited attempts"<<endl;
  cout<<"RULES:\n-->While Player 1 selects a word/phrase, Player 2 is prohibited to look\n-->Players may permit or forbid proper nouns, such as names, places, brands, or slang by deciding among themselves\n-->Player 2 has 7 attempts to guess the word/phrase properly\n-->Player 2 may give hints about language,references,etc"<<endl;
  cout<<"-->The player guessing the word may, at any time, attempt to guess the whole word.If the word is correct, the game is over and the guesser wins.\n-->Otherwise, the system will penalize the guesser by adding an element to the diagram.\n-->On the other hand, if the guesser makes enough incorrect guesses to allow the system to complete the diagram, the guesser loses.\n-->However, the guesser can also win by guessing all the letters that appear in the word, thereby completing the word, before the diagram is completed.\n-->Please Note that no symbols are permitted"<<endl;
}