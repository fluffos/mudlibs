// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:        /sys/portal.h
// Author:      Gnomi
// Description: Defines fuer /secure/portal

#ifndef __PORTAL_H__
#define __PORTAL_H__

#define PORTAL_SERVER     "/secure/portal/portal"
#define PORTAL_CONNECTION "/secure/portal/obj/connection"
#define PORTAL_ROOM       "/room/portal"
#define PORTAL_GUEST      "/obj/player"

#define ID_PORTAL_ALL           "Portal"
#define ID_PORTAL(name)         sprintf("Portal %s", (name))

#define P_CONF_SRC_PORTAL_NAME  "Portal"
#define P_CONF_ROOM             "Raum"
#define P_CONF_DEST_MUD         "ZielMUD"
#define P_CONF_DEST_PORTAL_NAME "ZielPortal"
#define P_CONF_DEST_PORT        "ZielPort"
#define P_CONF_DEST_IP          "ZielIP"
#define P_CONF_HOMEMUD          "HomeMUD"

#define P_MSG_TYPE              "Type"
#define P_MSG_PLAYER            "Player"
#define P_MSG_MUD               "MUD"
#define P_MSG_DATA              "Data"   // Command, message or save data.
#define P_MSG_PORTAL            "Portal"
#define P_MSG_IP                "IP"
#define P_MSG_PORT              "Port"
#define P_MSG_CHARACTER         "Char"

// UNItopia extensions
#define P_MSG_TEXTORIG          "UNI-Text"
#define P_MSG_TEXTTYPE          "UNI-MT"
#define P_MSG_TEXTACTION        "UNI-MA"

#define P_TYPE_HELLO            "Hi"     // Initial message.
#define P_TYPE_ENTER            "Enter"  // Player entered a guest world.
#define P_TYPE_MOVE             "Move"   // Guest moves to another guest world.
#define P_TYPE_LEAVE            "Leave"  // Guest must leave (he quit in his own world)
#define P_TYPE_QUIT             "Quit"   // He quit in the guest world.
#define P_TYPE_COMMAND          "Cmd"    // Player sent a command.
#define P_TYPE_MESSAGE          "Msg"    // Message to the real player
#define P_TYPE_SAVE_DATA        "Save"   // Save data from the guest MUD.

#define P_CHAR_NAME             "Name"
#define P_CHAR_GENDER           "Gender"
#define P_CHAR_LEVEL            "UNI-Level"

#endif
