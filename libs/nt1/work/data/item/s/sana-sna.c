// SN:4W=7DhE;oQAAMEBl
// ITEM Made by player(欧阳青蛙:sana) /data/item/s/sana-sna.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan 11 11:48:23 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m辟邪剑[2;37;0m", ({ "sna" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：欧阳青蛙(sana)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "我是太监又怎样？[2;37;0m\n");
	set("unwield_msg", "我是太监又怎样？[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
