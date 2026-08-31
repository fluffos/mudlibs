// jedipower.c (power object of the Jedi guild) 
// 121294: Beast: beginning 

#include "/players/mangla/guild/bedefines.h"

#define MAX_SPBOOST 80 // maximal (base) amount of SP 

int dark_power;        // cumulative power of the Dark side of the Force 
int light_power;       // cumulative power of the Light side of the Force
int ncloaks;           // number of cloaks worn

void reset(int arg) {
    if (arg) 
        return;
    dark_power = light_power = ncloaks = 0;
    return;
}

// compute your power and add it to global jedi power
int compute_power(int myalign, int mylevel) {
    int mypow;
    if (ncloaks <= 0)
        light_power = dark_power = ncloaks = 0;
    mypow = (myalign + ((myalign>=0) ? 950 : -950)) / 250;         
    if (mypow > 7) mypow = 7; else if (mypow < -7) mypow = -7;
    // mypow is from range 3..7 or -3..-7 
    mypow *= mylevel / 2 + 1;
    if (myalign >= 0) 
        light_power += mypow;
    else  
        dark_power += mypow;
    ncloaks++;
    return mypow;
}

// subtracts your power from global jedi power
void decompute_power(int mypow) {
    if (mypow >= 0) 
        light_power -= mypow;
    else 
        dark_power -= mypow;
    ncloaks--;
    if (ncloaks <= 0)
        light_power = dark_power = ncloaks = 0;
    return;
}

// returns power of the Dark side of The Force 
int query_dark_power() {
    return -dark_power;
}

// returns power of the Light side of the Force
int query_light_power() {
    return light_power;
}

// returns numeber of cloaks currenly worn
int query_ncloaks() {
    return ncloaks;
}

// returns (base) amount of SP to restore 
int query_power(int mypow) {
    int tmpow;
    tmpow = ((mypow >= 0) ? 
        (mypow + light_power / 2) : 
        (-mypow - dark_power / 2) ) / 3 + 1;
    if (tmpow > MAX_SPBOOST)
        tmpow = MAX_SPBOOST;
    return tmpow;
} 

// end of jedipower.c
