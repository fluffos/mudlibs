#ifndef __ninja_defs__
#define __ninja_defs__

/* ----- defines for all include - files of the soul --------------------------- */

#define TRUE         (0x1)
#define FALSE        (0x0)

#define NINJA_TITLES "/players/patience/guild/ninja_titles"

#define GUILD_MASTER ("guild/master")                       /* the guild-master  */
#define GUILD        ("ninja")                              /* the guild-name    */

#define MEDITATOR    "/players/dice/guild/meditator"    /* the meditator     */

#define MY_ATTACKER  (this_player()->query_attack())        /* my attacker       */
#define TP           (this_player())                        /* just was it is :) */
#define TPN          (TP->query_name())                     /* name of player    */
#define TP_POSS      (TP->query_possessive())               /* possissive word   */
#define TP_PRON      (TP->query_pronoun())                  /* pronoun of player */
#define TP_MAXHP     (TP->query_max_hp())                   /* mx hp of player */
#define ALL_STAT_AV  ((TP->query_str() + TP->query_dex() + TP->query_con() +     \
                       TP->query_int() + TP->query_wis() + TP->query_chr())      \
                       / 6 )

#define THROW_DAM    ((TP->query_str() + TP->query_dex()) / 2)
                                                    /* throwing_skill     */

#define MAX_ATTACK_CON (TP->query_dex() * 4)        /* max. attack-condit.*/
#define FULL_ATTACK_COST (30)                       /* cost of full_attack*/
#define THROW_COST       (3)                        /* cost of throwing   */
#define KARATE_HIT     ((TP->query_dex() + TP->query_str() + TP->query_wis()) / 6)
                                                    /* feet-hit damage    */
#define KARATE_COST     (1 + TP->query_level()/3 - TP->query_dex()/6)
#define HEAL_PER_HB  ( (100 + TP_MAXHP) / 70)     /* healing rate per hb */

#define LOOK_COST    (0)                            /* sp-reduce of a look in a dark room */
#define SPY_COST     (5)                            /* sp-reduce of a spy */
#define CHECK_COST   (10)                           /* sp-reduce check monst.*/

#define SHOUT_COST   (20)                           /* sp-reduce for a shout */
#define TELL_COST    (0)                            /* sp-reduce for a tell */

#endif __ninja_def__
