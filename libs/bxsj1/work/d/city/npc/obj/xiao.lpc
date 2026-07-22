// xiao.c 箫

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("箫",({"xiao"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit", "支");
		set("value", 600);
		set("material", "wood");
		set("long","这是一支用松木做的箫，做工十分精细。\n");
		set("wield_msg","$N伸手轻轻一招，一支$n已出现在$N手中。\n");
		set("unwield_msg","$N一声清啸，将$n插回腰间。\n");
	}
	init_sword(15);
	setup();
}
