// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:            /sys/player.h
// Description:     Defines fuer den player, 
//                  zb notify_quit, notify_login, notify_net_dead
//
// $Log: player.h,v $
// Revision 1.2  2014/09/27 12:39:56  myonara
// Freischaltung und Kommentaranpassung
//
// Revision 1.1  2014/09/12 17:34:38  myonara
// Initialer STand fuer PLAYER_NOTIFY_MODES
//
//

#ifndef PLAYER_H
#define PLAYER_H 1

#define PLAYER_NOTIFY_MODES 1
// #undef PLAYER_NOTIFY_MODES
// betroffen: secure/portal/portal.c, voice,login,player,
// alle gilden_ob und master

#ifdef PLAYER_NOTIFY_MODES

// notify_login fuer flag
#define NL_LOGON   0
#define NL_STATUE  1
// notify_login fuer mode
#define NL_DEFAULT        0
#define NL_ARMAGEDDON     1
#define NL_STADT          2
#define NL_START          3
#define NL_PORTAL_ENTER   4
#define NL_PORTAL_REENTER 5

// notify_quit fuer flag:
#define NQ_ENDE    0
#define NQ_NETZTOT 1
#define NQ_SUIZID  2
// notify_quit fuer mode:
#define NQ_KEIN_ENDE     0
#define NQ_ENDE_BLANK    1
#define NQ_ENDE_STADT    2
#define NQ_ENDE_START    3
#define NQ_PORTAL_LEAVE  4
#define NQ_PORTAL_TRAVEL 5

// NL_PORTAL_ENTER  Der Spieler betritt durch ein portal von aussen unser mud.
// NQ_PORTAL_LEAVE  Der Spieler verlaesst unser mud wieder.
// NQ_PORTAL_TRAVEL  Ein Spieler verlaesst durch ein Portal in ein anderes Mud.
// NL_PORTAL_REENTER  Ein Spieler kommt zurueck in unser Mud.

//fuer notify_net_dead-> nur 0en
#define NND_DEFAULT      0

#endif // PLAYER_NOTIFY_MODES

#endif // TOUCH_H
