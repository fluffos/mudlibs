#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "wakizashi");
  set_weapon_type("sword/long");
  set_material_type("metal/steel");
  set("id" , ({ "wakizashi" }) );
  set("short" , "wakizashi");
  set("long" , @EndText
  Slightly smaller than the Katana, the wakizashi is a weapon that is
  not to be taken lightly. In the hands of a master it can muster great
  damage.

EndText
);
  set_bonus(1,1,1);
  set("nosecond" , 0);
  set_verbs( ({ "slice" , "slash" , "cleave" }) );
  set_verbs2( ({ "slices" , "slashes" , "cleaves" }) );
}
