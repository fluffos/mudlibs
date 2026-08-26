/*
** File: 3d_glasses.c
** Purpose: Cool wiz tool. When worn, they tell their owner
**    how much damage something just did to them, and what
**    type the damage was.
** Credits:
**    11 July 97  Cyanide wrote the file.
*/


#include <mudlib.h>
#include <config.h>

inherit ARMOR;

void create() {
  set_armor_type("amulet");
  set("short", "a pair of cheap 3-d glasses");
  set("long", @End3D
These seem to be a cheap pair of 3D-glasses, with frames of
cardboard, and lenses of two different color cellophane.
When worn, these glasses tell you how much damage you've
taken.
End3D
    );
  set("id", ({ "glasses", "#REFLEXIVE_SPELL#"}) );
   set("value", 0);
}

int reflex (int damage, string type, object attacker) {
  object ob = environment(this_object());

   if ((query("equipped")) && (type) && (damage))
   tell_object(ob, wrap("You just took "+damage+" points of "+
     type+" damage from "+attacker->query("cap_name")+
     "'s attack."));

   return damage;
}
