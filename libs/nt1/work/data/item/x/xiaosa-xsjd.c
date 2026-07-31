// SN:6RSKUCOdM2L8aHWd
// ITEM Made by player(小撒:xiaosa) /data/item/x/xiaosa-xsjd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct  6 12:03:43 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m雪域苍狼追杀令[2;37;0m", ({ "xsjd" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：小撒(xiaosa)
");
	set("value", 2100000);
	set("point", 415);
	set("material", "magic stone");
	set("wield_msg", "得罪了[1;37m雪域[1;31m苍狼[2;37;0m还想活？？？[2;37;0m\n");
	set("unwield_msg", "杀人偿命，天经地义！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
