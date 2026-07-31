// SN:f>YoU;f<RBMj@=U?
// ITEM Made by player(青衣修罗:feng) /data/item/f/feng-fumo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 23 15:44:51 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m修罗[1;31m伏魔[1;33m衣[2;37;0m", ({ "fumo" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;33m上古修罗战衣[2;37;0m
战衣缘上刻着一行小字：青衣修罗(feng)
");
	set("value", 2100000);
	set("point", 135);
	set("material", "silk");
	set("wear_msg", "[1;33m上古修罗战衣突现魔光，飘落在主人身上。[1;31m$N[1;33m力量大增[2;37;0m\n");
	set("remove_msg", "[1;31m$N[1;33m身上魔光减弱，[1;33m上古修罗战衣从主人身上飘下[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
