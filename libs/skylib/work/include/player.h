/**
 * This file conatins all the defintions and stuff to handle the player
 * object.
 * @author Pinkfish
 */
#ifndef __SYS__PLAYER
/** @ignore yes */
#define __SYS__PLAYER

#include "playtesters.h"

/** The message to print for not having enough social points. */
#define NO_POWER "Insufficient Social Points.\n"
/** The message to print when you do not have the ability to do something. */
#define NOT_ALLOWED "You do not have that ability yet.\n"
/** The base cost of a shout in social points. */
#define SHOUT_COST 10
/** The base cost of a tell in social points. */
#define TELL_COST 1
/** The base cost of an emote in social points. */
#define EMOTE_COST 1
/** The base cost of a remote in social points. */
#define REMOTE_COST 5
/** The base cost of an echo in social points. */
#define ECHO_COST 1
/** The base cost of an echoto in social points. */
#define ECHOTO_COST 40
/** The base cost of an emoteall in social points. */
#define EMOTEALL_COST 8
/** The base cost of a soul in social points. */
#define SOUL_COST 3
/** The cost of setting a position with the 'position' command */
#define SET_POSITION_COST 50
/** The property which keeps track of if new lines are printed or not. */
#define NO_LINE_PROP "no new line"
/** The maximum amount of idle time for a player. */
#define MAX_IDLE 1800
/** The idle time at which they can be kicked off. */
#define FULL_IDLE 450

/**
 * The age in days at which you are considered to be mature.
 * @see /globla/player->query_mature()
 */
#define MATURITY 18

/** The character which is death.  This is the path to the poor thing. */
#define DEATH "/obj/monster/death"
/** The book to give to people when they die. */
#define DEAD_BOOK "/obj/misc/dead_book"
/** The shadow to use when your dead, to stop most things from happening. */
#define DEATH_SHADOW "/std/shadows/misc/death_shadow"

/**
 * The shadow offler gives you when your close to shutdown to stop certain
 * things from happening.
 */
#define OFFLER_SHADOW "/std/shadows/misc/offler_shadow"

/**
 * This is the time interval for automatic saving of players.
 */
#define TIME_BETWEEN_SAVES 450

/** The size of the tell history. */
#define MAX_TELL_HIS 20

/** The default amount of time in each round (heart_beat). */
#define ROUND_TIME 40
/** The default amount of time an action will take. */
#define DEFAULT_TIME 20 /* Time for a move or a look. */

/** The speed at which combat occurs, number of attacks a round. */
#define COMBAT_SPEED 2
/** Something neato to do with combat damage. */
#define COMBAT_DAMAGE 2

/**
 * The time at which to start warming people that the person being told is
 * idle.
 */
#define TELL_WARN_TIME 120
/** The maximum size allowed to be set for your description. */
#define MAX_DESC 2048

/** The object which defines all the stuff you get when you start the game. */
#define START_PLAYER "/global/player/newbie_junk"

/** The property to be used for defining a player killer. */
#define PKER "player_killer"
/** The misspelt property to be used for defining a player killer. */
#define PKER_MISSPELL "player killer"
/** The property indicating that the person was killed by a pk_death */
#define PK_KILLED "pk_killed"
/** The age you need to be to become a player killer. (2 days). */
#define PKER_MINIMUM_AGE (60 * 60 * 24 * 2)
/**
 * This property (if set on a player) means that they cannot become a
 * player killer.
 */
#define PKER_NOT_ALLOWED "not to be pk"
/** The token used in pk applications. */
#define PK_TOKEN "/obj/misc/pk_token"

/** Minimum time between saves using save command. */
#define MIN_SAVE_REPEAT 900

/** The path to the player file. */
#define PLAYER_OB "/global/player"
/** The path to the creator file.  */
#define CREATOR_OB "/global/creator"

/** The path to the auto load object. */
#define AUTO_LOAD_OB "/global/player/auto_load"

/** The unknown birthday type. */
#define UNKNOWN_BIRTHDAY "Not Known"

#endif /* __SYS__PLAYER */
