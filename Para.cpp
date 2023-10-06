#include "Para.h"
#include <string>
using namespace std;

Para::Para(char* para[])
{
    // POP_SIZE = 200;
    // ELITE = 1;
    // MUTATE_PROB = 0.1;
    POP_SIZE = stoi(para[1]);
    ELITE = stoi(para[2]);
    MUTATE_PROB = stod(para[3]);     
}

Para::~Para()
{ 
}