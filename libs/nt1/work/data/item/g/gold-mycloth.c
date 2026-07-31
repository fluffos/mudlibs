// SN:cP_fbVcf5eM9g^Ti
// ITEM Made by player(蓝魔:gold) /data/item/g/gold-mycloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep 18 18:41:55 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m白羽衣[2;37;0m", ({ "mycloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;37m这是用天使的白羽做的衣服[2;37;0m
战衣缘上刻着一行小字：蓝魔(gold)
");
	set("value", 2100000);
	set("point", 185);
	set("material", "silk");
	set("wear_msg", "[1;37m天使来啦，大家磕头啊！[2;37;0m\n");
	set("remove_msg", "[1;37m天使走啦，大家平身哦！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
