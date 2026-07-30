//mxp.h
//wings@HC

#include <net/telnet_def.h>

#ifndef _MXP_H
#define _MXP_H 1

/* SIGNAL "Do you want to use MXP?" */
#define WILL_MXP_STR    IAC + WILL + TELOPT_MXP

/* SIGNAL "Yes,Do it!" */
#define DO_MXP_STR      IAC + DO + TELOPT_MXP

/* SINGAL "No,Don't Do it!" */
#define DONT_MXP_STR    IAC + DONT + TELOPT_MXP

/* Start MXP string */ 
#define START_MXP_STR   IAC + SB + TELOPT_MXP + IAC +SE

/* Esc character */
#define MXP_ESC         "\x1B"

#define MXPMODE(arg)    MXP_ESC + "[" + arg + "z"

/* only MXP commands in the "open" category are allowed. */
#define MXP_MODE_OPEN_LINE       MXPMODE("0")

/* all tags and commands in MXP are allowed within the line.  
 * When a newline is received from the MUD, the mode reverts
 * back to Open mode. */
#define MXP_MODE_SECURE_LINE     MXPMODE("1")

/* no MXP or HTML commands are allowed in the line.  The 
 * line is not parsed for any tags at all.  This is useful for
 * "verbatim" text output from the MUD.  When a newline is 
 * received from the MUD, the mode reverts back to Open mode.*/ 
#define MXP_MODE_LOCKED_LINE     MXPMODE("2")

/* close all open tags.  Set mode to Open.  Set text color and 
 * properties to default. */
#define MXP_MODE_RESET           MXPMODE("3")

/* set secure mode for the next tag only.  Must be immediately 
 * followed by a < character to start a tag.  Remember to set 
 * secure mode when closing the tag also.*/
#define MXP_MODE_TEMP_SECURE     MXPMODE("4")

/* set open mode.  Mode remains in effect until changed. */
#define MXP_MODE_LOCK_OPEN       MXPMODE("5")

/* set secure mode.  Mode remains in effect until changed. */
#define MXP_MODE_LOCK_SECURE     MXPMODE("6")

/* set locked mode.  Mode remains in effect until changed. */
#define MXP_MODE_LOCK_LOCKED     MXPMODE("7")

/* the line is parsed as the name of a room.  Only used by MUDs
 * that only support tagging for the automapper and do not 
 * support the full MXP tag set. */
#define MXP_MODE_ROOM_NAME       MXPMODE("10")

/* the line is parsed as a description of a room.  Only used by 
 * MUDs that only support tagging for the automapper and do not 
 * support the full MXP tag set. */
#define MXP_MODE_ROOM_DESC       MXPMODE("11")

/* the line is parsed as an exit line for a room.  Only used by
 * MUDs that only support tagging for the automapper and do not
 * support the full MXP tag set. */
#define MXP_MODE_ROOM_EXITS      MXPMODE("12")

/* This text is sent from the MUD at the beginning of a session 
 * to welcome the user to the MUD.  This text is not displayed 
 * by the client if a <RELOCATE> command has been used.  See the
 * section on Multi-Server MUDs for more details.  Same as the 
 * <WELCOME> MXP tag. */
#define MXP_MODE_WELCOME_TEXT    MXPMODE("19")

#endif/*_MXP_H*/
