// SN::8JbB4YO:Q?XRLY3
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-pao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov 18 11:20:04 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m紫蟒袍[2;37;0m", ({ "pao" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
看上去很奢华的一件紫蟒袍。[2;37;0m
战衣缘上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 241);
	set("material", "silk");
	set("wear_msg", "[33m$N穿上一件$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N将$n[33m脱了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
