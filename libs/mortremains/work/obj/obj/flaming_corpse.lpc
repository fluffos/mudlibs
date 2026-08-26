// Chronos's demented flaming corpse for the _fry.c command.
// Written from scratch ladee-daa-deee-dahh.
#include <mudlib.h>

inherit OBJECT ;

void make_skull() ;
string X;

void create() {
  seteuid(getuid()) ;
  set("short", "a flaming corpse") ;
  set("long", "It's a flaming corpse, flailing about violently.\n") ;
  set("prevent_get", 1) ;
  set("prevent_put", 1) ;
  set("id", ({ "#CORPSE#" }) ) ;
  set("prevent_give", 1) ;
}

void set_name(string str) {
  if (!str) return ;
 X = str; 
  set("short", "flaming corpse of "+str) ;
  set("long", wrap("It's the flaming corpse of "+str+", flailing about violently.")) ;
  set("id", ({ "corpse", "flaming corpse", "corpse of "+str }) ) ;
  call_out("flail", random(2)+2) ;
}

int flail(int x) {
  switch(x) {
    case 0: tell_room(environment(), X+"'s flaming corpse flails about the room, screaming.\n"+
            "You hear the crackling of burning flesh.\n") ;    break ;
    case 1: tell_room(environment(), X+"'s flaming corpse flails about the room, screaming.\n"+
            "The smell of burning flesh assails your nostrils.\n") ;    break ;
    case 2: tell_room(environment(), X+
                  "'s flaming corpse collapses on the ground and writhes in agony.\n");
             break ;
    default: tell_room(environment(), wrap("The flames on "+X+
        "'s corpse finally burn out, leaving nothing but a charred skull behind.")) ;
     break ;
}
  if (x<3) call_out("flail", random(3)+3, x+1) ;
  else make_skull() ;
  return 1;
}

void make_skull() {
  object skull ;
  skull = clone_object("/obj/obj/nuke_skull") ;
  skull->set("name", X) ;
  skull->move(environment(TO)) ;
  TO->remove() ;
}

void init() {
    if (living(environment())) TO->move(environment(environment())) ;
}

