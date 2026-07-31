// SN:ELjQZ`D4TU2B<5D=
// ITEM Made by player(血影:wozuiqiang) /data/item/w/wozuiqiang-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 17 09:42:22 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m独[1;32m孤[1;37m剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;36m不是一把普通的剑[2;37;0m
剑柄上刻着一行小字：血影(wozuiqiang)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;32m中的毒发作了[2;37;0m\n");
	set("unwield_msg", "[1;34m鬼门关[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
