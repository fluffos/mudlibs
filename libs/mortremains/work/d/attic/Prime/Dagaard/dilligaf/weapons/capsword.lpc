#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());

  set("name" , "sword");
  set_weapon_type("sword/long");
  set_material_type("metal/steel");
  set("id" , ({ "sword" , "longsword" }) );
  set("short" , "a longsword");
  set("long" , @EndText
  This is the sword of the captain of the Dagaard guards, he obviously
  knew how to take care of a weapon. The blade reaches out a good couple
  of feet and it shines brightly in the sunlight. The hilt is a leather
  thong wrapped around a solid piece of wood, a very decent sword.

EndText
);
  set("value" , 1500);
  set_bonus(1,0,1);
  set("nosecond" , 0);
  set_verbs( ({ "slice" , "slash" }) );
  set_verbs2( ({ "slices" , "slashes" }) );
}
