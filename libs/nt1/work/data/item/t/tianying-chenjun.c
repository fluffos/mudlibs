// SN:X2RFfd<]?4d[ei;T
// ITEM Made by player(天鹰:tianying) /data/item/t/tianying-chenjun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Aug 18 18:54:29 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m龙王铠甲[2;37;0m", ({ "chenjun" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一件战衣。
[1;31m龙王铠甲[2;37;0m
战衣缘上刻着一行小字：天鹰(tianying)
");
	set("value", 1500000);
	set("point", 70);
	set("material", "silk");
	set("wear_msg", "[1;31m穿起了龙王铠甲[2;37;0m\n");
	set("remove_msg", "[1;31m脱掉了龙王铠甲[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
