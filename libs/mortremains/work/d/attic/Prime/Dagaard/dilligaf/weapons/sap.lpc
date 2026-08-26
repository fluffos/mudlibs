#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "sap");
  set_weapon_type("club");
  set_material_type("leather");
  set("id" , ({ "sap" }) );
  set("short" , "a sap");
  set("long" , @EndText
  A thong of soft leather with a lead wieght in the end of it. It has
  the ability to do massive damage, and looks like it would brain just
  about anyone.

EndText
);
  set_bonus(1,0,3);

  set("nosecond" , 0);
  set_verbs( ({ "smash" , "pummel" }) );
  set_verbs2( ({ "smashes" , "pummels" }) );
  set("damage" , ({ 5,20 }) );
}
