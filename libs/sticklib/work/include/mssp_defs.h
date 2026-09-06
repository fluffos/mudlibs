/*
** /include/mssp_defs.h
**
** AUTHOR: Tamarindo
**   DATE: January 2019
**
**  NOTES:
**
**	Find the MSSP Specification here: https://tintin.sourceforge.io/protocols/mssp/
**	Check if your MSSP is working here: https://grapevine.haus/mssp
**	Download TinTin++ here: http://tintin.sourceforge.net/
**	Then debug your MSSP with this:
**		#config {debug telnet} on
**		#session <your_mud_name> <your_mud_host_name> <your_mud_port>
**	Refer to /secure/login.c for how the MSSP handshake starts in this mudlib
**	Refer to /basic/player/telopt.c for how MSSP is sent to the client in this mudlib
*/
#ifndef MSSP_DEFS_H
#define MSSP_DEFS_H

#ifndef _MUD_NAME_H
#include "mud_name.h"
#endif // _MUD_NAME_H

#ifndef LEVELS_H
#include "levels.h"
#endif // LEVELS_H

#define MSSP_VAR 1
#define MSSP_VAL 2

// Required payload
#define MSSP_VAR_NAME               "NAME"
#define MSSP_VAL_NAME               MUD_NAME
#define MSSP_VAR_PLAYERS            "PLAYERS"
#define MSSP_VAL_PLAYERS            sprintf("%d", (sizeof(users()) - 1))
#define MSSP_VAR_UPTIME             "UPTIME"
#define MSSP_VAL_UPTIME             sprintf("%d", (time() - query_uptime()))

// Optional payload
#define MSSP_VAR_HOSTNAME           "HOSTNAME"
#define MSSP_VAL_HOSTNAME           "kandawen.com"
#define MSSP_VAR_PORT               "PORT"
#define MSSP_VAL_PORT               "7680"
#define MSSP_VAR_CODEBASE           "CODEBASE"
#define MSSP_VAL_CODEBASE           sprintf("LDMud %s", version())
#define MSSP_VAR_CONTACT            "CONTACT"
#define MSSP_VAL_CONTACT            "tamarindo@kandawen.com"
#define MSSP_VAR_CREATED            "CREATED"
#define MSSP_VAL_CREATED            "2018"
#define MSSP_VAR_ICON               "ICON"
#define MSSP_VAL_ICON               "http://www.kandawen.com/favicon.ico"
#define MSSP_VAR_IP                 "IP"
#define MSSP_VAL_IP                 "54.167.181.229"
#define MSSP_VAR_LANGUAGE           "LANGUAGE"
#define MSSP_VAL_LANGUAGE           "English"
#define MSSP_VAR_LOCATION           "LOCATION"
#define MSSP_VAL_LOCATION           "United States"
#define MSSP_VAR_MINIMUM_AGE        "MINIMUM AGE"
#define MSSP_VAL_MINIMUM_AGE        "13"
#define MSSP_VAR_WEBSITE            "WEBSITE"
#define MSSP_VAL_WEBSITE            "https://www.kandawen.com"
#define MSSP_VAR_FAMILY             "FAMILY"
#define MSSP_VAL_FAMILY             "LPMud"
#define MSSP_VAR_GENRE              "GENRE"
#define MSSP_VAL_GENRE              "Fantasy"
#define MSSP_VAR_GAMEPLAY           "GAMEPLAY"
#define MSSP_VAL_GAMEPLAY           "Hack and Slash"
#define MSSP_VAR_GAMESYSTEM         "GAMESYSTEM"
#define MSSP_VAL_GAMESYSTEM         "Custom"
#define MSSP_VAR_INTERMUD           "INTERMUD"
#define MSSP_VAL_INTERMUD           "-1"
#define MSSP_VAR_STATUS             "STATUS"
#define MSSP_VAL_STATUS             "Live"
#define MSSP_VAR_SUBGENRE           "SUBGENRE"
#define MSSP_VAL_SUBGENRE           "Medieval Fantasy"
#define MSSP_VAR_AREAS              "AREAS"
#define MSSP_VAL_AREAS              "-1"
#define MSSP_VAR_HELPFILES          "HELPFILES"
#define MSSP_VAL_HELPFILES          "-1"
#define MSSP_VAR_MOBILES            "MOBILES"
#define MSSP_VAL_MOBILES            "-1"
#define MSSP_VAR_OBJECTS            "OBJECTS"
#define MSSP_VAL_OBJECTS            "-1"
#define MSSP_VAR_ROOMS              "ROOMS"
#define MSSP_VAL_ROOMS              "-1"
#define MSSP_VAR_CLASSES            "CLASSES"
#define MSSP_VAL_CLASSES            "-1"
#define MSSP_VAR_LEVELS             "LEVELS"
#define MSSP_VAL_LEVELS             sprintf("%d", LVL_LEVELS)
#define MSSP_VAR_RACES              "RACES"
#define MSSP_VAL_RACES              "10"
#define MSSP_VAR_SKILLS             "SKILLS"
#define MSSP_VAL_SKILLS             "-1"
#define MSSP_VAR_ANSI               "ANSI"
#define MSSP_VAL_ANSI               "1"
#define MSSP_VAR_GMCP               "GMCP"
#define MSSP_VAL_GMCP               "1"
#define MSSP_VAR_MSDP               "MSDP"
#define MSSP_VAL_MSDP               "0"
#define MSSP_VAR_MCCP               "MCCP"
#define MSSP_VAL_MCCP               "0"
#define MSSP_VAR_MCP                "MCP"
#define MSSP_VAL_MCP                "0"
#define MSSP_VAR_MSP                "MSP"
#define MSSP_VAL_MSP                "1"
#define MSSP_VAR_MXP                "MXP"
#define MSSP_VAL_MXP                "0"
#define MSSP_VAR_PUEBLO             "PUEBLO"
#define MSSP_VAL_PUEBLO             "0"
#define MSSP_VAR_UTF_8              "UTF-8"
#define MSSP_VAL_UTF_8              "0"
#define MSSP_VAR_VT100              "VT100"
#define MSSP_VAL_VT100              "1"
#define MSSP_VAR_XTERM_256_COLORS   "XTERM 256 COLORS"
#define MSSP_VAL_XTERM_256_COLORS   "0"
#define MSSP_VAR_SSL                "SSL"
#define MSSP_VAL_SSL                "0"
#define MSSP_VAR_PAY_TO_PLAY        "PAY TO PLAY"
#define MSSP_VAL_PAY_TO_PLAY        "0"
#define MSSP_VAR_PAY_FOR_PERKS      "PAY FOR PERKS"
#define MSSP_VAL_PAY_FOR_PERKS      "0"
#define MSSP_VAR_HIRING_BUILDERS    "HIRING BUILDERS"
#define MSSP_VAL_HIRING_BUILDERS    "0"
#define MSSP_VAR_HIRING_CODERS      "HIRING CODERS"
#define MSSP_VAL_HIRING_CODERS      "0"

#endif // MSSP_VAR_DEFS_H
