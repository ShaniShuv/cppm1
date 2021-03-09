#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
#include <cmath>
#include <array>
using namespace std;
using namespace ariel;


const int MIN8 = 11111111;
const int MAX8 = 44444444;

// array<array<int, 6>, 4> = {
//                             {5, 11, 11, 11}, // hat's lengths sorted bt cases
//                             {1, 1, 1, 0}, // nose option
//                             {1, 1, 1, 1},  // although in all eye cases it's the same I rather this order
//                             {1, 1, 1, 0},
//                             {3, 3, 3, 3}, // toros option
//                             {3, 3, 3, 3} // base option
//                         };
// const string alloftheparts [8][5] = {
// std::array <std::array <string, 8>, 5> alloftheparts = {{ 
//                             {{"hat ", "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"}}, 
//                             {"nose ", ",", ".", "_", ""}},
//                             {{"left eye", ".", "o", "O", "-"}},
//                             {{"right eye", ".", "o", "O", "-"}},
//                             {{"left arm ", "<", "\\" , "/", ""}},
//                             {{"right arm ", ">", "/", "\\", ""}},
//                             {{"torso ", " : ", "] [" ,  "> <", "   "}},
//                             {{"base ", " : ", " ", "___", "   "}}
//                            }};

const std::array <std::array <string, 5>, 8> alloftheparts = {{
    {"hat ", "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"},
    {"nose ", ",", ".", "_", ""},
    {"left eye", ".", "o", "O", "-"},
    {"right eye", ".", "o", "O", "-"},
    {"left arm ", "<", "\\" , "/", ""},
    {"right arm ", ">", "/", "\\", ""},
    {"torso ", " : ", "] [" ,  "> <", "   "},
    {"base ", " : ", " ", "___", "   "}}};

int getrandomcase(){
    int smc = 0;
    for (size_t i = 0; i < 8; i++)
    {
        int temp = ((rand() % 10) % 4) + 1;
        smc *= 10;
        smc += temp;
    }
    return smc;
}


//3 tests
TEST_CASE("Don't initialize unnecessary"){
    int i = getrandomcase();
    for (size_t j = 0; j < 7; j++)
    {
        i /= 10;
        // for positive lower case
        CHECK_THROWS(snowman(i));
    }
    
    i += MAX8 + 1;

    // for positive larger case
    CHECK_THROWS(snowman(i));
    i = -1 * getrandomcase();

    //for negative case
    CHECK_THROWS(snowman(i));
    i *= -1;

    //for cases with non optional numbers
    for (size_t j = 0; j < 8; j++)
    {
        int k = pow(10, j);

        // int q = 
        int ruin = (((rand() % 10) % 3) + 4) * k;
        // at first we get a random number < 10 
        // then I chose to take a num mod 3 to be sure I ruin the good case of i 
        // then I added 4 so this number would be 4 or 5 or 6 
        // then no matter which number in {h, n , l, r, x, w, t, b} get it, we would get a wrong case

        int temp = i + ruin; 
        CHECK_THROWS(snowman(temp));
    }

}

TEST_CASE("Good initialization"){
    int smc = getrandomcase(); // snowman case
    string sms = snowman(smc); // snowman string

    int sma [8];
    int div = pow(10, 7);

    for (size_t i = 0; i < 8; i++)
    {
        int temp = smc / div;
        temp %= 10;
        sma[i] = temp;
        div /= 10;
    }

    int startcomp = 0; // this counter count the chars that passed so far

    for (size_t i = 0; i < 8; i++)
    {
        string comps = alloftheparts[i][sma[i]]; // this string represent the right string of the part we check 
        
        int thiscomplength = comps.length(); // show how long this part check sould be
        
        if(sms.length() < thiscomplength + startcomp){
            // if the string we got is too short then we sould fail
            // and we souldn't go to the loop because we would get out of bound
            CHECK(false);
            break;
        }

        for (size_t j = 0; j < thiscomplength; j++)
        {
            CHECK((comps[j]==sms[j + startcomp]));
           
        }
        startcomp += thiscomplength; // we add the length of the check we passed
        CHECK((sms[startcomp] == '\n'));
        startcomp += 1 ; // for the '\n'
    }
    CHECK (sms.length() == startcomp);
}