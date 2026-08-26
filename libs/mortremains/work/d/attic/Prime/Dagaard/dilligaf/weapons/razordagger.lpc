#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "dagger");
  set_weapon_type("sword/short");
  set_material_type("metal/silver");
  set("value" , 10000);
  set("id" , ({ "dagger" , "razor" , "razor dagger" }) );
  set("short" , "a razor sharp dagger");
  set("long" , @EndText
  This is the razor sharp dagger that Jack the Ripper used to cleave
  and kill his opponents. It is extremely sharp and it glints with
  an unholy light. When you wield it, you kinda feel like you are
  going to lose it and tear shit up.

EndText
);
  set_bonus(2,3,4);
// another weapon wielded with it
  set("nosecond" , 0);
  set_verbs( ({ "slice" , "slash" , "cut deep into"}) );
  set_verbs2( ({ "slices" , "slashes" , "cuts deep into"}) );
}
