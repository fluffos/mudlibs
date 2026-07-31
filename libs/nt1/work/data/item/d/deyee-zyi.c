// SN:bfHhJc8o^9cMRLBb
// ITEM Made by player(止水:deyee) /data/item/d/deyee-zyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 13 12:52:10 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m淡紫纱衣[2;37;0m", ({ "zyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[35m如云似雾的一件淡紫色纱衣，腰间随意绕着一串由水晶制成的小铃铛，雅致又不乏俏皮[2;37;0m
战衣缘上刻着一行小字：止水(deyee)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "silk");
	set("wear_msg", "[1;36m$N怔了一怔，披起喜爱的淡紫纱衣，走了出去[2;37;0m\n");
	set("remove_msg", "[1;36m$N轻轻叹息，扯下淡紫纱衣，丢在一边[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
