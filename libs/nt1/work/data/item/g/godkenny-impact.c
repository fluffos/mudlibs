// SN:XY=[nnVGmjBfI7VC
// ITEM Made by player(云飘之翼:godkenny) /data/item/g/godkenny-impact.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 19 20:30:34 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m第三次冲击[2;37;0m", ({ "impact" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[36m可以导致全人类走上毁灭之冲击[2;37;0m
腰带缘上刻着一行小字：云飘之翼(godkenny)
");
	set("value", 2100000);
	set("point", 104);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;36m第三次冲击[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m第三次冲击[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
