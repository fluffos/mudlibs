#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("镔铁杖", ({ "bintie zhang", "zhang","staff" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大明制式的镔铁杖，高级武将方可使用。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("no_drop",1);
		set("no_give",1);
		set("no_get","大明的制式镔铁杖，捡了要杀头的。\n");
	}
	init_staff(100+random(25));
	setup();
}
