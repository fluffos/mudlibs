> more ndef.h
#ifndef __ninja_defs__
#define BIN "/players/tatsuo/guild/bin/"
#define TPRN TP->query_real_name()
#define GUILDROOM "/players/tatsuo/guild/room"
#define __ninja_defs__


#define TRUE         (0x1)
#define FALSE        (0x0)

#define WEAP_OWNERS  "/players/tatsuo/guild/nweap/weap_owners"
#define BANISHED     "/players/tatsuo/ezo/fconference"

#define NINJA_TITLES "/players/tatsuo/guild/ninja_titles"

#define GUILD_MASTER ("guild/master")                       /* the guild-master  */
#define GUILD        ("ninja")                              /* the guild-name    */

#define MEDITATOR    "/players/tatsuo/guild/meditator"    /* the meditator     */
 /* -------------------  GLOBALS ----------------- */
#define MY_ATTACKER  (this_player()->query_attack())        /* my attacker       */
#define TP           (this_player())                        /* just was it is :) */
#define TPN          (TP->query_name())                     /* name of player    */
#define TP_POSS      (TP->query_possessive())               /* possissive word   */
#define TP_PRON      (TP->query_pronoun())                  /* pronoun of player */
#define TP_MAXHP     (TP->query_max_hp())                   /* mx hp of player */
#define ALL_STAT_AV  ((TP->query_str() + TP->query_dex() + TP->query_con() +     \
                       TP->query_int() + TP->query_wis() + TP->query_chr())      \
                       / 6 )
#define TPSTR TP->query_str()
#define TPDEX TP->query_dex()
#define TPCON TP->query_con()
#define TPINT TP->query_int()
#define TPWIS TP->query_wis()
#define TPCHR TP->query_chr()
#define HONOR TP->query_chr()*2

/* ------------------  DAMAGE CALC --------------- */

#define THROW_DAM    ((TP->query_str() + TP->query_dex()) / 2)
#define KARATE_HIT     ((TP->query_dex() + TP->query_str() + TP->query_wis()) / 6)


/* --------------------- COST CALC -------------- */
                                                  
#define MAX_ATTACK_CON (TP->query_dex() * 4)        /* max. attack-condit.*/
#define THROW_COST       (3)                        /* cost of throwing   */
#define KARATE_COST     (1 + TP->query_level()/3 - TP->query_dex()/6)
#define HEAL_PER_HB  ( (100 + TP_MAXHP) / 70)     /* healing rate per hb */

#define LOOK_COST    (0)                            /* sp-reduce of a look in a dark room */
#define SPY_COST     (5)                            /* sp-reduce of a spy */
#define CHECK_COST   (10)                           /* sp-reduce check monst.*/

#define SHOUT_COST   (20)                           /* sp-reduce for a shout */
#define TELL_COST    (0)                            /* sp-reduce for a tell */
 

 /* --------------- SKILL SYSTEM ----------------- */

#define KARATESKILL  ((TPDEX*2)+TPINT+TPWIS+TPSTR)/2 /* MAX 100 - Karate */
#define SLASHSKILL   ((TPSTR*4)+TPDEX)/2             /* MAX 100 - Slash */
#define SILENCESKILL ((TPDEX*2)+(TPINT*2)+TPWIS)/2   /* MAX 100 - Vanish, Spy, Camo */
#define ASSASSKILL   ((SILENCESKILL/2)+((TPDEX*5/4)  /* MAX 100 - Assassinate */
#define DISARMSKILL  ((TPDEX*3)+(TPSTR*2))/2         /* MAX 100 - Disarm */
#define BREAKSKILL   ((TPSTR*3)+(TPDEX*2))/2         /* MAX 100 - Break */
#define SHADOWMAGIC  (TPINT+(TPWIS*2)+HONOR)/2       /* MAX 100 - FS, SW, Freeze */

#endif __ninja_def__

