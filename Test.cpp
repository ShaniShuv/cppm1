#include "doctest.h"
#include "snowman.hpp"
#include <stdexcept>
#include <cmath>
using namespace std;
#ifndef MIN8
#define MIN8 11111111
#endif
#ifndef MAX8
#define MAX8 44444444
#endif

int lengthofall [6][4] = {
                            {5, 11, 11, 11}, // hat's lengths sorted bt cases
                            {1, 1, 1, 0}, 
                            {1, 1, 1, 1},  // although in all eye cases it's the same I rather this order 
                            {1, 1, 1, 0}, 
                            {3, 3, 3, 3},
                            {3, 3, 3, 3}
                          };
// {0, 0, 0 , 0};
// string hatcomp = "_===_";
// lengthofall0 = ((hatcomp.length()); 




//3
TEST_CASE("Don't initialize unnecessary"){
	int i = rand()*(MAX8-MIN8);
	CHECK_THROWS(snowmanCreation(i));
    i += MAX8;
    CHECK_THROWS(snowmanCreation(i));
    i *= -1;
    CHECK_THROWS(snowmanCreation(i));
}

TEST_CASE("Good hat initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string hatcomp = NULL; // a string to compare
    int div = pow(10, 7);
    int hat = smc / div;
    switch (hat)
    {
    case 1:
        hatcomp = "_===_";
        break;
    case 2:
        hatcomp = " ___ \n.....";
        break;
    case 3:
        hatcomp = "  _  \n /_\ ";
        break;
    case 4:
        hatcomp = " ___ \n(_*_)";
        break;
    default:
        CHECK(false);
    }
    int hatlength = hatcomp.length(); //lengthofall[1][hat];
    for (size_t i = 0; i < hatlength; i++)
    {
        CHECK((hatcomp[i]==sms[i]));
    }
    
}

TEST_CASE("Good nose initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = pow(10, 6);
    int nose = smc / div;
    div *= 10;
    int hat = smc / div;  
    nose %= 10;
    int sofarlength = lengthofall[0][hat]; //hatcomp.length(); 

    switch (nose)
    {
    case 1:
        CHECK((sms[sofarlength] == ','));
        break;
    case 2:
        CHECK((sms[sofarlength] == '.'));
        break;
    case 3:
        CHECK((sms[sofarlength] == '_'));
        break;
    case 4:
        break;
    default:
        CHECK(false);
    }
}

TEST_CASE("Good left eye initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = pow(10, 5);
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;

    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose]; //hatcomp.length(); 

    switch (lefteye)
    {
    case 1:
        CHECK((sms[sofarlength] == '.'));
        break;
    case 2:
        CHECK((sms[sofarlength] == 'o'));
        break;
    case 3:
        CHECK((sms[sofarlength] == 'O'));
        break;
    case 4:
        CHECK((sms[sofarlength] == '-'));
        break;
    default:
        CHECK(false);
    }
}

TEST_CASE("Good right eye initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = pow(10, 4);
    int righteye = smc / div;
    div *= 10;
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    righteye %= mul;
    mul *= 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose] + lengthofall[2][lefteye]; //hatcomp.length(); 

    switch (righteye)
    {
    case 1:
        CHECK((sms[sofarlength] == '.'));
        break;
    case 2:
        CHECK((sms[sofarlength] == 'o'));
        break;
    case 3:
        CHECK((sms[sofarlength] == 'O'));
        break;
    case 4:
        CHECK((sms[sofarlength] == '-'));
        break;
    default:
        CHECK(false);
    }
}

TEST_CASE("Good left arm initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = pow(10, 3);
    int leftarm = smc / div;
    div *= 10;
    int righteye = smc / div;
    div *= 10;
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    leftarm %= mul;
    mul *= 10;
    righteye %= mul;
    mul *= 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose] + lengthofall[2][lefteye] + lengthofall[2][righteye]; //hatcomp.length(); 

    switch (leftarm)
    {
    case 1:
        CHECK((sms[sofarlength] == '<'));
        break;
    case 2:
        CHECK((sms[sofarlength] == '\\'));
        break;
    case 3:
        CHECK((sms[sofarlength] == '\/'));
        break;
    case 4:
        break;
    default:
        CHECK(false);
    }
}

TEST_CASE("Good right arm initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = pow(10, 2);
    int rightarm = smc / div;
    div *= 10;
    int leftarm = smc / div;
    div *= 10;
    int righteye = smc / div;
    div *= 10;
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    rightarm %= mul;
    mul *= 10;
    leftarm %= mul;
    mul *= 10;
    righteye %= mul;
    mul *= 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose] + lengthofall[2][lefteye] + lengthofall[2][righteye] + lengthofall[3][leftarm]; //hatcomp.length(); 

    switch (rightarm)
    {
    case 1:
        CHECK((sms[sofarlength] == '>'));
        break;
    case 2:
        CHECK((sms[sofarlength] == '\/'));
        break;
    case 3:
        CHECK((sms[sofarlength] == '\\'));
        break;
    case 4:
        break;
    default:
        CHECK(false);
    }
}

TEST_CASE("Good torso initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int div = 10;
    int torso = smc / div;
    div *= 10;
    int rightarm = smc / div;
    div *= 10;
    int leftarm = smc / div;
    div *= 10;
    int righteye = smc / div;
    div *= 10;
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    torso %= mul;
    mul *= 10;
    rightarm %= mul;
    mul *= 10;
    leftarm %= mul;
    mul *= 10;
    righteye %= mul;
    mul *= 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose] + lengthofall[2][lefteye] + lengthofall[2][righteye] + lengthofall[3][leftarm] + lengthofall[3][rightarm]; //hatcomp.length(); 

    string torsocomp = NULL;

    switch (torso)
    {
    case 1:
        torsocomp = " : ";
        break;
    case 2:
        torsocomp = "] [";
        break;
    case 3:
        torsocomp = "> <";
        break;
    case 4:
        torsocomp = "   ";
        break;
    default:
        CHECK(false);
    }

    for (size_t i = 0; i < lengthofall[4][torso]; i++)
    {
        CHECK((sms[sofarlength+i] == torsocomp[i]));
    }
    
}

TEST_CASE("Good base initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    // string nosecomp = NULL; // a string to compare
    int div = 1;
    int base = smc / div;
    div *= 10;
    int torso = smc / div;
    div *= 10;
    int rightarm = smc / div;
    div *= 10;
    int leftarm = smc / div;
    div *= 10;
    int righteye = smc / div;
    div *= 10;
    int lefteye = smc / div;
    div *= 10;
    int nose = smc / div;
    div *= 10;
    int hat = smc / div; 

    int mul = 10;
    base %= mul;
    mul *= 10;
    torso %= mul;
    mul *= 10;
    rightarm %= mul;
    mul *= 10;
    leftarm %= mul;
    mul *= 10;
    righteye %= mul;
    mul *= 10;
    lefteye %= mul;
    mul *= 10;
    nose %= mul;
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose] + lengthofall[2][lefteye] + lengthofall[2][righteye] + lengthofall[3][leftarm] + lengthofall[3][rightarm] + lengthofall[5][torso]; //hatcomp.length(); 

    string basecomp = NULL;

    switch (base)
    {
    case 1:
        basecomp = " : ";
        break;
    case 2:
        basecomp = "] [";
        break;
    case 3:
        basecomp = "> <";
        break;
    case 4:
        basecomp = "   ";
        break;
    default:
        CHECK(false);
    }

    for (size_t i = 0; i < lengthofall[4][torso]; i++)
    {
        CHECK((sms[sofarlength+i] == basecomp[i]));
    }
    
}


// TEST_CASE("Good snowman code") {
//     CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
//     /* Add more checks here */
// }

// TEST_CASE("Bad snowman code") {
//     CHECK_THROWS(snowman(555));
//     /* Add more checks here */
// }



/*
TEST_CASE("Factorials of small numbers") {
    CHECK(snowmanCreation(1));
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
}


TEST_CASE("Factorials of large numbers") {
    CHECK(factorial(4) == 24);
    CHECK(factorial(6) == 720);
    CHECK(factorial(10) == 3628800);

    // auto f3 = factorial(3);
    // CHECK((f3==5 || f3==6)); // logic OR requires parentheses!
}


TEST_CASE("Factorials of negative numbers") { 
    CHECK_THROWS(factorial(-1));  // check that some exception is thrown
    CHECK_THROWS_AS(factorial(-2), std::out_of_range);  // check that a specific exception type is thrown
    CHECK_THROWS_AS(factorial(-2), std::exception);  // check that a specific exception type (or a descendant) is thrown
}

*/
/* add more test cases here */