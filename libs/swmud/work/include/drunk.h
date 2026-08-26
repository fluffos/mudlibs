#ifndef __DRUNK_H__
#define __DRUNK_H__

//Skill checks for combat/stance would get more 
//difficult the more drunk you are. These factors
//are multiplied unto the skill checks.
#define STANCE_IMPACT_AT_30 1.2
#define STANCE_IMPACT_AT_50 2
#define STANCE_IMPACT_AT_80 5

//Risk of stumbling begins at STUMBLE_AT % drunk.
//The chance is calculated as
//  random(100) < (drunk_percent - STUMBLE_AT)
//So 100% drunk gives you 50% stumble chance:
//
// Drunkenness      Stumble Risk   Fall risk
// 100%         --> 50%        --> 30%
//  60%         --> 10%        -->  0%
//  70%         --> 20%        -->  0%
// If the chance is even FALL_AT below, you also fall.
#define STUMBLE_AT 50
#define FALL_AT 20

//If random(FALL_INTO_NEXT_ROOM) returns true, you still move.
//2 would be 50/50 chance. 3 would be 66& chance etc.
#define FALL_INTO_NEXT_ROOM 2

//If more drunk than this, you'll get the [drunk] condition
#define SHOW_IN_ROOM 70

#endif