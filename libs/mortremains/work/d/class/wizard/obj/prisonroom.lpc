/*
** File: prisonroom.c
** Purpose: The imprisonment room
*/

#include <config.h>       
#include <mudlib.h> 
inherit ROOM;


void create() {
::create();      
 set ("short", "Deep beneath the ground.");
 set ("long", "Lots of dirt surrounds you.\n");
}

void init() {
   add_action("time_stop", "");
}

int time_stop() {
   if (wizardp(TP)) return 0;

   write("You are in stasis - you can do nothing.\n");
   return 1;
}


