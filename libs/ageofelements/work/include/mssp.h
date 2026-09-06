/*
** /include/mssp.h
**
** AUTHOR: Tamarindo
**   DATE: August 2019
**
**  NOTES:
**
**	Find the MSSP Specification here: https://tintin.sourceforge.io/protocols/mssp/
**	Check if your MSSP is working here: https://grapevine.haus/mssp
**	Download TinTin++ here: http://tintin.sourceforge.net/
**	Then debug your MSSP with this:
**		#config {debug telnet} on
**		#session <your_mud_name> <your_mud_host_name> <your_mud_port>
**	Refer to /obj/player.c for how the MSSP handshake starts in this mudlib
**	Refer to /obj/player/telopt.c for how MSSP is sent to the client in this mudlib
*/
#ifndef MSSP_H
#define MSSP_H

#ifndef LPC_DRIVER_INFO_H_
#include <sys/driver_info.h>
#endif // LPC_DRIVER_INFO_H_

#define MSSP_VAR 1
#define MSSP_VAL 2

// Required payload
#define MSSP_VAR_NAME               "NAME"
#define MSSP_VAL_NAME               "Age of Elements"
#define MSSP_VAR_PLAYERS            "PLAYERS"
#define MSSP_VAL_PLAYERS            sprintf("%d", (sizeof(users()) - 1))
#define MSSP_VAR_UPTIME             "UPTIME"
#define MSSP_VAL_UPTIME             sprintf("%d", (time() - driver_info(DI_BOOT_TIME)))

// Optional payload
#define MSSP_VAR_HOSTNAME           "HOSTNAME"
#define MSSP_VAL_HOSTNAME           "ageofelements.org"
#define MSSP_VAR_PORT               "PORT"
#define MSSP_VAL_PORT               "7680"
#define MSSP_VAR_CODEBASE           "CODEBASE"
#define MSSP_VAL_CODEBASE           sprintf("LDMud %s", version())
#define MSSP_VAR_CONTACT            "CONTACT"
#define MSSP_VAL_CONTACT            "tamarindo@ageofelements.org"
#define MSSP_VAR_CREATED            "CREATED"
#define MSSP_VAL_CREATED            "2019"
#define MSSP_VAR_DISCORD            "DISCORD"
#define MSSP_VAL_DISCORD            "https:/\/discord.gg/------"
#define MSSP_VAR_ICON               "ICON"
#define MSSP_VAL_ICON               "https:/\/www.ageofelements.org/favicon.ico"
#define MSSP_VAR_IP                 "IP"
#define MSSP_VAL_IP                 "3.221.71.235"
#define MSSP_VAR_LANGUAGE           "LANGUAGE"
#define MSSP_VAL_LANGUAGE           "English"
#define MSSP_VAR_LOCATION           "LOCATION"
#define MSSP_VAL_LOCATION           "United States"
#define MSSP_VAR_MINIMUM_AGE        "MINIMUM AGE"
#define MSSP_VAL_MINIMUM_AGE        "17"
#define MSSP_VAR_WEBSITE            "WEBSITE"
#define MSSP_VAL_WEBSITE            "https:/\/www.ageofelements.org"
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
#define MSSP_VAL_OBJECTS            sprintf("%d", driver_info(DI_NUM_OBJECTS))
#define MSSP_VAR_ROOMS              "ROOMS"
#define MSSP_VAL_ROOMS              sprintf("%d", -1) // Exchange -1 with call to map daemon
#define MSSP_VAR_CLASSES            "CLASSES"
#define MSSP_VAL_CLASSES            sprintf("%d", -1) // Exchange -1 with call to class daemon
#define MSSP_VAR_LEVELS             "LEVELS"
#define MSSP_VAL_LEVELS             sprintf("%d", 25) // Exchange 25 with call to level daemon
#define MSSP_VAR_RACES              "RACES"
#define MSSP_VAL_RACES              sprintf("%d", -1) // Exchange -1 with call to race daemon
#define MSSP_VAR_SKILLS             "SKILLS"
#define MSSP_VAL_SKILLS             sprintf("%d", -1) // Exchange -1 with call to skill daemon
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
#define MSSP_VAL_MXP                "1"
#define MSSP_VAR_PUEBLO             "PUEBLO"
#define MSSP_VAL_PUEBLO             "0"
#define MSSP_VAR_UTF_8              "UTF-8"
#define MSSP_VAL_UTF_8              "1"
#define MSSP_VAR_VT100              "VT100"
#define MSSP_VAL_VT100              "0"
#define MSSP_VAR_XTERM_256_COLORS   "XTERM 256 COLORS"
#define MSSP_VAL_XTERM_256_COLORS   "1"
#define MSSP_VAR_SSL                "SSL"
#define MSSP_VAL_SSL                "8680"
#define MSSP_VAR_PAY_TO_PLAY        "PAY TO PLAY"
#define MSSP_VAL_PAY_TO_PLAY        "0"
#define MSSP_VAR_PAY_FOR_PERKS      "PAY FOR PERKS"
#define MSSP_VAL_PAY_FOR_PERKS      "0"
#define MSSP_VAR_HIRING_BUILDERS    "HIRING BUILDERS"
#define MSSP_VAL_HIRING_BUILDERS    "0"
#define MSSP_VAR_HIRING_CODERS      "HIRING CODERS"
#define MSSP_VAL_HIRING_CODERS      "0"

#endif // MSSP_H
