// SN:X\U>]=^=dD0B350l
// ITEM Made by player(月影:moonshadow) /data/item/m/moonshadow-nshuang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 19 22:07:17 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m凝霜[1;32m玉手[2;37;0m", ({ "nshuang" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;32m一只晶莹剔透，泛着翠绿色的玉手。[2;37;0m
铁掌缘上刻着一行小字：月影(moonshadow)
");
	set("value", 2100000);
	set("point", 168);
	set("material", "magic stone");
	set("wear_msg", "[1;31m$N[1;31m轻轻地把$n[1;31m套在手上。[1;31m套在$N[1;31m手上的$n[1;31m隐隐渗透着一股[1;34m玄寒之气[1;31m，[1;31m使周围都结上一层薄薄的[1;36m霜。[2;37;0m\n");
	set("remove_msg", "[1;31m$N轻轻地把$n[1;31m脱下来，四周的[1;36m薄霜[1;31m才开始慢慢的融化。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
