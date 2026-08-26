// portal.c - This is the stanard inheritable portal object.
// (06-09-00) Written by Chronos@MR.
#include <mudlib.h>

inherit OBJECT ;

string dest ;

void create() {
  seteuid(getuid()) ;
  set("short", "a glowing portal") ;
  set("long", "This is a generic portal.\n" );
  set("id", ({ "portal", "glowing portal" }) ) ;
  set("prevent_get", 1) ;
  set("prevent_insert", 1) ;
  set("prevent_clean", 1) ;
}

void init() {
  if (living(environment())) move(environment(environment())) ;
  add_action("enter", "enter") ;
}

int enter(string str) {
  if (!str || !id(str)) return 0 ;
  write("You step through the portal and find yourself elsewhere..\n") ;
  say(TPN+" steps through the portal and vanishes!\n") ;
  TP->move_player(dest, "SNEAK") ;
  message("movement", wrap(
      "The portal shimmers momentarily and "+TPN+
          " steps through, looking a bit disoriented."), 
          environment(TP), ({ TP }) ) ;
  return 1;
}

void set_destination(string str) {
   if (!str) return ;
  set("destination", str ) ;
    dest = str ;
}
