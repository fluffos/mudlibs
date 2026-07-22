// bishou.c 匕首
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("匕首", ({ "bi shou", "shou" }));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄锋利的小匕首。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从腰间抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n别在腰中。\n");
	}
	init_dagger(10);
	setup();
}
