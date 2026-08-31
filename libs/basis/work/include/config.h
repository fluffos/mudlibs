// file:    /include/config.h
// mudlib:  base

// created: 1992/07/28

/*
  $Locker:  $

  $Source: /usr/local/mud/libs/basis/include/RCS/config.h,v $
  $Revision: 1.4 $
  $Author: garnett $
  $Date: 92/10/11 23:54:53 $
  $State: Exp $

  $Log:	config.h,v $
 * Revision 1.4  92/10/11  23:54:53  garnett
 * defined BASIS
 * 
 * Revision 1.3  92/10/02  03:44:56  garnett
 * added REPORT
 * 
 * Revision 1.2  92/09/29  03:16:59  garnett
 * added MASTER_FILE etc
 * 
 * Revision 1.1  92/09/24  18:59:06  garnett
 * Initial revision
 * 
*/

#ifndef _CONFIG_H
#define _CONFIG_H

#define BASIS

#include "uid.h"

// tells the /adm/daemon/cmwhod.c daemon to send MUDWHO data.  Leave
// uncommented for now until you've read the comments in the cmwhod.c
// file and know what you want to do with it.
#undef MUDWHO

#define TRUE 1
#define FALSE 0

// Old MudOS drivers injected MUDOS_VERSION/MUDOS_ARCH as compile-time
// predefines; this driver (FluffOS) predefines the equivalents as
// __VERSION__/__ARCH__ instead. Bridge the naming so
// adm/obj/simul_efun/backcompat.lpc still compiles.
#define MUDOS_VERSION __VERSION__
#define MUDOS_ARCH __ARCH__

#define THIS_MUD MUD_NAME
#define CORE "/std/core"
#define MOVE "/std/object/move"
#define BASE "/std/object/base"
#define SECURE_BASE "/std/object/secure"
#define LIVING "/std/living"

#define OBJECT BASE

#define ACCESS_FILE "/adm/etc/access"
#define GROUP_FILE "/adm/etc/groups"

#define ADDRESSES "/adm/etc/addresses"
#define SERVICES  "/adm/etc/services"
#define MUD_SERVICES  "/adm/etc/mud_services"
#define MUD_ADDRESSES "/adm/etc/mud_addresses"

#define NEW_MASTER_OB "/bin/admin/objects/new_master"
#define EMPTY_OB "/adm/obj/empty"
// use MASTER_OB instead of GROUP_OB since GROUP_OB is inherited by MASTER_OB
#define MASTER_OB master()
#define MASTER_FILE "/adm/obj/master"
#define SIMUL_EFUN_OB "/adm/obj/simul_efun"
#define OVERRIDES "/adm/obj/simul_efun/overrides"
#define LOGIN_OB "/adm/obj/login"
#define SU_OB    "/bin/maker/system/su"
#define INTERACTIVE_OB "/std/i"
#define USER_OB "/std/user"
#define MAKER_OB "/std/maker"
#define ADMIN_OB "/std/admin"
#define VOID_OB "/room/void"
#define START_OB "/room/start"

// inherits
#define ALIAS "/std/i/alias"
#define SAVE  "/std/save"
#define ROOM "/std/room"
#define CONTAINER "/std/container"
#define LIVING "/std/living"
#define REPORT "/std/bin/report"

#define CALLER(x) (getuid(previous_object()) == (x))

// todo: get rid of VOID (used by master.c etc.)
#define VOID VOID_OB
#define BIN "/adm/std/security/bin"
#define DAEMON "/adm/std/security/daemon"

// miscellaneous directories
//
#define DATA_DIR "/data"
#define HOME_DIRS "/u"
#define USER_DIR "/data/users"
#define INTERACTIVES_DIR  "/obj/i"
#define CONFIG_DIR "/adm/etc"
#define SECURE_DIR "/adm/obj"
#define LOG_DIR "/log"
#define NEWS_DIR "/adm/news"
#define TMP_DIR "/tmp"
#define HELP_DIR "/doc/help"
#define WIZH_DIR "/doc/wizhelp"
#define MAIL_DIR "/data/mail"

// command directories
//
#define DEV_CMDS "/bin/dev"
#define USER_CMDS "/bin/user"
#define ADMIN_CMDS "/bin/admin"

// miscellaneous
//
#define STANDARD_DOMAIN "/d/basis"

#endif /* _CONFIG_H */
