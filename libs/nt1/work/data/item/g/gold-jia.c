// SN:dH=@HAQOXJ>>TVa7
// ITEM Made by player(黄金:gold) /data/item/g/gold-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jul 29 19:15:40 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m软猥甲[2;37;0m", ({ "jia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[1;32m桃花岛的宝物之一，会刺人哦！[2;37;0m
护甲缘上刻着一行小字：黄金(gold)
");
	set("value", 2100000);
	set("point", 148);
	set("material", "magic stone");
	set("wear_msg", "[1;32m桃花庵里桃花仙！！！！[2;37;0m\n");
	set("remove_msg", "[1;32m桃花仙人种桃树！！！！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
