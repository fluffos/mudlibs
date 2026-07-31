// SN:NNkJmgKlL^K=;>n6
// ITEM Made by player(寒易:yale) /data/item/y/yale-yala.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug  7 10:39:11 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m长[1;33m袖[2;37;0m", ({ "yala" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
[1;36m不错，[1;37m挺好穿的！！！[2;37;0m
护甲缘上刻着一行小字：寒易(yale)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "silk");
	set("wear_msg", "[1;33m有点冷啦！！[1;31m多穿一件！！！[2;37;0m\n");
	set("remove_msg", "[1;33m该脱衣服啦！[1;37m脱！再脱！没啦！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
