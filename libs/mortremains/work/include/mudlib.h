 
//  File  :  /include/mudlib.h
//
//  Standard mudlib object file locations
 
#define OBJECT 		"/std/object/ob"
#define SECURE_OBJECT 	"/std/object/sec_ob"
#define USER 		"/std/user"
#define BODY_BASE	"/std/body"
#define ROOM 		"/std/room"
#define DAEMON 		"/std/cmd_m"
#define SERVER		"/std/server"
#define WEAPON 		"/std/weapon"
#define ARMOR 		"/std/armor"
#define MONSTER 	"/std/monster"
#define LIVING 		"/std/living"
#define GHOST		"/std/ghost"
#define CONTAINER 	"/std/container"
#define COINVALUE 	"/std/coinvalue"
#define LOCK 		"/std/lock"
#define DOORS 		"/std/doors"
#define PRIVATE_ROOM    "/std/private_room"
#define PORTAL          "/std/portal"
#define BUYONLY_SHOP    "/std/buy_only_shop"
#define BOARD 		"/std/board/bboard"
#define SPELL           "/std/spell.lpc"
#define GUILD           "/std/guild.lpc"
#define SHOP            "/std/shop.lpc"
#define PUB		"/std/pub.lpc"
#define AMMO            "/std/ammo.lpc"
#define CAN             "/std/waste_can.lpc"
#define CYBERWARE       "/std/cyberware.lpc"
#define SHIP             "/std/ship_ob.lpc"  // Chronos added.

// The next is to make save extension work for v20.*and v21.*
#ifndef __SAVE_EXTENSION__
#define __SAVE_EXTENSION__ SAVE_EXTENSION
#endif

//Useful global definitions.
#define TP this_player()
#define TPn this_player()->query("name")
#define TPN this_player()->query("cap_name") 
#define TO this_object()
#define TON this_object()->query("cap_name")
#define POSS possessive(this_player()->query("gender"))
