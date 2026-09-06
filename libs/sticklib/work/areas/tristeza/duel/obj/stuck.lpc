 
/*
** (C) Tron.
**
** stuck.c 
**  
**- stuck in the swamp.
***********************/

#include <areas.h>

#define FOOP	AREA_TRISTEZA "duel/obj/shadow"
 
inherit FOOP;
 
#define say(x) tell_room(environment(this_player()), (x), ({this_player()}))
void
reset(status arg) {
 
   if(arg) return;
 
   do_shadow(this_player());
   set_short(this_player()->query_name()+
            " is stuck in the swamp here");
  
}
 
void
move_player(mixed a, mixed b) {
 
     write("You try to move but you are stuck in the swamp.\n");
     say(this_player()->query_name()+
                     " tries to move but soon gives up.\n");
 
     return;
}

status
query_stuck() { return 1; }
