/// @addtogroup privileged
/// @{
/// @file std_paths.h
/// @brief standard defines for priviledged objects
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2015-11-29

#ifndef __SEC_STD_PATHS_H
#define __SEC_STD_PATHS_H

#include "config.h"

// directories
#define LOG_DIR         "/var/log/"                         ///< logfiles
#define PRIV_SAVE_DIR   "/var/save/"                        ///< save-files of privileged objects
#define PLAYER_SAVE_DIR "/var/player_save/"                 ///< save-files of players
#define CFG_DIR         "/var/cfg/"                         ///< base config files
#define SECURE_DIR      "/secure/"                          ///< everything security relevant
#define DAEMON_DIR      SECURE_DIR "daemons/"               ///< daemons
#define SECURE_OBJ_DIR  SECURE_DIR "obj/"                   ///< security relevant std objects
#define SECURE_LIB_DIR  SECURE_DIR "lib/"                   ///< security relevant std library
#define SEFUN_DIR       SECURE_DIR "sefuns/"                ///< simul_efun-modules

#define __HOME_DIR(x)   "/players/" x[0..0] "/" x "/"       ///< create home directory name

// files
#define __SAVE_FILE(x)      ((x) + __SAVE_EXT)              ///< create save file name (uncompressed)
#define __SAVE_GZ_FILE(x)   ((x) + __SAVE_GZ_EXT)           ///< create save file name (compressed)
/// create save file name for given player
#define __PLAYER_SAVE(x)    __SAVE_FILE(PLAYER_SAVE_DIR  x[0..0] "/" x)

#define PRELOADS        CFG_DIR "PRELOADS"                  ///< file containing filenames to be preloaded

#define ACL_READ_CFG    CFG_DIR "Read.acl"                  ///< standard acl for read access
#define ACL_WRITE_CFG   CFG_DIR "Write.acl"                 ///< standard acl for write access
#define PRIVS_CFG       CFG_DIR "Privs.cfg"                 ///< default privs for all objects

#define WELCOME_MSG     CFG_DIR "welcome.txt"               ///< welcome message, displayed @ logon
#define MOTD            CFG_DIR "motd.txt"                  ///< message of the day, displayed @ logon

// library
#define P_INPUT         SECURE_LIB_DIR "player/inp_sys"     ///< module for input handling
#define P_MESSAGE       SECURE_LIB_DIR "player/messages"    ///< module for message handling
#define P_SHELL         SECURE_LIB_DIR "player/shell"       ///< module for shell handling

#define M_INPUT         SECURE_LIB_DIR "input"              ///< helper module for player input
#define M_MENU          SECURE_LIB_DIR "menu"               ///< standard module for menus

// objects
#define LOGIN_OB        SECURE_OBJ_DIR "player/login"       ///< login object
#define PLAYER_OB       SECURE_OBJ_DIR "player/player"      ///< player object

// daemons
#define SYSLOG_D        DAEMON_DIR "syslogd"                ///< logging daemon
#define MUD_INFO_D      DAEMON_DIR "mud_info"               ///< mud infos
#define TMP_D           DAEMON_DIR "tmpd"                   ///< handler for temporary files
#define MAIL_D          DAEMON_DIR "smtpd"                  ///< mailer daemon
#define NEWS_D          DAEMON_DIR "newsd"                  ///< news daemon
#define RACES_D         DAEMON_DIR "racesd"                 ///< handler for everything race related

#endif // __SEC_STD_PATHS_H

///  @}
