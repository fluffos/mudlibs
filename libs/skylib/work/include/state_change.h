/*
 * state_change.h - include file for /handlers/state_change.c
 */

class state_change {
    string result;       // Path of result
    float factor;        // Ratio of old amount to new amount
    function *func;      // Array of function pointers for configuring
                         // the result on-the-fly
}
