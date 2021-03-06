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

int lengthofall [8][4] = {{5, 11, 11, 11}, {1, 1, 1, 0}, }
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
    int hat = smc / 10000000;
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
     int hat = smc / 10000000;
    // string hatcomp = NULL; // a string to compare
    int nose = smc / 1000000;
    nose %= 10;
    // switch (hat)
    // {
    // case 1:
    //     hatcomp = "_===_";
    //     break;
    // case 2:
    //     hatcomp = " ___ \n.....";
    //     break;
    // case 3:
    //     hatcomp = "  _  \n /_\ ";
    //     break;
    // case 4:
    //     hatcomp = " ___ \n(_*_)";
    //     break;
    // default:
    //     CHECK(false);
    // }
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

TEST_CASE("Good nose initialization"){
    int smc = rand()*(MAX8-MIN8) + MIN8; // snowman case
    string sms = snowmanCreation(smc); // snowman string
    string nosecomp = NULL; // a string to compare
    int hat = smc / 10000000;
    // string hatcomp = NULL; // a string to compare
    int nose = smc / 1000000;
    nose %= 10;
    int nose = smc / 1000000;
    nose %= 10;
    // switch (hat)
    // {
    // case 1:
    //     hatcomp = "_===_";
    //     break;
    // case 2:
    //     hatcomp = " ___ \n.....";
    //     break;
    // case 3:
    //     hatcomp = "  _  \n /_\ ";
    //     break;
    // case 4:
    //     hatcomp = " ___ \n(_*_)";
    //     break;
    // default:
    //     CHECK(false);
    // }
    int sofarlength = lengthofall[0][hat] + lengthofall[1][nose]; //hatcomp.length(); 

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


TEST_CASE("Good snowman code") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    /* Add more checks here */
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));
    /* Add more checks here */
}



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