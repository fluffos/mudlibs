#define OPEN_DOMAINS ({ "Genesis" })

#define MASTER_OB "/obj/master"

/*
 * This one is used by the experimental map system. It defines the object
 * that manages the map.
 */
#define MAP_OB "/room/map/map"

#define MAP_OBJECT(file_name) (extract(file_name, 0, 10) == "/room/map/m")

/*
 * This is an important constant. It says how many hits a fighter has
 * had with his weapon when the fighter is in between a beginner and
 * an expert user.
 *
 * If this value is changed a lot suddenly, then all players will suddenly
 * have it more easy or harder.
 */
#define AVERAGE_EXPERIENCE	5000

/*
 * Convert the experience amount into a skill value, in the range
 * 0 - 100.
 */
#define EXP_TO_PERCENT(exp)\
    (100 - 100 * AVERAGE_EXPERIENCE / (AVERAGE_EXPERIENCE + (exp)))

/*
 * Different skills has different learning curves. For example, a fighter
 * might have to hit 1000 times before he is an average fighter.
 * But a thief may only have to pick locks 100 times before he is
 * an average thief. All skills when used must define what learning constant
 * below to use. The administrator may later change this value to tune
 * the game.
 *
 * Always use one of the symbols below, not an absolute numeric value.
 */

#define LEARNING_1		1	/* Fighting etc */
#define LEARNING_2		5	/* Using spells in combats etc */
#define LEARNING_3		20	/* Pick locks,climb, unusual spells */
#define LEARNING_4		100	/* Very unusual actions */
#define LEARNING_5		1000	/* Extremly unusual actions */
