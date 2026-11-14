/* 
 * /p/daemon/housed/sys/housed.h - Deklarationen zum Seherhausverwalter 
 *
 * (c) 1998-2000 Mud Silberland - Adrian Holzwarth / Anatol@Silberland
 *
 *  1998 01 15 Revision 0.1   Redefinition REPFILE()
 *                          
 *  1999 02 22 Revision 0.2   PROPER_EXITS erweitert.
 *
 *  2000 11 18 Revision 0.3   Umzug nach /p/daemon/housed/sys,
 *                            Abspaltung von house.h,
 *
 *  2000 12 02 Revision 0.4   Rename auf housed_priv.h, Abspaltung von housed.h
 *
 */

#ifndef _HOUSED_PRIV_H_
#define _HOUSED_PRIV_H_

#include "housed.h"

// Etwas unsauber, da es von Seiten der variierenden Mudlib dann doch noch
// Nachkorrekturaufwand braucht, aber, nicht zuletzt wegen des Virtual
// Compilers, leider nicht anders moeglich: VC-Objekt, VC-Geruest und
// Filename brauchen die gleiche EUID.


#define HOUSED_LOG_DIR         "daemon/"

#define HOUSED_ERROR_LOG(x) log_file(HOUSED_LOG_DIR+"housed.err", \
    sprintf("%s: %s\n",(dtime(time())[5..]),x))
#define HOUSED_LOG(x) log_file(HOUSED_LOG_DIR+"housed.houses", \
    sprintf("%s: %s\n",(dtime(time())[5..]),x),50000,1)

#define HOUSED_KLOG(x) log_file(HOUSED_LOG_DIR+"housed.karton", \
    sprintf("%s: %s\n",(dtime(time())[5..]),x))
#define HOUSED_KELOG(x) log_file(HOUSED_LOG_DIR+"housed.karton.err", \
    sprintf("%s: %s\n",(dtime(time())[5..]),x))

#define H_ENV_FILE_NAME               0
#define H_ROOMS                       1
#define H_ENTER_DIRECTION             2

#define HS_ITEM       1  // ein bestimmtes Objekt (per AddItem())
#define HS_EXIT       2  // ein Ausgang (per AddExit())

#define HOUSE_NO_PERMISSION               -1
#define HOUSE_BAD_OWNER                   -2
#define HOUSE_ALREADY_EXISTING            -3
#define HOUSE_CLONED_ENVIRONMENT          -4
#define HOUSE_NOROOM_ENVIRONMENT          -5
#define HOUSE_BAD_ENTER_DIRECTION         -6 
#define HOUSE_HOUSE_COMPILE_FAIL          -7
#define HOUSE_NOT_EXISTING                -8
#define HOUSE_MUCH_TOO_MUCH_ROOMS         -9
#define HOUSE_BAD_ROOM_NUMBER             -10
#define HOUSE_BAD_ENVIRONMENT             -11
#define HOUSE_NODOMAIN_ENVIRONMENT        -12
#define HOUSE_FAIL_ENVIRONMENT_LOAD       -13
#define HOUSE_CONNECT_NO_DOMAIN_LORD      -14
#define HOUSE_DISCONNECT_NO_DOMAIN_LORD   -15
#define HOUSE_ALREADY_CONNECTED           -16
#define HOUSE_NOT_CONNECTED               -17
#define HOUSE_ENVIRONMENT_CANT_CONNECT    -18
#define HOUSE_HOUSE_EXIT_CLASH            -19

#endif
