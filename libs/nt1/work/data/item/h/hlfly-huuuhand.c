// SN:MNO81]CTV2N6JS;>
// ITEM Made by player(净胡:hlfly) /data/item/h/hlfly-huuuhand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 26 15:29:47 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("乱来之手[2;37;0m", ({ "huuuhand" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：净胡(hlfly)
");
	set("value", 2100000);
	set("point", 327);
	set("material", "magic stone");
	set("wear_msg", "胡乱飞发现自己的手很痒。[2;37;0m\n");
	set("remove_msg", "胡乱飞脱下乱来之手，用右手抓了一下左手解痒。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
