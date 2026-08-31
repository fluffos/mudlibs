#include <std.h>
inherit ARMOUR;
int extra_worn();

void create() {
    ::create();
    set_name("armour");
    set("id", ({ "artrell armour" }) );
    set("short", "artrell armour");
    set("long", "The armour was tailored just for artrells.");
    set_weight(30);
    set_curr_value("gold", 5);
    set_type("body armour");
    set_limbs( ({ "first arm", "second arm", "third arm", "fourth arm",
                  "torso", }));
    set_ac(5);
    set_wear( (: extra_worn :) );
}

int extra_worn() {
  write("You slip on your artrell battle armour and feel more protected.");
  return 1;
}

int query_auto_load() { if (this_player()->query_race()=="artrell") return 1; }
