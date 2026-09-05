/*
 * This file defines flags that will make the game log facts.
 * If you change a definition, be sure to remove obj/player.i and
 * obj/living.i if you have them.
 */
#ifndef _sys_log_h_
#define _sys_log_h_

#define LOG_ECHOALL

/* Log all set and clear of flags to log/FLAGS */
#define LOG_FLAGS

/* Log what object/player marks that a quest is solved to log/QUESTS */
#define LOG_SET_QUEST

/* Log when players enter to log/ENTER */
#define LOG_ENTER

/* Log all newplayers to log/NEWPLAYER */
#define LOG_NEWPLAYER

/* Log all shutdowns to log/GAME_LOG */
#define LOG_SHUTDOWN

/* Log when someone is killed and by what to log/KILLS */
#define LOG_KILLS

/* Log illegal manipulation of the player.c object to log/ILLEGAL */
#define LOG_ILLEGAL_PLAYER

/* Log when a player gets exp or money from an interactive player to
 * log/EXPERIENCE
 * ROOM_EXP_LIMIT should be defined to the least amount of exp to be logged */
#define LOG_EXP
#define ROOM_EXP_LIMIT 9000

#endif /* _sys_log_h_ */
