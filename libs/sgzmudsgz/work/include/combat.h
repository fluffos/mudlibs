#define RES_DISARM              1 /* This blow should disarm it's target */
#define RES_NOWEAPONONHORSE	2 /* ride a horse without weapon, can't hit others */
#define RES_PARRY               3 /* target parry successful */
#define RES_DODGE		4 /* target dodge successful */
#define RES_HIT			5 /* hit the target */
#define RES_WAIT		6 /* wait a good chance to hit */
#define RES_TALK                7 /* say something */
#define RES_MISS        8 /* miss the target */
////////////////////////////////////////////////////////////////////////
#define COMBAT_FIGHT 1  // a common fight
#define COMBAT_KILL 2   // this is a kill only in certain situation
#define COMBAT_DANTIAO 3 // a dantiao in the war
/* old code */
#define RES_MIGHT_BE_FATAL      2 /* A potentially fatal blow */
#define RES_NO_RESISTANCE       4 /* Target is asleep, or willing to die */
#define RES_NONE                8 /* Ignore this result */
#define RES_KNOCKDOWN           16 /* This blow should knockdown it's target */
#define RES_KNOCKOUT            32 /* This blow should knock out it's target */
#define RES_FATAL               64 /* This blow _is_ fatal, no matter what */
#define RES_NONPHYSICAL        128 /* Not a physical blow.  E.g. normal */
