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
 
#if 0
#define HM_VILLAGE  "/room/village/"
#else

#define TEMP_DIR    "/players/kryll/new/"
#define HM_VILLAGE  TEMP_DIR
#endif
#define HM_SHORE    "/room/shore/"
#define FOREST      "/room/forest/"
#define EAST        "/room/east/"
#define PLAIN       "/room/plain/"

#include "/obj/lw.h"

#endif // __ROOM_DEFS_H__

