// SN:4LK`G6E66oSd_:=D
// ITEM Made by player(段枫:jump) /data/item/j/jump-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 23 14:20:21 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m破布衣[2;37;0m", ({ "cloth" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
一件又破又烂的步衣。[2;37;0m
护甲缘上刻着一行小字：段枫(jump)
");
	set("value", 2100000);
	set("point", 156);
	set("material", "silk");
	set("wear_msg", "[35m穿上一件破布衣，看上去又破又烂。[2;37;0m\n");
	set("remove_msg", "[35m脱下破布衣，看上去精神多了。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
