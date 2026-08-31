
#ifndef __ninja_defs__

 /* ------------- GUILD DEFINES -------------- */
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
#define TO this_object()
#define TPN          (TP->query_name())                     /* name of player    */
#define TPL          (TP->query_level())
#define TP_POSS      (TP->query_possessive())               /* possissive word   */
#define TP_PRON      (TP->query_pronoun())                  /* pronoun of player */
#define TP_MAXHP     (TP->query_max_hp())                   /* mx hp of player */
#define ALL_STAT_AV  ((TPSTR() + TPDEX() + TPCON+     \
                       TPINT() + TPWIS() + TPCHR()) / 6 )
#define TPSTR TP->query_str()
#define TPDEX TP->query_dex()
#define TPCON TP->query_con()
#define TPINT TP->query_int()
#define TPOSS TP->query_possessive()
#define TPWIS TP->query_wis()
#define TPCHR TP->query_chr()
#define HONOR TP->query_chr()*2

/* ------------------  DAMAGE CALC --------------- */

#define WIND_DAM ((TPINT*2)+(TPWIS*2))
#define SLASHOBJ  "/players/tatsuo/guild/obj/slasher"
#define FIREDAM (random(25)+100);
#define THROW_DAM (TPDEX+TPSTR*2)
#define KARATE_HIT ((TPL*6)+(TPSTR*3))/2


/* --------------------- COST CALC -------------- */

#define HEAL_PER_HB ((100 + TP_MAXHP)/70)                                                      
#define MAX_ATTACK_CON (TP->query_dex() * 4)        /* max. attack-condit.*/

#define THROW_COST   (3)                        /* cost of throwing   */
#define NSAY_COST (1)
#define NSHOUT_COST (20)
#define KARATE_COST (10+TPINT)/2
#define LOOK_COST (0)                            /*sp-reduce of a look in dark room */
#define SPY_COST     (5)                            /* sp-reduce of a spy */
#define CHECK_COST   (10)                           /* sp-reduce check monst.*/
#define SLASH_COST   (100)                          /* sp-reduce of slash */
#define SHOUT_COST   (20)                           /* sp-reduce for a shout */
#define TELL_COST    (0)                            /* sp-reduce for a tell */
#define FIRE_COST (25)
#define WIND_COST (30)
#define FREEZE_COST (50)
#define DISARM_COST  (100)
#define BREAK_COST   (75)
#define POSE_COST    (35)
#define ASSASS_COST  (TP->query_max_sp()-50)
#define CAMOU_COST   (50)


 /* --------------- SKILL SYSTEM ----------------- */

#define KARATESKILL  ((TPDEX*2)+TPINT+TPWIS+TPSTR)/2   /* MAX 100 - Karate */
#define SLASHSKILL   ((TPSTR*4)+TPDEX)/2               /* MAX 100 - Slash */
#define SILENCESKILL ((TPDEX*2)+(TPINT*2)+TPWIS)/2     /* MAX 100 - Vanish, Spy, Camo */
#define ASSASSKILL   ((SILENCESKILL/2)+((TPDEX*5)/4))  /* MAX 100 - Assassinate */
#define DISARMSKILL  ((TPDEX*3)+(TPSTR*2))/2           /* MAX 100 - Disarm */
#define BREAKSKILL   ((TPSTR*3)+(TPDEX*2))/2           /* MAX 100 - Break */
#define SHADOWMAGIC  (TPINT+(TPWIS*2)+HONOR)/2         /* MAX 100 - FS, SW, Freeze */
#define THROWSKILL ((TPDEX*4)+TPINT)/2           /*  MAX 100 - Throw */

#endif __ninja_def__


