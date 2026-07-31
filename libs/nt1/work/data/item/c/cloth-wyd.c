// SN:4h\E2UQhTV\eD??l
// ITEM Made by player(布衣:cloth) /data/item/c/cloth-wyd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Dec 12 23:21:34 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30m无影刀[2;37;0m", ({ "wyd" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[30m杀人于无影无踪[2;37;0m
刀柄上刻着一行小字：布衣(cloth)
");
	set("value", 2100000);
	set("point", 250);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
