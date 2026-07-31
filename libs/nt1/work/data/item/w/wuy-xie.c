// SN:oUbOGZbRgUc50cGK
// ITEM Made by player(默默:wuy) /data/item/w/wuy-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec 15 10:32:22 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m无影[2;37;0m", ({ "xie" }));
	set_weight(1080);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一双靴子。
[34m来无踪去无影。[2;37;0m
靴子缘上刻着一行小字：默默(wuy)
");
	set("value", 1500000);
	set("point", 51);
	set("material", "silk");
	set("wear_msg", "[1;34m来无影……[2;37;0m\n");
	set("remove_msg", "[1;34m去无踪……[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
