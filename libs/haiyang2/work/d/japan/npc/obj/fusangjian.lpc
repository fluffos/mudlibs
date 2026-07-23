// thin_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
      set_name("扶桑剑", ({ "fusang jian", "sword", "jian" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                 set("value", 8500);
		set("material", "steel");
            set("long", "这是一把又细又长的剑，刃口相当锋利。\n");
		set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
		set("weapon_prop/courage", -4);
	}
        init_sword(120);
	setup();
}
