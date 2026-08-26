

#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
	set("author", "sebastian");
	set("name", "greataxe");
	set_weapon_type("axe/two-handed");
	set_material_type("metal/steel");
	set("id", ({"axe", "great axe", "giant axe" }) );
	set("short", "a great axe");
	set("long",@EndText
This is a crude, yet devastating weapon.  A favorite of giants.
EndText
	);
	set("nosecond", 1);
	set_verbs( ({ "slice", "slash", "impale" , "cut into" }) );
	set_verbs2( ({"slices", "slashes", "impales","cuts into" }) );
}
