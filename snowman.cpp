#include <string>
#include "snowman.hpp"
#include <cmath>
// #include <exception>

#include <stdexcept>
using namespace std;

const int MIN8 = 11111111;
const int MAX8 = 44444444;
const string alloftheparts [8][4] = {
                            {  "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"}, 
                            { ",", ".", "_", ""},
                            { ".", "o", "O", "-"},
                            { ".", "o", "O", "-"},
                            {"<", "\\" , "/", ""},
                            {">", "/", "\\", ""},
                            {" : ", "] [" ,  "> <", "   "},
                            {" : ", " ", "___", "   "},
                           };



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

        for (size_t i = 0; i < 8; i++)
        {
            sms += alloftheparts[i][sma[i]-1];
            sms += '\n';
        }
        
        return sms;

    }
};