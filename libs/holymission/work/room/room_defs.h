/*-------------------------------------------------------------------------*/
/* FILE : /room/room_defs.h                                                */
/*                                                                         */
/* Description : This file contains some universal defines that are        */
/*               included in all room files.                               */
/*-------------------------------------------------------------------------*/
 
#ifndef __ROOM_DEFS_H__
 
#define __ROOM_DEFS_H__
 
#define TP         this_player()
#define TO         this_object()
#define NAME       query_name()
#define RNAME      query_real_name()
#define TPN        TP->NAME
#define TPRN       TP->RNAME
#define TPL        TP->query_level()
#define IMM        query_immortal()
#define INV        query_invis()
#define CAP        capitalize
#define LVL        query_level()
#define ENV        environment

#define TELL       tell_object
#define TELLR      tell_room
#define MOVE       move_object
#define MOVEP      move_player
 
#define HM_VILLAGE  "/room/village/"
#define ROOM        "/room/"
#define PLAIN        "/room/plain/"
#define HM_SHORE    "/room/shore/"
#define FOREST      "/room/forest/"
#define EAST        "/room/east/"
#define MINES      "/room/mines/"
#define FIELDS      "/room/field/"
#define SHORE       "/room/shore/"
#define ORC_VALLEY   "/room/orc_valley/"
#define VILLAGE_MEET    HM_VILLAGE + "meeting/"
#define VILLAGE_GARDEN  HM_VILLAGE + "garden/"
 
#include "/obj/lw.h"
 
#endif // __ROOM_DEFS_H__
