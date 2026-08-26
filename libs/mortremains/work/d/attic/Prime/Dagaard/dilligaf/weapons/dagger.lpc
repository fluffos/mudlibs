#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "dagger");
  set_weapon_type("sword/short");
  set_material_type("metal/steel");
  set("value" , 250);
  set("id" , ({ "dagger" , "blackened dagger" }) );
  set("short" , "a blackened dagger");
  set("long" , @EndText
  A small blackened dagger, used mainly to slit throats. The blade has
  been blackened to hide the glint of the sun and the handle is wrapped
  with a tough hide.

EndText
);
  set("nosecond" , 0);
  set_verbs( ({ "slice" , "slash" }) );
  set_verbs2( ({ "slices" , "slashes" }) );

}
