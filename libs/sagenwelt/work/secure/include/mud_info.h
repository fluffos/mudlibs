/// @file mud_info.h
/// @brief macros concerning requests/answers from the mud_info daemon
/// @author Gwenhwyvar
/// @version 0.0.0
/// @date 2016-01-28

#ifndef __SEC_MUD_INFO_H
#define __SEC_MUD_INFO_H

#include "std_paths.h"

#define MUD_INFO_SAVE     __SAVE_FILE(PRIV_SAVE_DIR "mud_info")

// mapping player_info
#define MI_PI_CRED      0       ///< credentials (uid:gid) of the player    (string)
#define MI_PI_INVALID   1       ///< supplied name invalid                  (string)
#define MI_PI_PWDC      2       ///< counter how many tries for passwd left (int)
#define MI_PI_PWD       3       ///< crypted passwd                         (string)
#define MI_PI_REG       4       ///< registered email supplied              (int)
#define MI_PI_NAME      5       ///< name for new players                   (string)
#define MI_PI_GENDER    6       ///< gender for new players                 (string)

// email handling
#define MI_EMAIL_INVALID    "@inv@"
#define MI_EMAIL_INVALID    "@reg@"

// password handling
#define MI_PWD_INVALID      "@inv@"
#define MI_PWD_TOO_SHORT    "@sho@"

#endif  // __SEC_MUD_INFO_H
