// SN:X5FGM8>X2Y]Yi<b5
// ITEM Made by player(虚欧:wenc) /data/item/w/wenc-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 30 18:19:31 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m弑魂[2;37;0m", ({ "zhi" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：虚欧(wenc)
");
	set("value", 2100000);
	set("point", 861);
	set("material", "magic stone");
	set("wear_msg", "[1;32m一道光芒划过，$N双手闪烁[1;37m夺目光华[1;32m，映射得$N有若临风玉树，神采飞扬。[2;37;0m\n");
	set("remove_msg", "[1;33m$N双手一扬，[1;37m光华[1;33m尽敛。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
