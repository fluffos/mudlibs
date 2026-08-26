/*
**  File: cloak.c
**  Purpose: You figure it out, duh...
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
**    8 Oct 97 Cyanide added the init/remove thing to clean up the mud!
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
  void create() {
   set("short", "a thin black cloak");
   set("long", @Suckme
A thin black cloak, it looks like it would keep you warm, but not
much else.
Suckme
 );
  set("id", ({ "cloak", "newbie cloak", "newbie_equipment" }) ) ;
   set_armor_type("cloak");
   set("size", -1);
   set("value", 0);
}

void init() {
  if (!living(environment(this_object())))
    call_out("remove", 1);
}

void remove() {
  tell_room(environment(this_object()), 
    "The newbie item crumbles to dust and blows away.\n");
  ::remove();
}

