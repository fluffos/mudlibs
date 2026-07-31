// SN:Pk7A\90U7c[W>`K2
// ITEM Made by player(小撒:xiaosa) /data/item/x/xiaosa-xsjb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Sep  7 23:49:26 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m雪域苍狼追杀令[2;37;0m", ({ "xsjb" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：小撒(xiaosa)
");
	set("value", 2100000);
	set("point", 341);
	set("material", "magic stone");
	set("wield_msg", "得罪了[1;31m雪域苍狼[2;37;0m还想活？？？[2;37;0m\n");
	set("unwield_msg", "杀人偿命，天经地义！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
