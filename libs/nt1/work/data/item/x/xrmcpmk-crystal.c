// SN:RiSg9nRm35:669fV
// ITEM Made by player(慕容鼬:xrmcpmk) /data/item/x/xrmcpmk-crystal.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 22 19:23:59 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m水晶[2;37;0m", ({ "crystal" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：慕容鼬(xrmcpmk)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wear_msg", "[1;37m哇～～～～[1;35m水晶　[1;36m︿＿︿　[1;37m想要吧．．．爸爸买给你[2;37;0m\n");
	set("remove_msg", "[1;37m哇～～～～[1;35m水晶　[1;36m︿＿︿　[1;37m想要吧．．．爸爸买给你[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
