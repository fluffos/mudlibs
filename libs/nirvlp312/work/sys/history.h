/*
 * /sys/history.h
 * Macros for the history mappings of the players
 */

#ifndef _sys_history_h
#define _sys_history_h

#define HIST_DATE       "date"       /* is set in every mapping and points to
                                      * an int stating the time this event
                                      * happened                            */
#define HIST_AGE        "age"        /* is set in every mapping created after
                                      * 2001-Sep01                          */
#define HIST_LEVEL      "level"      /* is set in every mapping created after
                                      * 2001-Sep01                          */
#define HIST_BIRTH      "birth"      /* is set in the mapping that states when
                                      * a player appeared first             */
#define HIST_SPONSOR    "sponsor"    /* points to a name of the sponsor in the
                                      * mapping that states when a player
                                      * became wizard                       */
#define HIST_ELDER      "elder"      /* when did he become elder?           */
#define HIST_ARCH       "arch"       /* when did he become arch?            */
#define HIST_NEW_LEVEL  "new_level"  /* points to new level                 */
#define HIST_DEMOTE     "demote"     /* points to a string explaining the
                                      * demotion                            */
#define HIST_QUEST      "quest"      /* points to the name of the quest he
                                      * solved                              */
#define HIST_SCENARIO   "scenario"   /* points to the name of the scenario
                                      * he solved                           */
#define HIST_KILLER     "killer"     /* points to the name of the monster he
                                      * was killed by                       */
#define HIST_HOLIDAY    "holiday"    /* points to the amount of seconds since
                                      * the last login; this will only be
                                      * entered into the history if this time
                                      * is large (>1month or so)            */
#endif
