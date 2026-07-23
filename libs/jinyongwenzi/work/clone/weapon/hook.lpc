// hook.c

#include <weapon.h>
inherit HOOK;

void create()
{
    set_name("单钩", ({ "hook", "gou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄开边刃的单钩，是可怕的外门武器。\n");
		set("value", 4000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声将$n抽出握在手中。\n");
	}
	init_hook(30);
	setup();
}
