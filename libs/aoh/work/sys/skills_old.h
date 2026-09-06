/*
** File: /sys/skills.h
** Desc: Define the available skills and skillfunctions in OSB
**
**  V1.0 :   Softbyte   041097      : Creation
**
**
**
*/

#ifndef _SKILLS_H_
#define _SKILLS_H_


#define FAIL_LEARN_CHANCE 15 // the chance to learn from failures
#define GENERAL_LIST ({SK_THROW,SK_CLIMB,SK_SWIM,SK_JUMP,SK_DETECT,SK_SHOOT})

// ****************** MAGIC SKILLS *******************************************
#define SK_FIRE      "fire"     // the ability to cast fire spells 

// ****************** BODY SKILLS ********************************************
// Defined in std/room
#define SK_SEARCH      "searching"     // the ability to throw something
#define SK_CLIMB       "climbing"     // climbing on hills, trees
#define SK_SWIM        "swimming"     // swim through oceans, ...
#define SK_JUMP        "jumping"      // jumping 5 metres and more ;-)

#define SK_DETECT      "perception"       // detect traps, secrets, etc.

// Defined in std/thing
#define SK_THROW       "throwing"     // the ability to throw something

// Not yet implemented
#define SK_REPAIR      "repair"       // repair skill for weapons

// ************* PATH and FILENAMES ******************************************

#define SK_MAIN     "/p/skills/"         // The root directory
#define SK_STD(x)   SK_MAIN "std/"+(x)   // The std code
#define SK_MOD(x)   SK_MAIN "modules/"+(x)  // The skill modules
#define SK_DATA(x)  SK_MAIN "data/"+(x)  // The definition for the skills

#define SKILLSERVER "/p/skills/std/skillserver"  // The main skill handler


// ************ PROPERTIES ***************************************************
#define P_SK_THROW_MSG           "SKThrowMsg"
#define P_SK_THROW_DISTANCE      "SKThrowDistance"
#define P_SK_THROW_HITHP         "SKThrowHitHP"
#define P_SK_THROW_BREAK_CHANCE  "SKThrowBreakChance"
#define P_SK_THROW_BREAK_FUN     "SKThrowBreakFun"

#define P_SK_CLIMB_MSG           "SKClimbMsg"     // M_SPECIAL message
#define P_SK_CLIMB_DEST          "SKClimbDest"    // destination room
#define P_SK_CLIMB_HURTHP        "SKClimbHurtHP"  // dfamage on fail


// ************ LOGIN STUFF **************************************************
#define SK_TRAIN_NO 10         // so often can the skills be trained
#define SK_TRAIN_AMOUNT 30     // so much is on avarage learned by training


// ************ INTERNAL STUFF ***********************************************
#define S_PO    previous_object(1) // Modules need to use this as
                                   // previous_object due to the
                                   // Relay via the skill server

// ***************************************************************************


#endif /* _SKILLS_H */
