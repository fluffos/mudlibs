// ITEM Made by player(胡来:welcome_1) /data/item/w/welcome_1-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr  6 23:54:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m白嫖王[2;37;0m", ({ "jian" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;31m真龙[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：胡来(welcome_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
