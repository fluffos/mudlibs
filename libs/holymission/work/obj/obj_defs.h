/*-------------------------------------------------------------------------*/
/* FILE : /obj/obj_defs.h                                                  */
/*                                                                         */
/* Description : This file contains some universal defines that are        */
/*               included in all inherited object files. They do not pass  */
/*               over to other files.                                      */
/*-------------------------------------------------------------------------*/
 
#ifndef __OBJ_DEFS_H__

#define __OBJ_DEFS_H__
 
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
 
#endif // __OBJ_DEFS_H__
