#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
#include <cmath>
#include <array>
using namespace std;
using namespace ariel;


const int MIN8 = 11111111;
const int MAX8 = 44444444;

const std::array<string, 4> hats = { "_===_", " ___ \n.....", "  _  \n /_\\ ",  " ___ \n(_*_)"};
const std::array<string, 4> upleftarms = {"", "\\", "", ""};
std::array<char, 4> lefteyes = { '.', 'o', 'O', '-'};
const std::array<string, 4> noses = {",", ".", "_", ""};
const std::array<string, 4> righteyes = { ".", "o", "O", "-"};
const std::array<string, 4> uprightarms = {"", "/", "", ""};
const std::array<string, 4> lowleftarms = {"<", "" , "/", ""};
const std::array<string, 4> torsos =  {"( : )", "(] [)" ,  "(> <)", "(   )"};
const std::array<string, 4> lowrightarms = {">", "", "\\", ""};
const std::array<string, 4> bases = {"( : )", "(\" \")", "(___)", "(   )"};

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
    int smc = getrandomcase(); // random snowman case
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
    
    int sofarcur = 0;

 /*   
    int counter = 0;
    if(sma[0] != 1){
        counter --;
    }
    // for space before the hat
    while (sms[sofarcur] == ' '){
        counter++;
    }
    sofarcur +=counter;
*/

    string currcomps = hats[sma[0] -1];
    int sofarlength = currcomps.length() + sofarcur;
    if (sofarlength > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    // checks hat
    for (size_t i = 0; i < currcomps.length(); i++)
    {
        CHECK (sms[sofarcur + i]== currcomps[i]);
    }
     
    sofarcur += currcomps.length() ;

/*
    // for space after the hat
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == '\n');

    sofarcur ++; // for the '\n'

/*
    // for space before up left arm
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    // checks upper left arm
    if(upleftarms[sma[4]-1].length() > 0){
        CHECK(sms[sofarcur] == upleftarms[sma[4]-1][0]);
        sofarcur ++; // for upper left hand if there is
    }

/*
    // for space between up left arm and '('
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == '(');

    sofarcur ++; // for the '('

/*
    // for space between '(' and left eye
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == lefteyes[sma[2] -1]);
    
    sofarcur ++; // for the left eye

/*
    // for space between left eye and nose
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == noses[sma[1] -1][0]);
    
    sofarcur ++; // for the nose
/*
    // for space between nose and right eye
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == righteyes[sma[3] -1][0]);
    
    sofarcur ++; // for the right eye

/*
    // for space between right eye and ')'
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == ')');

    sofarcur ++; // for the ')'

/*
    // for space between ')' and up right arm
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }
    
    if(uprightarms[sma[5] -1].length() > 0){
        CHECK(sms[sofarcur] == uprightarms[sma[5] -1][0]);
        sofarcur ++; // for the upper right hand if there is
    }

/*
    // for space after the upper right hand
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == '\n');

    sofarcur ++; // for the '\n'

/*
    // for space before the lower left hand
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/
    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    if(sma[4] != 4){
        CHECK(sms[sofarcur] == lowleftarms[sma[4] -1][0]);
        sofarcur++; // for lower left hand
    }
/*
    // for space between lower left hand and torso
    counter = 0;
    while (sms[sofarcur] == ' '){
        counter ++;
    }
    sofarcur += counter;
*/

    currcomps = torsos[sma[6] -1];

    sofarlength = sofarcur + currcomps.length();

    if (sofarlength > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    for (size_t i = 0; i < currcomps.length(); i++)
    {
        CHECK (sms[sofarcur + i]== currcomps[i]);
    }

    sofarcur += currcomps.length();

/*
    // for space between torso and right lower hand
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    if (lowrightarms[sma[5] -1].length() > 0){
        CHECK(sms[sofarcur] == lowrightarms[sma[5] -1][0]);
        sofarcur++; // for lower right hand
    }
/*
    // for space after lower right hand
    while (sms[sofarcur] == ' '){
        sofarcur++;
    }
*/

    if (sofarcur > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    CHECK(sms[sofarcur] == '\n');

    sofarcur ++; // for the '\n'
/*
    counter = 0;

    // for space before base
    while (sms[sofarcur] == ' '){
        counter++;
    }
    sofarcur +=counter;
*/   

    currcomps = bases[sma[7] -1];
    sofarlength = sofarcur + currcomps.length();

    if (sofarlength > sms.length()){
        throw std::invalid_argument{"test failed"};
    }

    for (size_t i = 0; i < currcomps.length(); i++)
    {
        CHECK (sms[sofarcur + i]== currcomps[i]);
    }

    sofarcur += currcomps.length();
/*
    // from now we'll check that if there are more chars they will bt '\n' or ' ' 
    while(sofarcur < sms.length()){
        bool b = (sms[sofarcur] == '\n') || (sms[sofarcur] == ' ');
        CHECK(b);
        sofarcur++;
    }
*/
   
}