#ifndef _sys_color_h
#define _sys_color_h

#include "ansi.h"

/*
 *
 * first the defines for the status bits for P_TERMCOL_STATUS
 */
#define TERMCOL_BIT_SERVICE        0
#define TERMCOL_BIT_DESCRIPTION    1
#define TERMCOL_BIT_TECHNICAL      2


/*
 *
 * now the real tokens ...
 */

#define TERMCOL_UNDERSCORE          "UNDERSCORE"

#define TERMCOL_NORMAL              "NORMAL"
#define TERMCOL_BLACK               "BLACK"
#define TERMCOL_RED                 "RED"
#define TERMCOL_GREEN               "GREEN"
#define TERMCOL_YELLOW              "YELLOW"
#define TERMCOL_BLUE                "BLUE"
#define TERMCOL_MAGENTA             "MAGENTA"
#define TERMCOL_CYAN                "CYAN"
#define TERMCOL_WHITE               "WHITE"

#define TERMCOL_BOLD                "BOLD"
#define TERMCOL_BOLD_BLACK          "BOLD_BLACK"
#define TERMCOL_BOLD_RED            "BOLD_RED"
#define TERMCOL_BOLD_GREEN          "BOLD_GREEN"
#define TERMCOL_BOLD_YELLOW         "BOLD_YELLOW"
#define TERMCOL_BOLD_BLUE           "BOLD_BLUE"
#define TERMCOL_BOLD_MAGENTA        "BOLD_MAGENTA"
#define TERMCOL_BOLD_CYAN           "BOLD_CYAN"
#define TERMCOL_BOLD_WHITE          "BOLD_WHITE"

#define TERMCOL_BG_PREFIX           "BG_"

#define TERMCOL_BG_BLACK            TERMCOL_BG_PREFIX "BLACK"
#define TERMCOL_BG_RED              TERMCOL_BG_PREFIX "RED"
#define TERMCOL_BG_GREEN            TERMCOL_BG_PREFIX "GREEN"
#define TERMCOL_BG_YELLOW           TERMCOL_BG_PREFIX "YELLOW"
#define TERMCOL_BG_BLUE             TERMCOL_BG_PREFIX "BLUE"
#define TERMCOL_BG_MAGENTA          TERMCOL_BG_PREFIX "MAGENTA"
#define TERMCOL_BG_CYAN             TERMCOL_BG_PREFIX "CYAN"
#define TERMCOL_BG_WHITE            TERMCOL_BG_PREFIX "WHITE"

/* these defines have the "%^" added here already, because they are
 *  not handled by LIB_CNTL_SEQUENCES.
 */
#define TERMCOL_DESC              "DESC_"
#define TERMCOL_DESC_UNDERSCORE   "%^" TERMCOL_DESC TERMCOL_UNDERSCORE "%^"
#define TERMCOL_DESC_NORMAL       "%^" TERMCOL_DESC TERMCOL_NORMAL "%^"
#define TERMCOL_DESC_BLACK        "%^" TERMCOL_DESC TERMCOL_BLACK "%^"
#define TERMCOL_DESC_RED          "%^" TERMCOL_DESC TERMCOL_RED "%^"
#define TERMCOL_DESC_GREEN        "%^" TERMCOL_DESC TERMCOL_GREEN "%^"
#define TERMCOL_DESC_YELLOW       "%^" TERMCOL_DESC TERMCOL_YELLOW "%^"
#define TERMCOL_DESC_BLUE         "%^" TERMCOL_DESC TERMCOL_BLUE "%^"
#define TERMCOL_DESC_MAGENTA      "%^" TERMCOL_DESC TERMCOL_MAGENTA "%^"
#define TERMCOL_DESC_CYAN         "%^" TERMCOL_DESC TERMCOL_CYAN "%^"
#define TERMCOL_DESC_WHITE        "%^" TERMCOL_DESC TERMCOL_WHITE "%^"
#define TERMCOL_DESC_BOLD         "%^" TERMCOL_DESC TERMCOL_BOLD "%^"
#define TERMCOL_DESC_BOLD_BLACK   "%^" TERMCOL_DESC TERMCOL_BOLD_BLACK "%^"
#define TERMCOL_DESC_BOLD_RED     "%^" TERMCOL_DESC TERMCOL_BOLD_RED "%^"
#define TERMCOL_DESC_BOLD_GREEN   "%^" TERMCOL_DESC TERMCOL_BOLD_GREEN "%^"
#define TERMCOL_DESC_BOLD_YELLOW  "%^" TERMCOL_DESC TERMCOL_BOLD_YELLOW "%^"
#define TERMCOL_DESC_BOLD_BLUE    "%^" TERMCOL_DESC TERMCOL_BOLD_BLUE "%^"
#define TERMCOL_DESC_BOLD_MAGENTA "%^" TERMCOL_DESC TERMCOL_BOLD_MAGENTA "%^"
#define TERMCOL_DESC_BOLD_CYAN    "%^" TERMCOL_DESC TERMCOL_BOLD_CYAN "%^"
#define TERMCOL_DESC_BOLD_WHITE   "%^" TERMCOL_DESC TERMCOL_BOLD_WHITE "%^"
#define TERMCOL_DESC_BG_BLACK     "%^" TERMCOL_DESC TERMCOL_BG_BLACK "%^"
#define TERMCOL_DESC_BG_RED       "%^" TERMCOL_DESC TERMCOL_BG_RED "%^"
#define TERMCOL_DESC_BG_GREEN     "%^" TERMCOL_DESC TERMCOL_BG_GREEN "%^"
#define TERMCOL_DESC_BG_YELLOW    "%^" TERMCOL_DESC TERMCOL_BG_YELLOW "%^"
#define TERMCOL_DESC_BG_BLUE      "%^" TERMCOL_DESC TERMCOL_BG_BLUE "%^"
#define TERMCOL_DESC_BG_MAGENTA   "%^" TERMCOL_DESC TERMCOL_BG_MAGENTA "%^"
#define TERMCOL_DESC_BG_CYAN      "%^" TERMCOL_DESC TERMCOL_BG_CYAN "%^"
#define TERMCOL_DESC_BG_WHITE     "%^" TERMCOL_DESC TERMCOL_BG_WHITE "%^"

#define TERMCOL2DESC_TERMCOL ([ \
            TERMCOL_NORMAL       : TERMCOL_DESC_NORMAL,           \
            TERMCOL_BLACK        : TERMCOL_DESC_BLACK,            \
            TERMCOL_RED          : TERMCOL_DESC_RED,              \
            TERMCOL_GREEN        : TERMCOL_DESC_GREEN,            \
            TERMCOL_YELLOW       : TERMCOL_DESC_YELLOW,           \
            TERMCOL_BLUE         : TERMCOL_DESC_BLUE,             \
            TERMCOL_MAGENTA      : TERMCOL_DESC_MAGENTA,          \
            TERMCOL_CYAN         : TERMCOL_DESC_CYAN,             \
            TERMCOL_WHITE        : TERMCOL_DESC_WHITE,            \
            TERMCOL_BOLD         : TERMCOL_DESC_BOLD,             \
            TERMCOL_BOLD_BLACK   : TERMCOL_DESC_BOLD_BLACK,       \
            TERMCOL_BOLD_RED     : TERMCOL_DESC_BOLD_RED,         \
            TERMCOL_BOLD_GREEN   : TERMCOL_DESC_BOLD_GREEN,       \
            TERMCOL_BOLD_YELLOW  : TERMCOL_DESC_BOLD_YELLOW,      \
            TERMCOL_BOLD_BLUE    : TERMCOL_DESC_BOLD_BLUE,        \
            TERMCOL_BOLD_MAGENTA : TERMCOL_DESC_BOLD_MAGENTA,     \
            TERMCOL_BOLD_CYAN    : TERMCOL_DESC_BOLD_CYAN,        \
            TERMCOL_BOLD_WHITE   : TERMCOL_DESC_BOLD_WHITE,       \
          ])

#define TERMCOL2DESC_BG_TERMCOL ([ \
            TERMCOL_BLACK        : TERMCOL_DESC_BG_BLACK,         \
            TERMCOL_RED          : TERMCOL_DESC_BG_RED,           \
            TERMCOL_GREEN        : TERMCOL_DESC_BG_GREEN,         \
            TERMCOL_YELLOW       : TERMCOL_DESC_BG_YELLOW,        \
            TERMCOL_BLUE         : TERMCOL_DESC_BG_BLUE,          \
            TERMCOL_MAGENTA      : TERMCOL_DESC_BG_MAGENTA,       \
            TERMCOL_CYAN         : TERMCOL_DESC_BG_CYAN,          \
            TERMCOL_WHITE        : TERMCOL_DESC_BG_WHITE,         \
          ])

/* these defines have the "%^" added here already, because they are
 * not handled by LIB_CNTL_SEQUENCES.
 */
#define TERMCOL_TECH              "TECH_"
#define TERMCOL_TECH_UNDERSCORE   "%^" TERMCOL_TECH TERMCOL_UNDERSCORE "%^"
#define TERMCOL_TECH_NORMAL       "%^" TERMCOL_TECH TERMCOL_NORMAL "%^"
#define TERMCOL_TECH_BLACK        "%^" TERMCOL_TECH TERMCOL_BLACK "%^"
#define TERMCOL_TECH_RED          "%^" TERMCOL_TECH TERMCOL_RED "%^"
#define TERMCOL_TECH_GREEN        "%^" TERMCOL_TECH TERMCOL_GREEN "%^"
#define TERMCOL_TECH_YELLOW       "%^" TERMCOL_TECH TERMCOL_YELLOW "%^"
#define TERMCOL_TECH_BLUE         "%^" TERMCOL_TECH TERMCOL_BLUE "%^"
#define TERMCOL_TECH_MAGENTA      "%^" TERMCOL_TECH TERMCOL_MAGENTA "%^"
#define TERMCOL_TECH_CYAN         "%^" TERMCOL_TECH TERMCOL_CYAN "%^"
#define TERMCOL_TECH_WHITE        "%^" TERMCOL_TECH TERMCOL_WHITE "%^"
#define TERMCOL_TECH_BOLD         "%^" TERMCOL_TECH TERMCOL_BOLD "%^"
#define TERMCOL_TECH_BOLD_BLACK   "%^" TERMCOL_TECH TERMCOL_BOLD_BLACK "%^"
#define TERMCOL_TECH_BOLD_RED     "%^" TERMCOL_TECH TERMCOL_BOLD_RED "%^"
#define TERMCOL_TECH_BOLD_GREEN   "%^" TERMCOL_TECH TERMCOL_BOLD_GREEN "%^"
#define TERMCOL_TECH_BOLD_YELLOW  "%^" TERMCOL_TECH TERMCOL_BOLD_YELLOW "%^"
#define TERMCOL_TECH_BOLD_BLUE    "%^" TERMCOL_TECH TERMCOL_BOLD_BLUE "%^"
#define TERMCOL_TECH_BOLD_MAGENTA "%^" TERMCOL_TECH TERMCOL_BOLD_MAGENTA "%^"
#define TERMCOL_TECH_BOLD_CYAN    "%^" TERMCOL_TECH TERMCOL_BOLD_CYAN "%^"
#define TERMCOL_TECH_BOLD_WHITE   "%^" TERMCOL_TECH TERMCOL_BOLD_WHITE "%^"
#define TERMCOL_TECH_BG_BLACK     "%^" TERMCOL_TECH TERMCOL_BG_BLACK "%^"
#define TERMCOL_TECH_BG_RED       "%^" TERMCOL_TECH TERMCOL_BG_RED "%^"
#define TERMCOL_TECH_BG_GREEN     "%^" TERMCOL_TECH TERMCOL_BG_GREEN "%^"
#define TERMCOL_TECH_BG_YELLOW    "%^" TERMCOL_TECH TERMCOL_BG_YELLOW "%^"
#define TERMCOL_TECH_BG_BLUE      "%^" TERMCOL_TECH TERMCOL_BG_BLUE "%^"
#define TERMCOL_TECH_BG_MAGENTA   "%^" TERMCOL_TECH TERMCOL_BG_MAGENTA "%^"
#define TERMCOL_TECH_BG_CYAN      "%^" TERMCOL_TECH TERMCOL_BG_CYAN "%^"
#define TERMCOL_TECH_BG_WHITE     "%^" TERMCOL_TECH TERMCOL_BG_WHITE "%^"

#define TERMCOL2TECH_TERMCOL ([ \
            TERMCOL_NORMAL       : TERMCOL_TECH_NORMAL,           \
            TERMCOL_BLACK        : TERMCOL_TECH_BLACK,            \
            TERMCOL_RED          : TERMCOL_TECH_RED,              \
            TERMCOL_GREEN        : TERMCOL_TECH_GREEN,            \
            TERMCOL_YELLOW       : TERMCOL_TECH_YELLOW,           \
            TERMCOL_BLUE         : TERMCOL_TECH_BLUE,             \
            TERMCOL_MAGENTA      : TERMCOL_TECH_MAGENTA,          \
            TERMCOL_CYAN         : TERMCOL_TECH_CYAN,             \
            TERMCOL_WHITE        : TERMCOL_TECH_WHITE,            \
            TERMCOL_BOLD         : TERMCOL_TECH_BOLD,             \
            TERMCOL_BOLD_BLACK   : TERMCOL_TECH_BOLD_BLACK,       \
            TERMCOL_BOLD_RED     : TERMCOL_TECH_BOLD_RED,         \
            TERMCOL_BOLD_GREEN   : TERMCOL_TECH_BOLD_GREEN,       \
            TERMCOL_BOLD_YELLOW  : TERMCOL_TECH_BOLD_YELLOW,      \
            TERMCOL_BOLD_BLUE    : TERMCOL_TECH_BOLD_BLUE,        \
            TERMCOL_BOLD_MAGENTA : TERMCOL_TECH_BOLD_MAGENTA,     \
            TERMCOL_BOLD_CYAN    : TERMCOL_TECH_BOLD_CYAN,        \
            TERMCOL_BOLD_WHITE   : TERMCOL_TECH_BOLD_WHITE,       \
          ])

#define TERMCOL2TECH_BG_TERMCOL ([ \
            TERMCOL_BLACK        : TERMCOL_TECH_BG_BLACK,         \
            TERMCOL_RED          : TERMCOL_TECH_BG_RED,           \
            TERMCOL_GREEN        : TERMCOL_TECH_BG_GREEN,         \
            TERMCOL_YELLOW       : TERMCOL_TECH_BG_YELLOW,        \
            TERMCOL_BLUE         : TERMCOL_TECH_BG_BLUE,          \
            TERMCOL_MAGENTA      : TERMCOL_TECH_BG_MAGENTA,       \
            TERMCOL_CYAN         : TERMCOL_TECH_BG_CYAN,          \
            TERMCOL_WHITE        : TERMCOL_TECH_BG_WHITE,         \
          ])

#define TERMCOL2DESC ([ \
            TERMCOL_NORMAL       : "default",               \
            TERMCOL_BLACK        : "black",                 \
            TERMCOL_RED          : "red",                   \
            TERMCOL_GREEN        : "green",                 \
            TERMCOL_YELLOW       : "yellow",                \
            TERMCOL_BLUE         : "blue",                  \
            TERMCOL_MAGENTA      : "magenta",               \
            TERMCOL_CYAN         : "cyan",                  \
            TERMCOL_WHITE        : "white",                 \
            TERMCOL_BOLD         : "bold default",          \
            TERMCOL_BOLD_BLACK   : "bold black",            \
            TERMCOL_BOLD_RED     : "bold red",              \
            TERMCOL_BOLD_GREEN   : "bold green",            \
            TERMCOL_BOLD_YELLOW  : "bold yellow",           \
            TERMCOL_BOLD_BLUE    : "bold blue",             \
            TERMCOL_BOLD_MAGENTA : "bold magenta",          \
            TERMCOL_BOLD_CYAN    : "bold cyan",             \
            TERMCOL_BOLD_WHITE   : "bold white",            \
          ])


#define DESC2TERMCOL ([ \
            "default"           : TERMCOL_NORMAL,           \
            "black"             : TERMCOL_BLACK,            \
            "red"               : TERMCOL_RED,              \
            "green"             : TERMCOL_GREEN,            \
            "yellow"            : TERMCOL_YELLOW,           \
            "blue"              : TERMCOL_BLUE,             \
            "magenta"           : TERMCOL_MAGENTA,          \
            "cyan"              : TERMCOL_CYAN,             \
            "white"             : TERMCOL_WHITE,            \
            "bold default"      : TERMCOL_BOLD,             \
            "bold black"        : TERMCOL_BOLD_BLACK,       \
            "bold red"          : TERMCOL_BOLD_RED,         \
            "bold green"        : TERMCOL_BOLD_GREEN,       \
            "bold yellow"       : TERMCOL_BOLD_YELLOW,      \
            "bold blue"         : TERMCOL_BOLD_BLUE,        \
            "bold magenta"      : TERMCOL_BOLD_MAGENTA,     \
            "bold cyan"         : TERMCOL_BOLD_CYAN,        \
            "bold white"        : TERMCOL_BOLD_WHITE,       \
          ])


/*
 *
 * These defines are for message() like
 *   send_message(({ M_CNTL_SEQ, TERMCOL_SHOUT,
 *                   "Death shouts: COME TO ME, I'M WAITING!",
 *                   M_CNTL_SEQ, TERMCOL_NORMAL }));
 */

/*
 * for services:
 */

#define TERMCOL_TELL             "TELL"
#define TERMCOL_SHOUT            "SHOUT"
#define TERMCOL_CHANNEL          "CHANNEL"
#define TERMCOL_SAY              "SAY"
#define TERMCOL_WHISPER          "WHISPER"
#define TERMCOL_FEELING          "FEELING"
#define TERMCOL_REMOTE_FEELING   "REMOTE_FEELING"
#define TERMCOL_REMOTE_CHANNEL   "REMOTE_CHANNEL"
#define TERMCOL_EMOTE            "EMOTE"

#define TERMCOL_SERVICES  ([ \
          TERMCOL_TELL           : "tell",               \
          TERMCOL_SHOUT          : "shout",              \
          TERMCOL_CHANNEL        : "channel",            \
          TERMCOL_SAY            : "say",                \
          TERMCOL_WHISPER        : "whisper",            \
          TERMCOL_FEELING        : "feeling",            \
          TERMCOL_REMOTE_FEELING : "remote feeling",     \
          TERMCOL_REMOTE_CHANNEL : "remote channel",     \
          TERMCOL_EMOTE          : "emote",              \
        ])

/*
 * for descriptions:
 */

#define TERMCOL_NPC              "NPC"
#define TERMCOL_PLAYER           "PLAYER"
#define TERMCOL_EXIT             "EXIT"
#define TERMCOL_ENEMY            "ENEMY"
#define TERMCOL_LIVING           "LIVING"

/*
 * The TERMCOL_LIVING resp. TERMCOL_DESC_LIVING defines should be used in all
 * messages where the kind of living is not known; it will be evaluated
 * to TERMCOL_NPC, TERMCOL_PLAYER or TERMCOL_ENEMY according to the relation
 * between the described living and the receiver of the message.
 * Therefore they MUST NOT be added to the TERMCOL_DESCRIPTIONS and
 * TERMCOL_DESC_DESCRIPTIONS arrays resp. mappings below.
 */

#define TERMCOL_DESCRIPTIONS  ([ \
          TERMCOL_NPC            : "npc",                \
          TERMCOL_PLAYER         : "player",             \
          TERMCOL_EXIT           : "exit",               \
          TERMCOL_ENEMY          : "enemy",               \
        ])

#define TERMCOL_DESC_NPC         "%^" TERMCOL_DESC TERMCOL_NPC    "%^"
#define TERMCOL_DESC_PLAYER      "%^" TERMCOL_DESC TERMCOL_PLAYER "%^"
#define TERMCOL_DESC_EXIT        "%^" TERMCOL_DESC TERMCOL_EXIT   "%^"
#define TERMCOL_DESC_ENEMY       "%^" TERMCOL_DESC TERMCOL_ENEMY  "%^"
#define TERMCOL_DESC_LIVING      "%^" TERMCOL_DESC TERMCOL_LIVING "%^"

#define TERMCOL_DESC_DESCRIPTIONS  ({ TERMCOL_DESC TERMCOL_NPC,         \
                                     TERMCOL_DESC TERMCOL_PLAYER,      \
                                     TERMCOL_DESC TERMCOL_EXIT,        \
                                     TERMCOL_DESC TERMCOL_ENEMY,       \
                                  })

#define TERMCOL_DESCRIPTIONS2DESC_DESCRIPTIONS  ([ \
          TERMCOL_NPC            : TERMCOL_DESC_NPC,      \
          TERMCOL_PLAYER         : TERMCOL_DESC_PLAYER,   \
          TERMCOL_EXIT           : TERMCOL_DESC_EXIT,     \
          TERMCOL_ENEMY          : TERMCOL_DESC_ENEMY,    \
        ])

/*
 * technical stuff:
 */

#define TERMCOL_INFO             "INFO"
#define TERMCOL_WARNING          "WARNING"
#define TERMCOL_COMBAT           "COMBAT"
#define TERMCOL_MAGIC            "MAGIC"

#define TERMCOL_TECHNICAL  ([ \
          TERMCOL_INFO           : "info",               \
          TERMCOL_WARNING        : "warning",            \
          TERMCOL_COMBAT         : "combat",             \
          TERMCOL_MAGIC          : "magic",              \
        ])

#define TERMCOL_TECH_INFO        "%^" TERMCOL_TECH TERMCOL_INFO    "%^"
#define TERMCOL_TECH_WARNING     "%^" TERMCOL_TECH TERMCOL_WARNING "%^"
#define TERMCOL_TECH_COMBAT      "%^" TERMCOL_TECH TERMCOL_COMBAT  "%^"
#define TERMCOL_TECH_MAGIC       "%^" TERMCOL_TECH TERMCOL_MAGIC   "%^"

#define TERMCOL_TECH_DESCRIPTIONS  ({ TERMCOL_TECH TERMCOL_INFO,        \
                                     TERMCOL_TECH TERMCOL_WARNING,     \
                                     TERMCOL_TECH TERMCOL_COMBAT,      \
                                     TERMCOL_TECH TERMCOL_MAGIC,       \
                                  })

#define TERMCOL_TECHNICAL2TECH_DESCRIPTIONS  ([ \
          TERMCOL_INFO           : TERMCOL_TECH_INFO,     \
          TERMCOL_WARNING        : TERMCOL_TECH_WARNING,  \
          TERMCOL_COMBAT         : TERMCOL_TECH_COMBAT,   \
          TERMCOL_MAGIC          : TERMCOL_TECH_MAGIC,    \
        ])

/*
 * possible settings
 */

#define TERMCOL_DEFAULT_SETTINGS  ({ "lit_bg", "dark_bg" })


/*
 *
 * The TERMCOL_MODELS section includes the available control sequences for
 * each separate color model (for the tokens of TERMCOL_APPLICATIONS).
 */

#define TERMCOL_MODELS ([ \
          ANSI : ([ TERMCOL_UNDERSCORE   : ANSI_UNDERSCORE,    \
                    TERMCOL_NORMAL       : ANSI_NORMAL,        \
                    TERMCOL_BLACK        : ANSI_BLACK,         \
                    TERMCOL_RED          : ANSI_RED,           \
                    TERMCOL_GREEN        : ANSI_GREEN,         \
                    TERMCOL_YELLOW       : ANSI_YELLOW,        \
                    TERMCOL_BLUE         : ANSI_BLUE,          \
                    TERMCOL_MAGENTA      : ANSI_MAGENTA,       \
                    TERMCOL_CYAN         : ANSI_CYAN,          \
                    TERMCOL_WHITE        : ANSI_WHITE,         \
                    TERMCOL_BOLD         : ANSI_BOLD,          \
                    TERMCOL_BOLD_BLACK   : ANSI_BOLD_BLACK,    \
                    TERMCOL_BOLD_RED     : ANSI_BOLD_RED,      \
                    TERMCOL_BOLD_GREEN   : ANSI_BOLD_GREEN,    \
                    TERMCOL_BOLD_YELLOW  : ANSI_BOLD_YELLOW,   \
                    TERMCOL_BOLD_BLUE    : ANSI_BOLD_BLUE,     \
                    TERMCOL_BOLD_MAGENTA : ANSI_BOLD_MAGENTA,  \
                    TERMCOL_BOLD_CYAN    : ANSI_BOLD_CYAN,     \
                    TERMCOL_BOLD_WHITE   : ANSI_BOLD_WHITE,    \
                    TERMCOL_BG_BLACK     : ANSI_BG_BLACK,      \
                    TERMCOL_BG_RED       : ANSI_BG_RED,        \
                    TERMCOL_BG_GREEN     : ANSI_BG_GREEN,      \
                    TERMCOL_BG_YELLOW    : ANSI_BG_YELLOW,     \
                    TERMCOL_BG_BLUE      : ANSI_BG_BLUE,       \
                    TERMCOL_BG_MAGENTA   : ANSI_BG_MAGENTA,    \
                    TERMCOL_BG_CYAN      : ANSI_BG_CYAN,       \
                    TERMCOL_BG_WHITE     : ANSI_BG_WHITE,      \
                 ]), \
          ])

/*
 * TERMCOL_DESC_MODELS holds all colors that can be used for descriptions
 */
#define TERMCOL_DESC_MODELS ([ \
          ANSI : ([ TERMCOL_DESC TERMCOL_UNDERSCORE   : ANSI_UNDERSCORE,    \
                    TERMCOL_DESC TERMCOL_NORMAL       : ANSI_NORMAL,        \
                    TERMCOL_DESC TERMCOL_BLACK        : ANSI_BLACK,         \
                    TERMCOL_DESC TERMCOL_RED          : ANSI_RED,           \
                    TERMCOL_DESC TERMCOL_GREEN        : ANSI_GREEN,         \
                    TERMCOL_DESC TERMCOL_YELLOW       : ANSI_YELLOW,        \
                    TERMCOL_DESC TERMCOL_BLUE         : ANSI_BLUE,          \
                    TERMCOL_DESC TERMCOL_MAGENTA      : ANSI_MAGENTA,       \
                    TERMCOL_DESC TERMCOL_CYAN         : ANSI_CYAN,          \
                    TERMCOL_DESC TERMCOL_WHITE        : ANSI_WHITE,         \
                    TERMCOL_DESC TERMCOL_BOLD         : ANSI_BOLD,          \
                    TERMCOL_DESC TERMCOL_BOLD_BLACK   : ANSI_BOLD_BLACK,    \
                    TERMCOL_DESC TERMCOL_BOLD_RED     : ANSI_BOLD_RED,      \
                    TERMCOL_DESC TERMCOL_BOLD_GREEN   : ANSI_BOLD_GREEN,    \
                    TERMCOL_DESC TERMCOL_BOLD_YELLOW  : ANSI_BOLD_YELLOW,   \
                    TERMCOL_DESC TERMCOL_BOLD_BLUE    : ANSI_BOLD_BLUE,     \
                    TERMCOL_DESC TERMCOL_BOLD_MAGENTA : ANSI_BOLD_MAGENTA,  \
                    TERMCOL_DESC TERMCOL_BOLD_CYAN    : ANSI_BOLD_CYAN,     \
                    TERMCOL_DESC TERMCOL_BOLD_WHITE   : ANSI_BOLD_WHITE,    \
                    TERMCOL_DESC TERMCOL_BG_BLACK     : ANSI_BG_BLACK,      \
                    TERMCOL_DESC TERMCOL_BG_RED       : ANSI_BG_RED,        \
                    TERMCOL_DESC TERMCOL_BG_GREEN     : ANSI_BG_GREEN,      \
                    TERMCOL_DESC TERMCOL_BG_YELLOW    : ANSI_BG_YELLOW,     \
                    TERMCOL_DESC TERMCOL_BG_BLUE      : ANSI_BG_BLUE,       \
                    TERMCOL_DESC TERMCOL_BG_MAGENTA   : ANSI_BG_MAGENTA,    \
                    TERMCOL_DESC TERMCOL_BG_CYAN      : ANSI_BG_CYAN,       \
                    TERMCOL_DESC TERMCOL_BG_WHITE     : ANSI_BG_WHITE,      \
                 ]), \
          ])

/*
 * TERMCOL_TECH_MODELS holds all colors that can be used for technical info
 */
#define TERMCOL_TECH_MODELS ([ \
          ANSI : ([ TERMCOL_TECH TERMCOL_UNDERSCORE   : ANSI_UNDERSCORE,    \
                    TERMCOL_TECH TERMCOL_NORMAL       : ANSI_NORMAL,        \
                    TERMCOL_TECH TERMCOL_BLACK        : ANSI_BLACK,         \
                    TERMCOL_TECH TERMCOL_RED          : ANSI_RED,           \
                    TERMCOL_TECH TERMCOL_GREEN        : ANSI_GREEN,         \
                    TERMCOL_TECH TERMCOL_YELLOW       : ANSI_YELLOW,        \
                    TERMCOL_TECH TERMCOL_BLUE         : ANSI_BLUE,          \
                    TERMCOL_TECH TERMCOL_MAGENTA      : ANSI_MAGENTA,       \
                    TERMCOL_TECH TERMCOL_CYAN         : ANSI_CYAN,          \
                    TERMCOL_TECH TERMCOL_WHITE        : ANSI_WHITE,         \
                    TERMCOL_TECH TERMCOL_BOLD         : ANSI_BOLD,          \
                    TERMCOL_TECH TERMCOL_BOLD_BLACK   : ANSI_BOLD_BLACK,    \
                    TERMCOL_TECH TERMCOL_BOLD_RED     : ANSI_BOLD_RED,      \
                    TERMCOL_TECH TERMCOL_BOLD_GREEN   : ANSI_BOLD_GREEN,    \
                    TERMCOL_TECH TERMCOL_BOLD_YELLOW  : ANSI_BOLD_YELLOW,   \
                    TERMCOL_TECH TERMCOL_BOLD_BLUE    : ANSI_BOLD_BLUE,     \
                    TERMCOL_TECH TERMCOL_BOLD_MAGENTA : ANSI_BOLD_MAGENTA,  \
                    TERMCOL_TECH TERMCOL_BOLD_CYAN    : ANSI_BOLD_CYAN,     \
                    TERMCOL_TECH TERMCOL_BOLD_WHITE   : ANSI_BOLD_WHITE,    \
                    TERMCOL_TECH TERMCOL_BG_BLACK     : ANSI_BG_BLACK,      \
                    TERMCOL_TECH TERMCOL_BG_RED       : ANSI_BG_RED,        \
                    TERMCOL_TECH TERMCOL_BG_GREEN     : ANSI_BG_GREEN,      \
                    TERMCOL_TECH TERMCOL_BG_YELLOW    : ANSI_BG_YELLOW,     \
                    TERMCOL_TECH TERMCOL_BG_BLUE      : ANSI_BG_BLUE,       \
                    TERMCOL_TECH TERMCOL_BG_MAGENTA   : ANSI_BG_MAGENTA,    \
                    TERMCOL_TECH TERMCOL_BG_CYAN      : ANSI_BG_CYAN,       \
                    TERMCOL_TECH TERMCOL_BG_WHITE     : ANSI_BG_WHITE,      \
                 ]), \
          ])


/*
 *
 * The MODEL2TERMCOL resp. TERMCOL2MODEL section defines the color translation
 * from standard model description (TERMCOL_*) to a special model description
 * (e.g. ANSI_*) and vice versa.
 *
 * In both mappings only _colors_ including the 'default' color are allowed,
 * this mapping is needed to get the available list of colors for every
 * model.
 */

#define MODEL2TERMCOL ([ \
          ANSI: \
                ([ ANSI_NORMAL         : TERMCOL_NORMAL,       \
                   ANSI_BLACK          : TERMCOL_BLACK,        \
                   ANSI_RED            : TERMCOL_RED,          \
                   ANSI_GREEN          : TERMCOL_GREEN,        \
                   ANSI_YELLOW         : TERMCOL_YELLOW,       \
                   ANSI_BLUE           : TERMCOL_BLUE,         \
                   ANSI_MAGENTA        : TERMCOL_MAGENTA,      \
                   ANSI_CYAN           : TERMCOL_CYAN,         \
                   ANSI_WHITE          : TERMCOL_WHITE,        \
                   ANSI_BOLD           : TERMCOL_BOLD,         \
                   ANSI_BOLD_BLACK     : TERMCOL_BOLD_BLACK,   \
                   ANSI_BOLD_RED       : TERMCOL_BOLD_RED,     \
                   ANSI_BOLD_GREEN     : TERMCOL_BOLD_GREEN,   \
                   ANSI_BOLD_YELLOW    : TERMCOL_BOLD_YELLOW,  \
                   ANSI_BOLD_BLUE      : TERMCOL_BOLD_BLUE,    \
                   ANSI_BOLD_MAGENTA   : TERMCOL_BOLD_MAGENTA, \
                   ANSI_BOLD_CYAN      : TERMCOL_BOLD_CYAN,    \
                   ANSI_BOLD_WHITE     : TERMCOL_BOLD_WHITE,   \
                ]), \
          ])


#define TERMCOL2MODEL ([ \
          ANSI: \
                ([ TERMCOL_NORMAL       : ANSI_NORMAL,         \
                   TERMCOL_BLACK        : ANSI_BLACK,          \
                   TERMCOL_RED          : ANSI_RED,            \
                   TERMCOL_GREEN        : ANSI_GREEN,          \
                   TERMCOL_YELLOW       : ANSI_YELLOW,         \
                   TERMCOL_BLUE         : ANSI_BLUE,           \
                   TERMCOL_MAGENTA      : ANSI_MAGENTA,        \
                   TERMCOL_CYAN         : ANSI_CYAN,           \
                   TERMCOL_WHITE        : ANSI_WHITE,          \
                   TERMCOL_BOLD         : ANSI_BOLD,           \
                   TERMCOL_BOLD_BLACK   : ANSI_BOLD_BLACK,     \
                   TERMCOL_BOLD_RED     : ANSI_BOLD_RED,       \
                   TERMCOL_BOLD_GREEN   : ANSI_BOLD_GREEN,     \
                   TERMCOL_BOLD_YELLOW  : ANSI_BOLD_YELLOW,    \
                   TERMCOL_BOLD_BLUE    : ANSI_BOLD_BLUE,      \
                   TERMCOL_BOLD_MAGENTA : ANSI_BOLD_MAGENTA,   \
                   TERMCOL_BOLD_CYAN    : ANSI_BOLD_CYAN,      \
                   TERMCOL_BOLD_WHITE   : ANSI_BOLD_WHITE,     \
                ]), \
          ])

#define TERMCOL_CS_CLEAR_RIGHT          "%^TERMCOL_CS_CLEAR_RIGHT%^"

#define TERMCOL_CS_SEQUENCES ([                                 \
  TERMCOL_CS_CLEAR_RIGHT      : CS_CLEAR_RIGHT,                 \
  ])

#endif  // _sys_color_h

