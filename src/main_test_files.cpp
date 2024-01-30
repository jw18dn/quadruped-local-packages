#include <iostream>
#include "gait_sequence.cpp"

int main(){
    // Test the Gait Sequence Function
    GaitSequence temp;
    temp.Print();
    temp.StandingGait();
    temp.Print();
    temp.TrottingGait();
    temp.Print();
    return 0;
}