// SN:e^9jCi4^Dh35FAF2
// ITEM Made by player(钟情:cookie) /data/item/c/cookie-cookiea.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug  8 17:55:26 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m灵水系[2;37;0m", ({ "cookiea" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
全色特装[2;37;0m
腰带缘上刻着一行小字：钟情(cookie)
");
	set("value", 2100000);
	set("point", 82);
	set("material", "silk");
	set("wear_msg", "这个可是加很多骨和攻击的啊[2;37;0m\n");
	set("remove_msg", "有更好的么[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
