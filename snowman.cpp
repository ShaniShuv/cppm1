#include <string>
#include "snowman.hpp"
#include <cmath>
#include <array>
// #include <exception>

#include <stdexcept>
using namespace std;

const int MIN8 = 11111111;
const int MAX8 = 44444444;
// const string alloftheparts [8][4] = {
const std::array<string, 4> hats = { "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"};
const std::array<string, 4> upleftarms = {"", "\\", "", ""};
const std::array<string, 4> lefteyes = { ".", "o", "O", "-"};
const std::array<string, 4> noses = { ",", ".", "_", ""};
const std::array<string, 4> righteyes = { ".", "o", "O", "-"};
const std::array<string, 4> uprightarms = {"", "/", "", ""};
const std::array<string, 4> lowleftarms = {"<", "" , "/", ""};
const std::array<string, 4> torsos =  {" : ", "] [" ,  "> <", "   "};
const std::array<string, 4> lowrightarms = {">", "", "\\", ""};
const std::array<string, 4> bases = {" : ", " ", "___", "   "};

// const std::array <std::array <string, 4>, 10> alloftheparts{{{ "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"},
//                             {"", "\\", "", ""};
// const std::array<string, 4> lefteyes = { ".", "o", "O", "-"};
// const std::array<string, 4> noses = { ",", ".", "_", ""};
// const std::array<string, 4> righteyes = { ".", "o", "O", "-"};
// const std::array<string, 4> uprightarms = {"", "/", "", ""};
// const std::array<string, 4> lowleftarms = {"<", "" , "/", ""};
// const std::array<string, 4> torsos =  {" : ", "] [" ,  "> <", "   "};
// const std::array<string, 4> lowrightarms = {">", "", "\\", ""};
// const std::array<string, 4> bases = {" : ", " ", "___", "   "};




namespace ariel{
    string snowman(int smc){

        string sms = "Not optional";
        if (smc < MIN8 || MAX8 < smc){
            throw std::invalid_argument{"invalid value"}; //std::exception ex{"Not a valid option"};
        }
        
        sms = "";

        int sma [8];
        int div = pow(10, 7);

        for (size_t i = 0; i < 8; i++)
        {
            int temp = smc / div;
            temp %= 10;
            if (temp > 4){
                throw std::invalid_argument{"invalid value" + std::to_string(temp)};
            }
            sma[i] = temp;
            div /= 10;
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
        sms = hats[sma[0]-1] + "\n" + 
            upleftarms[sma[4]-1] + '(' + lefteyes[sma[2] -1] + noses[sma[1]-1] + righteyes[sma[3]-1] + ')' + uprightarms[sma[5]-1] + '\n'+
            lowleftarms[sma[4]-1] +  '(' + torsos[sma[6]-1] + ')'+ lowrightarms[sma[5] -1] + '\n' +
            '(' + bases[sma[7]-1] + ')';
        
        return sms;

    }
};