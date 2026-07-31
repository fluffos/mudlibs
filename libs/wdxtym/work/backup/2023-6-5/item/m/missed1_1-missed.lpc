// ITEM Made by player(永夜:missed1_1) /data/item/m/missed1_1-missed.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 20:19:22 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("日轮刀[2;37;0m", ({ "missed" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：永夜(missed1_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "传说唯一能伤害无惨的武器[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
