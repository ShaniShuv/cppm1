#include <string>
#include "snowman.hpp"
#include <cmath>
#include <array>

#include <stdexcept>
using namespace std;

const int MIN8 = 11111111;
const int MAX8 = 44444444;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int TEN = 10;

const std::array<string, 4> hats = { "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"};
const std::array<string, 4> upleftarms = {" ", "\\", "", ""};
const std::array<string, 4> lefteyes = { ".", "o", "O", "-"};
const std::array<string, 4> noses = { ",", ".", "_", " "};
const std::array<string, 4> righteyes = { ".", "o", "O", "-"};
const std::array<string, 4> uprightarms = {"", "/", "", ""};
const std::array<string, 4> lowleftarms = {"<", "" , "/", ""};
const std::array<string, 4> torsos =  {" : ", "] [" ,  "> <", "   "};
const std::array<string, 4> lowrightarms = {">", "", "\\", ""};
// const std::array<string, 4> bases = {" : ", " ", "___", "   "};
const std::array<string, 4> bases = {" : ", "\" \"", "___", "   "};


#include <iostream>
#include <exception>

// struct invalid_code: public std::exception
// {
// 	const char * what () const throw ()
//     {
//     	return "invalid code " ;//+ std::to_string();
//     }
// };
namespace ariel{
    string snowman(int smc){

        string sms = "Not optional";
        if (smc < MIN8 || MAX8 < smc){
            // throw invalid_code(); // invalid_code{"invalid code " + std::to_string(smc)}; //std::exception ex{"Not a valid option"};
            throw std::invalid_argument{"invalid code " + std::to_string(smc)}; 
        }
        
        sms = "";

        std::array<int, EIGHT> sma = {};
        int div = pow(TEN, SEVEN);

        for (size_t i = 0; i < EIGHT; i++)
        {
            int temp = smc / div;
            temp %= TEN;
            if (temp > 4){
                throw std::invalid_argument{"invalid code " + std::to_string(temp)};
            }
            sma.at(i) = temp;
            div /= TEN;
        }

        /* 
        sma:
        0 - hat
        1 - nose
        2 - left eye
        3 - right eye
        4 - left arm
        5 - right arm
        6 - torso
        7 - base
        */
        sms = hats.at(sma[0]-1) + "\n" + 
            upleftarms.at(sma.at(FOUR)-1) + '(' + lefteyes.at(sma[2] -1) + noses.at(sma[1]-1) + righteyes.at(sma[3]-1) + ')' + uprightarms.at(sma.at(FIVE)-1) + '\n'+
            lowleftarms.at(sma.at(FOUR)-1) +  '(' + torsos.at(sma.at(SIX)-1) + ')'+ lowrightarms.at(sma.at(FIVE) -1) + '\n' +
            '(' + bases.at(sma.at(SEVEN)-1) + ')';
        
        return sms;

    }
};