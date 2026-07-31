// SN:X<3S0GoeCWlickCg
// ITEM Made by player(唐五藏:tangwu) /data/item/t/tangwu-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 13 21:38:41 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m玉带[2;37;0m", ({ "yaodai" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
看上去碧绿碧绿的，象是很值钱的东东。[2;37;0m
腰带缘上刻着一行小字：唐五藏(tangwu)
");
	set("value", 2100000);
	set("point", 94);
	set("material", "silk");
	set("wear_msg", "[1;33m$N将$n[1;33m缚在腰间。[2;37;0m\n");
	set("remove_msg", "[1;33m$N将$n[1;33m解下，团成一团，收入怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
