#include <string>
#include "snowman.hpp"
using namespace std;

#define MIN8 = 11111111;
#define MAX8 = 44444444;


string snowmanCreation(int t){
    
    string p = "Not optional";
    switch (t)
    {
    case 33232124:
        p = "   _\n  /_\\n\(o_O)\n (] [)>\n (   )";
        break;
    
    case 11114411:
        p = "_===_\n (.,.)\n ( : )\n ( : )";
        break;
    } 
    return p;
    
}