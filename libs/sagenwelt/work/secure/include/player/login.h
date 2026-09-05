/// @file login.h
/// @brief macros needed during login
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2016-01-27

#ifndef __SEC_PLAYER_LOGIN_H
#define __SEC_PLAYER_LOGIN_H

#include <message.h>                            // needed for communication
#include <mud_info.h>                           // needed for mud_info_d requests

#define LOGIN_TIMEOUT   180                     ///< timeout in s (3min)

/// all prompts used by login
#define LOGIN_PROMPT    "User name/email : "
#define PWD_PROMPT      "Password        : "
#define NPWD_PROMPT     "New password    : "
#define CNPWD_PROMPT    "Confirm password: "

// Please don't change this one
#define MSSP_USER       "___MSSP-REQUEST___"    ///< login name to get MSSP-info via login prompt

#endif  // __SEC_PLAYER_LOGIN_H
