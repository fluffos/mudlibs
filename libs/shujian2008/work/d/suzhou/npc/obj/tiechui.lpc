// tiechui.c 铁锤

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("铁锤", ({ "tie chui", "chui" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄普通的精钢打造的铁锤 \n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从腰间抽出一柄$n握在手中试了试重量。\n");
		set("unwield_msg", "$N将手中的$n别在腰中。\n");
	}
	init_hammer(30);
	setup();
}
