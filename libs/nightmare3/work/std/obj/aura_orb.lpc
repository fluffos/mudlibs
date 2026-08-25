//    /std/obj/aura_orb.c
//    Nightmare Mudlib
//    Part of the /cmds/skills/_aura.c spell
//    Kalinash@Nightmare June 5, 1994.

#define LIGHT_LEVEL 2

#include <std.h>

inherit OBJECT;

int time;

void create() {
    ::create();
    set_id( ({ "orb", "glowing orb", "magical orb" }) );
    set_name("orb");
    set_weight(0);
    set_value(0);
    time = 0;
}

void set_time(int length) {
    time = length;
}

void start() {
  call_out("dest_me", time);
}

int move(mixed dest) {
    int x;

    if(environment(this_object()))
        environment(this_object())->add_property("light", -LIGHT_LEVEL);
    x = ::move(dest);
    if(environment(this_object()))
        environment(this_object())->add_property("light", LIGHT_LEVEL);
    return x;
}

void dest_me() {
    this_object()->remove();
}

int remove() {
    object ob;

    if(ob = environment(this_object()))
      ob->add_property("light", -LIGHT_LEVEL);
    return ::remove();
}


