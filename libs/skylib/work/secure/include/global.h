#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <global/customise.h>    // Global Defines
#include <global/directories.h>  // Global Directories
#include <global/handlers.h>     // Global Handlers
#include <global/shops.h>        // Global Shops
#include <global/npcs.h>         // Global Npcs
#include <global/objects.h>      // Global Objects
#include <global/properties.h>   // Global Properties
#include <global/rooms.h>        // Global Rooms
#include <global/standard.h>     // Global Standard Definitions

// Do not undefine this
#define NO_SURRENDER

#define LOGIN_OBJ      SECURE_DIR "/login"

#define PLAYER_OBJ     "/global/player"
#define CREATOR_OBJ    "/global/creator"

#define COMMAND_BASE   SECURE_DIR STANDARD_DIR "/command_base"
#define CHANNEL_BASE   SECURE_DIR STANDARD_DIR "/channel_base"
#define ERRORS_BASE    SECURE_DIR STANDARD_DIR "/errors_base"
#define POSITION_BASE  SECURE_DIR STANDARD_DIR "/position_base"
#define REPORT_BASE    SECURE_DIR STANDARD_DIR "/report_base"
#define SPEECH_BASE    SECURE_DIR STANDARD_DIR "/speech_base"
#define WWW_BASE       SECURE_DIR STANDARD_DIR "/www_base"

#define TCRE(XXX,YYY)  tell_creator(XXX,YYY)

#define NEW_DRIVER

#define DISTRIBUTION_LIB

// optimize and save_types are off because they can crash us
// #pragma save_binary
#pragma strict_types
#pragma warnings
#pragma no_save_types
#pragma no_optimize
#pragma show_error_context

#define slice_array(a,b,c) (a[b..c])
#define m_indices(map) (keys(map))
#define m_sizeof(map) (sizeof(map))
#define m_values(map) (values(map))
#define mappingp(x) (mapp(x))

#ifndef __SENSIBLE_MODIFIERS__
#define nosave nosave
#define protected nosave

#endif

#endif /* __GLOBAL_H */
