// mudlib: Fading Summer
// file:   objects.h
// author: Lontau
// date:   20-6-2001

/* Synopsis: This file defines the path names referenced throughout
   the mudlib.
*/

#ifndef _H_PATHS_
#define _H_PATHS_

#define CLONE_DIR          "/clonable"
#define COMMAND_DIR        "/command"
#define DATA_DIR           "/data"
#define HELP_DIR           "/doc"
#define HOME_DIR           "/home"
#define LOG_DIR            "/log"
#define INHERIT_DIR        "/parents"
#define SYSTEM_DIR         "/system"
#define TMP_DIR            "/tmp"

#define DAEMON_DIR         SYSTEM_DIR+"/daemons"
#define SIMUL_DIR          SYSTEM_DIR+"/simul_efun"
#define CONFIG_DIR         SYSTEM_DIR+"/etc"
#define VOID_DIR           SYSTEM_DIR+"/void"
#define BASE_DIR           INHERIT_DIR+"/base"

#define USER_DATA_DIR      DATA_DIR+"/user"
#define DAEMON_DATA_DIR    DATA_DIR+"/daemons"
#define MAILER_DATA_DIR    DATA_DIR+"/mail"

#endif
