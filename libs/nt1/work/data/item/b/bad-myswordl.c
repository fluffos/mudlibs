// SN:n]j6Idag]odn=YT9
// ITEM Made by player(坏男孩:bad) /data/item/b/bad-myswordl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Dec  9 01:26:04 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m日月无光[2;37;0m", ({ "myswordl" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：坏男孩(bad)
");
	set("value", 1);
	set("point", 200100);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
