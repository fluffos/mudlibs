/*--------------------------------------------------------------------------
 * /sys/msgclass.h -- Definition of the message classes
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  98/07/05 [Mica] added MMSG_DISCARD
 */

#ifndef _MSGCLASS_H_
#define _MSGCLASS_H_

/*
 *--------------------------------------------------------------------------
 * Message classes
 *  valid numbers are 0 to 1023, the other bits are reserved for message-
 *  modifiers
 *--------------------------------------------------------------------------
 * CMSG_CHANNEL : ({ (string)channel, (string)name, (string)msg, (int)type })
 *                type == 1 : emote, anything else is tell
 */

/* NOTE: If you redefine message classes and/or add them modify the array
 *       below. Array needs to be in order that it is possible to query the
 *       string by using STRING_CMSG[class]
 */

#define STRING_CMSG ({ "generic", "tell", "say", "emote", "shout", "channel", "broadcast", "combat", "combat_self", "combat_others", "room", "room_short", "room_long", "room_exit", "status", "fun", "ask", "error" })
		     

#define CMSG_GENERIC                     0 

#define CMSG_TELL                        1
#define CMSG_SAY                         2
#define CMSG_EMOTE                       3
#define CMSG_SHOUT                       4
#define CMSG_CHANNEL                     5
#define CMSG_BROADCAST                   6

#define CMSG_COMBAT                      7
#define CMSG_COMBAT_SELF                 8
#define CMSG_COMBAT_OTHERS               9

#define CMSG_ROOM                       10
#define CMSG_ROOM_SHORT                 11
#define CMSG_ROOM_LONG                  12
#define CMSG_ROOM_EXIT                  13

#define CMSG_STATUS                     14
#define CMSG_FUN                        15
#define CMSG_ASK                        16

#define CMSG_ERROR                      17

#define CMSG_USER                       500

/*
 *--------------------------------------------------------------------------
 * Message modifiers
 *  There define additional flags for the messages and need to be |'ed with
 *  the type of the message, valid are 2^(10..30)
 *--------------------------------------------------------------------------
 *
 * Living specific modifiers:
 *  - all messages can be either a string or an array, if an array is given,
 *    livings who do not match the modifier, for example cannot see, get the
 *    second string from the array. If only a string is given and the living
 *    does not match, it will receive nothing.
 * 
 *  MMSG_SEE          : living needs to be able to see
 *  MMSG_HEAR         : living needs to be able to hear
 *  MMSG_SMELL        : living needs to be able to smell
 *
 * Generic modifiers:
 *
 *  MMSG_DIRECT       : do not stack this message if the user is editing etc.
 *  MMSG_NOWRAP       : do not auto-wordwrap this message
 *  MMSG_MORE         : the message is buffered and mored afterwards
 *
 *  MMSG_NOREPLY      : if this modifier is set, do not reply with another
 *                      message to prevent infinite looping
 *  MMSG_IDENT_TRANS  : the message is identically translated by terminal_
 *                      colour instead of expanding the color-tokens
 *
 *  MMSG_DISCARD      : if set the message will be discarded by the players
 *                      message handler. This makes sense if set for example
 *                      by filter_message of CMSG_ROOM
 * Specials
 * 
 *  MMSG_MASKOUT      : class &= MMSG_MASKOUT; strips the modifiers
 */

#define MMSG_MASKOUT                 0x003ff

#define MMSG_SEE                     0x00400
#define MMSG_HEAR                    0x00800
#define MMSG_SMELL                   0x01000

#define MMSG_DIRECT                  0x02000
#define MMSG_NOWRAP                  0x04000
#define MMSG_MORE                    0x08000

#define MMSG_NOREPLY                 0x10000
#define MMSG_IDENT_TRANS             0x20000

#define MMSG_DISCARD                 0x40000

#endif
