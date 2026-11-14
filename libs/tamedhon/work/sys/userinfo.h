// SilberLand MUDlib
//
// sys/userinfo.h -- secure user info defines
//
// $Date: 1997/03/31 13:57:58 $
/* $Revision: 1.1 $
 * $Log: userinfo.h,v $
 * Revision 1.1  1997/03/31 13:57:58  Woody
 * prepared for revision control
 *
 */

#ifndef __USERINFO_H__
#define __USERINFO_H__

/*
 * userinfo: what each field of /secure/PASSWD is
 */

/* password (encrypted) */
#define USER_PASSWORD 0

/* wizard level (or programming level) (0 for simple users) */
#define USER_LEVEL 1

/* domain (if any) master == *domainname */
#define USER_DOMAIN 2

/* player object to be loaded by /secure/login */
#define USER_OBJECT 3

/* Date and time of first login */
#define USER_CREATION_DATE 4

/* Time userinfo has been touched last */
#define USER_TOUCH 5

#endif
