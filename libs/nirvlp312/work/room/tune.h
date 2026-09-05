/*
 * This file is used to tune the game
 * The game should be "easy" in the beginning, because there are not
 * enough monsters and puzzles.
 * When wizards start to create new rooms, an inflation will be noted
 * (it is easier to become wizard).
 *
 * EXP_COST: How many experience points you get for 1000 gold coins in
 * avdenturers guild.
 *	2000: For an easy start.
 *	1000: Normal.
 *	500:  Extremly inflated game.
 */
/*
 *
 * If you change this value, remove adv_guild.i (if you have it), so that
 * the new value will be used at restart of the game.
 *
 * Big LPmuds usually have several guilds made by other wizards. It is
 * very important that they call query_cost() in adv_guild.c to determine
 * what the cost is to advance a player. All guilds should have the same
 * cost for advancing.
 */

#define EXP_COST	300
#define ATTRIB_COST 2200
#define ATTRIB_COST_TWO 3800
#define ATTRIB_COST_THREE 6000
/* attrib. costs for groups -Bp */

#define SKILL_COST 6000
#define SKILL_COST_TWO 18000
#define SKILL_COST_THREE 35000
/* For guilds, like templars -Bp */
/*
 * When there are many quests in the game, it is not good to force
 * the players to solve all of them. FREE_QUESTS defines how many of
 * them that you don't have to solve. If you change this value, remove
 * quert_room.i (if you have one), so that the new value will be used
 * when the game is restarted next time.
 *
 */
/*
 * Recommended values:
 *
 * Number of quests		FREE_QUESTS
 * 1 (default)			0
 * 4				0
 * 8				2
 * 16				4
 * 24				6
 */

#define FREE_QUESTS	0
/* How many quest points to become wizard???*/
/* set at total avialible qp - 1*mean qp value of quests */
#define NEEDED_QP     284
#define TOTAL_QP      370
