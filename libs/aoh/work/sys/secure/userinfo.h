#ifndef _SECURE_USERINFO_
#define _SECURE_USERINFO_ 1

/*--------------------------------------------------------------------------
 * /sys/secure/userinfo.h -- Definition of the fields of the password entries.
 *
 * Copyright (C) 1997-1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

/* login name */
#define USER_NAME 0

/* password (encrypted) */
#define USER_PASSWORD 1

/* user level (see /sys/secure/wizlevels.h) */
#define USER_LEVEL 2

/* domain (if any) master == *domainname */
#define USER_DOMAIN 3

/* player object to be loaded by /secure/login */
#define USER_OBJECT 4

/* Player's age on last promotion */
#define USER_PROMOTION 5

/* Who promoted the player to learnership? */
#define USER_ELPROMO 6

/* For internal use of the master: time the userinfo was last touched */
#define USER_TOUCH 7

#define USER_8  8
#define USER_9  9

#endif /* _SECURE_USERINFO_ */
