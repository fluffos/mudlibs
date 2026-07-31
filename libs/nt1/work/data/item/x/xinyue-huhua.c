// SN:^Ej4hMQO2Y<BJPhW
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-huhua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 25 01:01:07 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m护花[1;33m铃[2;37;0m", ({ "huhua" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;33m一对由两根金线连在一起的金黄色小铃铛，是南宫世家的传家宝。
特别之处在于假若一个铃铛振动，另外一铃必定轻声以和之。[2;37;0m
铁掌缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 298);
	set("material", "magic stone");
	set("wear_msg", "[1;33m一阵清脆的铃声掠过你的耳畔，你还未从中回过神来，$N已然拿了一对$n[1;33m在[1;37m玉掌[1;33m间缠绕。[2;37;0m\n");
	set("remove_msg", "[1;33m$N手腕翻动间，只闻得铃声一阵，$N腕间的一对$n[1;33m已经放入怀中，不见了踪影。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
