// SilberLand MUDlib
// 
// /secure/login_defs.h -- login handling definitions
//
// $Id: login_defs.h,v 1.2 2004/09/23 01:17:37 Woody Exp $
/*
 * $Log: login_defs.h,v $
 * Revision 1.2  2004/09/23 01:17:37  Woody
 * LOGIN_REGISTERED definiert
 *
 * Revision 1.1  2003/06/25 10:41:57  Crea
 * Initial revision
 *
 */

#ifndef __LOGIN_DEFS_H
#define __LOGIN_DEFS_H

// MAXPLAYERS ergibt sich aus MAX_PLAYERS in config.h, da man nicht direkt drankommt, doubledefine

#define MAXPLAYERS 150

// diverse defines

#define MAXWIZ 20
#define MAXARCH 5
#define MINLOCK_LVL 10
#define MAXLOCK_LVL 66
#define LOGIN_RESTRICTIONS "/secure/ARCH/login_restrictions"
#define LOGIN_RES_LOG "/ARCH/LOGIN_RESTRICTIONS"
#define DEFAULT_RESTRICTION_STRING "Diese IP wurde von den Admins gesperrt."

#define ACTIVATE "ACTV"
#define LOCKGAME "LOCK"
#define SITEBAN  "SBAN"
#define SETPLRS  "SPLR"

/* return values */

// > 0: OK
#define LOGIN_REGISTERED                2
#define LOGIN_OK                        1
// <= 0: ERROR
#define LOGIN_FALSE                     0
#define LOGIN_MAXIMUM_REACHED           -2
#define LOGIN_WRONG_MARK                -3
#define LOGIN_WIZARD_ONLINE             -4
#define LOGIN_ANOTHER_SECOND_ONLINE     -5

#endif /* __LOGIN_DEFS_H */

