 
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
#define BOARD 		"/std/board/bboard"
// The next is to make save extension work for v20.*and v21.*
#ifndef __SAVE_EXTENSION__
#define __SAVE_EXTENSION__ SAVE_EXTENSION
#endif
