/*
    -Chain of responsibility in design patterns
        -Types of design patterns
            -Singleton () 
                //creates only one
            -Factory () 
                //hides implementation to create similar objects with single interface 
                //good for making npcs
                //proceedural generation
        -Design pattern that will pass execution from one obj in a chain to the next until the request is handled (eg. vending machine)
            -Avoids attaching sender and receiver (decoupling)
            -Dependancy between objects is minimized
            -Not good for doing just one request
            -Pros:
                -extensible -> easy to add handlers to the chain
                -flexible -> I can put handlers in any order
                -decoupled -> dependancy minimized
            -Cons:
                -handling not guaranteed
                -easy to break chain
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

