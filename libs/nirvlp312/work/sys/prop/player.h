/*
 *  <prop/player.h>
 *
 * Here the properties which may be set in player objects are defined.
 * Properties which are not defined here cannot be set in player objects.
 * If you add new properties to the list in this file, do not forget to
 * add the properties to the array PLAYER_PROPERTIES at the end of this
 * file.
 */

#ifndef _sys_prop_player_h
#define _sys_prop_player_h

#include "/sys/prop/living.h" // I have to have P_MSGIN, P_MSGOUT, P_MMSGIN and
                          // P_MMSGOUT available for the players, too.
                          // Just include it here, but use only these four
                          // properties in PLAYER_PROPERTIES.

#define P_TESTPLAYER            "testplayer"      /* name of wizard who 'owns'
                                                     the player. */
#define P_NO_MORE               "no_more"         /* don't stop output after
                                                     x lines */
#define P_DISPLAY_WIDTH         "display_width"   /* display width and    */
#define P_DISPLAY_HEIGHT        "display_height"  /* height in characters */

#define P_MSGCLONE              "msgclone"        /* message when cloning */

#define P_MSGDESTRUCT           "msgdestruct"     /* message when destructing */

#define P_ECHO                  "echo"            /* echo say, tell, etc. */

#define P_VERBOSE_SEQUENCE      "verbose_sequence"        
                                  /* display commands while running sequence */

#define P_ED_USER               "ed_user"         /* an ED-user, wow */

#define P_COMBINED              "combined"        /* will look at combined
                                                     short-descriptions all 
                                                     the time, yeah */
#define P_EDITING               "editing"         /* mode in which the 
                                                     player is (during an
                                                     input_to, should
                                                     be something like:
                                                     'writing something' etc.
                                                     */
#define P_AWAY                  "away"            /* message and the time
                                                     when a player used the
                                                     'away'-command */

#define P_TAB_EXPAND            "tab_expand"      /* if set then the tab
                                                     expanding of filenames
                                                     should work.
                                                     THIS IS NOT INSTALLED,
                                                     DO NOT USE THIS !!! */
#define P_REDIRECT_OUTPUT       "redirect_output" /* if set then the redirect-
                                                     ion with the >-character
                                                     in the command line works.
                                                     THIS IS NOT INSTALLED,
                                                     DO NOT USE THIS !!! */

#define P_FIGHTABLE             "fightable"       /* can attack other players
                                                     with this property and
                                                     can be attacked by them */

#define P_RACE                  "race"            /* of what race is the
                                                     player? (for the combat
                                                     system) */
#define P_DONT_SHOW_CLOAKED     "dont_show_cloaked" /* do not show the
                                                     current query_name() of
                                                     the player when he is
                                                     cloaked after the "you"
                                                     in every message.
                                                     possible values:
                                                     0: show the cloak when
                                                       current description
                                                       differs from the
                                                       vis_name
                                                     1: never show cloak
                                                     string: show when current
                                                       description differs from
                                                       this string
                                                     object: like string, but
                                                       the result of the lfun
                                                       query_current_vis_name()
                                                       in this object is used
                                                       as string */

#define P_MONITOR               "monitor"           /* if set all changes
                                                       of hit and spellpoints
                                                       are reported */

#define P_ADD_INVENTORY         "add_inventory"     /* if set, inventory is
                                                       added to the long
                                                       description upon 'look'
                                                       */

#define P_VERBOSE_WHO           "verbose_who"       /* if set, you get a more
                                                       detailed who list that
                                                       includes levels */

#define P_DONT_BEEP             "dont_beep"         /* if set, you don't wish
                                                       to be beeped and no
                                                       acoustic signal will
                                                       come through */

#define P_LITTLEMAP             "littlemap"         /* show those little map
                                                       left to the room
                                                       description */

#define P_AUTO_REFUSE           "auto_refuse"       /* automatically refuse
                                                       objects which another
                                                       player 'gives' to you.
                                                       the other player has
                                                       to 'offer' the items
                                                       then. */
#define P_ALL_FAIL_MESSAGES     "all_fail_messages" /* setting this in a
                                                       player results in him
                                                       getting all notify_-
                                                       fail-messages instead
                                                       of just the last
                                                       highest priorized. */

#define P_HIDE_AUTOLOADS        "hide_autoloads"    // hide autoloads for the
                                                    // inventory command,

#define P_PROMPT_TERMINATOR     "prompt_terminator" /* this is the string
                                                       which will be sent
                                                       after each prompt to
                                                       make it easier for the
                                                       frontend.  */

#define P_TERMCOL_MODEL         "colour_model"      // coloured messages
#define P_TERMCOL_STATUS        "colour_status"     // used for several
                                                    // colour toggles,
#define P_TERMCOL_SETTING       "colour_setting"

#define P_RESIZE_WINDOW         "resize_window"     /* when resizing the window,
                                                       adjust display variables;
                                                        1: adjust display
                                                        0: give usage hint
                                                       -1: do nothing at all.
                                                     */

#define P_TTY_TYPE              "tty_type"          /* contains the tty-type of
                                                       a player, e.g. vt100;
                                                     */

#define PLAYER_PROPERTIES ({ \
P_NO_MORE,              \
P_DISPLAY_WIDTH,        \
P_DISPLAY_HEIGHT,       \
P_MSGCLONE,             \
P_MSGDESTRUCT,          \
P_ECHO,                 \
P_TESTPLAYER,           \
P_VERBOSE_SEQUENCE,     \
P_ED_USER,              \
P_COMBINED,             \
P_EDITING,              \
P_AWAY,                 \
P_TAB_EXPAND,           \
P_REDIRECT_OUTPUT,      \
P_FIGHTABLE,            \
P_RACE,                 \
P_DONT_SHOW_CLOAKED,    \
P_MONITOR,              \
P_ADD_INVENTORY,        \
P_VERBOSE_WHO,          \
P_DONT_BEEP,            \
P_LITTLEMAP,            \
P_AUTO_REFUSE,          \
P_ALL_FAIL_MESSAGES,    \
P_MSGIN,                \
P_MSGOUT,               \
P_MMSGIN,               \
P_MMSGOUT,              \
P_HIDE_AUTOLOADS,       \
P_PROMPT_TERMINATOR,    \
P_TERMCOL_MODEL,        \
P_TERMCOL_STATUS,       \
P_TERMCOL_SETTING,      \
P_RESIZE_WINDOW,        \
P_TTY_TYPE,             \
P_INTERVAL_BETWEEN_HEALING,     \
P_REGENERATION_MODE,    \
P_REGENERATION_RATE,    \
P_MAX_STR,              \
P_MAX_DEX,              \
P_MAX_INT,              \
P_MAX_STE,              \
P_MAX_STA,              \
P_MAX_MAG,              \
P_MAX_PIE,              \
P_MAX_CHA,              \
P_MAX_LUC,              \
P_MAX_WIL,              \
})

#endif /* _sys_prop_player_h */

