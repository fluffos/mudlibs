//File: boots.c
//Purpose: to test cattt's room.

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
   void create() {
    set("short", "boots");
    set("long" @Foo
A pair of worn leather boots.
Foo
);

    set("id", ({"boots", "leather"}) );
    set_armor_type("boots");
    set("value", 10);
    set("size", -1);
}

void init() {
  if (!living(environment(this_object())))
    call_out("remove", 1);
}

void remove() {
  tell_room(environment(this_object()),
  "The boots fall apart, and disappear.\n");
  ::remove();
}
