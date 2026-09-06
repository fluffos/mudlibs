 
/*
** nlock.c
**
** Solve the problem and get
** a crystal.
**
** (C) Tron.
**
*/
 
#include <areas.h>

#define	FOOP	AREA_TRISTEZA "duel/obj/puzzle"
inherit FOOP;
 
void
reset(status arg) {
 
   if(arg) return;
 
   set_trigger_fun(this_object(), "lock_opens");
}
 
void
create() {
 
::create();
reset(0);
}
 
string
short() { return "There is a board attached to the wall here"; }
 
void
lock_opens() {
 
    write("CLICK!!! - A piece of crystal drops down on the ground.\n");
	move_object(clone_object(AREA_DUEL_ARENA "obj/crystal"),
                environment());
 
}
