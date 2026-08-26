/*
** File: lustsword.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    set("id", ({ "pickle", "sword", "pickle of wrath" }) );
    set("short", "The Pickle of Wrath");
    set("long", @PicklE
This is the mighty Pickle of Wrath, Not only is it a killer weapon
but you can eat it to boot! Other than the fact it's shaped like a
pickle, and has odd leaf things for the guard, it looks quite nice.
PicklE
    );
    set_weapon_type("sword/two-handed");
    set("name", "pickle of wrath");
    set_verbs(({ "slash", "stab", "cut" }));
    set("value", 15000);
    set_bonus(5);
    set("damage_type", "bludgeoning");
   set("nosecond", 1);
}
void init() {
   add_action("eat", "eat");
  }
int eat(string str) {
   if (!str) {
     write("Eat what?\n");
   return 1;
  }
   if (str == "pickle") {
     say (TPN+" eats their sword, right in front of you.\n");
     write("You gobble up the sword till nothing remains.\n");
   remove();
   return 1;
  }
return 1;
}
