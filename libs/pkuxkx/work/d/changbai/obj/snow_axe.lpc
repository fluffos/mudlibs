// gangdao.c

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("破冰斧", ({ "snow axe", "axe" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄坚韧的破冰斧，常在冰原中使用。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_axe(20);
	setup();
}
