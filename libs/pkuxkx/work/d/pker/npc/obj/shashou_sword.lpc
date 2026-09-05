// Made by goodtaste
//1999.6.3

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("杀手剑", ({ "shashou sword", "sword" }));
	set_weight(10000);
        set("value",10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "杀手帮高级成员的配剑\n");
		set("material", "steel");
               set("wield_msg", BLU "$N抽出杀手剑握于手中\n" NOR);
		set("unwield_msg", HIY "$N将杀手剑收入鞘中\n" NOR);
	}
        init_sword(100);
	setup();
}
