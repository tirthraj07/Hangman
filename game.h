#ifndef GAME_H
#define GAME_H

class game{
    private:
        std::string word ="",guessedWord = "",gameOver;
        char alphabets[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
        char cap_alphabets[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R','S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
        int no_words,retryPlayer1,error=0,tempInt,tempInt2;
        std::string tempString,wordDisplay="";
        char sym[41] = {'`','~','!','@','#','$','%','^','&','*','(',')','-','_','+','=','[',']','{','}','|',';',':','"',',','<','.','>','?','/','\'','1','2','3','4','5','6','7','8','9','0'};
        std::string used_letters ="";  
        char guessedletter;
        int winner;


    public:
        game();
        std::string Player1();
        std::string lowercase(std::string stringName, int length);
        int illegalWordcheck(std::string word, int length);
        std::string Player2();
        int gameFinished(int win);


};

#endif