/*--------------------------------------------------------------------------
 * /sys/channel.h -- Definition of the channel related things
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  07/02/98 [Mica] removed guild, assoc and domain channels, added
 *                  CHANNEL_FLAG_MASTERED
 */

#ifndef _CHANNEL_H_
#define _CHANNEL_H_

#define CHANNEL_FLAG_HLP        0x0001     
#define CHANNEL_FLAG_WIZ        0x0002
#define CHANNEL_FLAG_ADMIN      0x0004
#define CHANNEL_FLAG_RESTRICTED 0x0008
#define CHANNEL_FLAG_MASTERED   0x0010 

#define CHANNEL_FLAG_ANONYMOUS  0x1000
#define CHANNEL_FLAG_PERMANENT  0x2000
#define CHANNEL_FLAG_READONLY   0x4000

#define CHANNEL_TYPE_LOCAL      0
#define CHANNEL_TYPE_IMUD       1
#define CHANNEL_TYPE_IMUD3      2

#define CHANNEL_LISTENERS       0
#define CHANNEL_FLAGS           1
#define CHANNEL_TYPE            2
#define CHANNEL_EXTRA           3
#define CHANNEL_HISTORY         4
#define CHANNEL_CREATOR         5

#define CHANNEL_MAX             5

#define PERMCHANNEL_FLAGS       0
#define PERMCHANNEL_TYPE        1
#define PERMCHANNEL_EXTRA       2
#define PERMCHANNEL_CREATOR     3

#define PERMCHANNEL_MAX         3

#endif
