// hook.c

#include <ansi.h>
#include <weapon.h>
inherit HOOK;

void create()
{
    set_name("护手钩", ({ "hushou gou", "gou", "hushou", "hook" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "\n这是一把精刚所制的护手钩，刃口泛出阵阵青光，锋利无比！\n\n");
		set("value", 20000);
		set("material", "steel");
                set("rigidity", 1);
                set("weapon_prop/parry", -2);
                set("wield_neili", 50);
                set("wield_maxneili", 500);
                set("wield_str", 22);
	}
	init_hook(40);
	setup();
}

