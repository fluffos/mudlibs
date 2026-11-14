#ifndef _HEALTH_
#define _HEALTH_ 1

// Normal regeneration rates in 1/10-HP per heartbeat

#define HP_RATE        3
#define SP_RATE        3
#define PEP_RATE       15
#define MEP_RATE       15
#define ALCOHOL_RATE   2     // added to HP/SP_RATE
#define POISON_RATE    3

// Degeneration rate of alcohol, food and drink, in 1/100 points per hb.

#define ALCOHOL_DEG    30    // quite fast
#define DRINK_DEG       1    // quite slow
#define FOOD_DEG        1    // quite slow

// ------------------------ Compatibility --------------------------
/* These are tune macros to determine the actual effect of food, */
/* drink and alcohol */

#define ALCOHOL_VALUE(strength) strength
#define DRINK_VALUE(strength)   strength
#define FOOD_VALUE(strength)    strength
 
// Degeneration rates.

#define ALCOHOL_DELAY   3    // quite fast
#define DRINK_DELAY   100    // quite slow
#define FOOD_DELAY    100    // quite slow
#define HEAL_DELAY      4    // quite fast

// Relative values for alcohol content - for use in pubs etc.

#define LOW_ALCOHOL     5    //  cidre, shandy
#define BEER_ALCOHOL    9    //  average beer
#define WINE_ALCOHOL   13    //  average wine
#define HARD_ALCOHOL   20    //  liqueurs and distilled 
 

#define MIN_FOOD_EVAL(soak,stuff,alc,heal,weight) \
	(soak+stuff+alc*2+heal*heal/4-weight/100)
#define MIN_FOOD_COST(soak, stuff, alc, heal, weight) \
	(MIN_FOOD_EVAL(soak,stuff,alc,heal,weight)>10 \
	? MIN_FOOD_EVAL(soak,stuff,alc,heal,weight) \
	: random(10)+1)

// how much does it cost to heal <heal> HP
#define HEAL_COST(heal) heal*10

// how are the wounds defined at the healer
#define LIGHT_WOUNDS    10
#define SERIOUS_WOUNDS  30
#define CRITICAL_WOUNDS 50

// The necessary ids for poison, curse and virus.
// May be used in AddId.
#define D_POISON  "poison-object"
// D_POISON mustn't be "poison" because bottles with poisons
// inside might identify to it as well
#define D_CURSE   "curse"
#define D_DISEASE "virus"

#define NIGHT_COST(c) (c*4)
#endif







