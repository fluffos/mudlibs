#ifndef __SYS__INHUME
#define __SYS__INHUME

#define DEBUG // Define to start logging skills info to LOGFILE. undefine for normal use.
#define LOGFILE "/w/shrike/secure/inhume.log"
#define TM_LOG "/log/INHUME_TMS"
#define PLAY_LOG "/w/shrike/secure/play_inhume.log"
// #define NOKILL  // For testing purposes -- noone will attack or die if this is defined

#define INHUME "/handlers/inhume.lpc"

#define EXP_TIME   2419200       // 28 days
#define TAXES      40            // how much they steal in taxes
#define SURCHARGE  10            // service charge for timed-out contracts
#define NOTME_MULT 1.1           // How much extra if you pay for a
                                 // contract someone else requested.
#define MIN_LEVEL  50            // minimum level for a contract
#define PK_MULT    0             // how much extra nonPKs cost
                                 // 0 indicates disallowed
#define COST_MULT  ( 5 * 400 )   // how much per level 400 = 1$AM
#define COST_GUILD ( 6 * 400 )   // Premium rate for contracts on
                                 // guild members.
#define MAXTIMES 4               // how many times can you inhume
                                 // an NPC.
#define NO_DEATH_MULT 0.5        // How much less you pay for a contract
                                 // that doesn't cause the victim to lose
                                 // a life.

/* failure values when validating contracts */
#define LOW          -1
#define NON_KILLER   -2
#define CRE          -3
#define TOO_SOON     -4

/* status values for contracts */
#define REQUESTED 0
#define VALIDATED 1
#define INFORMED 2
#define ACTIVE 3
#define SPECIAL 4

/* Rate at which a given player can be inhumed. */
#define REPEAT_RATE ( 60 * 60 * 24 * 7 * 2 ) // 2 weeks

/* Time before an npc will start working on a player contract */
#define NPC_TIME ( 60 * 60 * 24 * 7 * 2 ) // 2 weeks

#endif /* __SYS__INHUME */
