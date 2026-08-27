/* TIME_BETWEEN_HEAL is scaling factor to speed or slow the rate of healing. */

#define TIME_BETWEEN_HEAL 5

/* minimum time between guild changes - obsolete currently*/

#define MIN_TIME 2*60*60*60   

/* tuning for cost of advanncing in guilds.  STD_COST is a base and LEVEL_DIV
   is a gradient factor.  Increasing STD_COST makes skills more expensive and
   decreasing LEVEL_DIV will increase the rate at which the skills increase in
   cost.  LEVEL_DIV of 3 gives a rate of 1/3 */

#define STD_COST 500
#define LEVEL_DIV 1
