// SN:MXg8>8>@@KKVbO[m
// ITEM Made by player(欧阳闻浩:wenc) /data/item/w/wenc-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 20 07:18:49 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m太皓梭[2;37;0m", ({ "hand" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：欧阳闻浩(wenc)
");
	set("value", 2100000);
	set("point", 415);
	set("material", "magic stone");
	set("wear_msg", "[1;32m一道光芒划过，$N双掌闪烁[1;37m夺目光华[1;32m，映射得$N有若临风玉树，神采飞扬。[2;37;0m\n");
	set("remove_msg", "[1;33m$N双手一扬，[1;37m光华[1;33m尽敛。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
