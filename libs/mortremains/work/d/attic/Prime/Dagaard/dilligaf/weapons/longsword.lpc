#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "longsword");
  set_weapon_type("sword/long");
  set_material_type("metal/steel");
  set("id" , ({ "sword" , "longsword" }) );
  set("short" , "a longsword");
  set("long" , @EndText
  A finly crafted longsword, it glints and shines in the light.

EndText
);
  set_bonus(1,0,0);
  set("nosecond" , 0);

  set_verbs( ({ "slice" , "slash" , "cleave" }) );
  set_verbs2( ({ "slices" , "slashes" , "cleaves" }) );

}
