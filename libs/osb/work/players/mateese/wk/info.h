#ifndef _SECURE_INFO_
#define _SECURE_INFO_ 1

/*--------------------------------------------------------------------------
 * /sys/secure/info.h -- Definitions for the /secure/info.c
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <secure/config.h>

// Savefile pathnames
#define I_USERPATH   SECURESAVEPATH "players/"
#define I_INFOPATH   SECURESAVEPATH "info/"

// 'Wizlevel' of interactive users.
#define LVL_PLAYER   0
#define LVL_ANCIENT  1  // "Retired player"
#define LVL_LEARNER  2  // "Apprentice" is a better word
#define LVL_WIZARD   3

// Type of a info database entry:
#define ITYPE_NONE    0  // Non-existent entry
#define ITYPE_USER    1  // Entry describes an existing user (poss. banished).
#define ITYPE_GROUP   2  // Entry describes a user group.
#define ITYPE_RESERV  3  // Name of this entry is reserved (banished).

// The fields of the <logins> array.
#define ILOGIN_TSUCC   0  // time() of the last successfull login.
#define ILOGIN_ISUCC   1  // hostip of the last successfull login.
#define ILOGIN_NSUCC   2  // hostname of the last successfull login.
#define ILOGIN_ATTEMPT 3  // Number of unsuccessful attempts since last
                          // successfull login. If this is 0, the following
                          // fields are 0.
#define ILOGIN_TLAST   4  // time() of last attempt
#define ILOGIN_ILAST   5  // hostip of the last attemp.
#define ILOGIN_NLAST   6  // hostname of the last attempt.
#define ILOGIN_SIZE    7  // Number of fields in the array.

// Codes of the resume entries
#define IRESUME_CREATE  0  // Creation
#define IRESUME_LEVEL   1  // Level change
#define IRESUME_BANISH  2  // Change of banish state
#define IRESUME_MUMMY   3  // Change of mummy state
#define IRESUME_FREEZE  4  // Change of freeze state
#define IRESUME_JOIN    5  // Group join
#define IRESUME_LEAVE   6  // Leaving of group.

// Reserved usergroups.
#define IGROUP_BANISHED  "banished"  // All banished users
#define IGROUP_BANISH    "banish-"   // All banished non-user names
  // This one is extended with one letter, a-z
#define IGROUP_FROZEN    "frozen"    // All frozen users
#define IGROUP_WIZARDS   "wizards"   // All known wizards
#define IGROUP_GROUPS    "groups"    // All known groups

#endif /* _SECURE_INFO_ */
