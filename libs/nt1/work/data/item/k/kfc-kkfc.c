// SN:@H9A8:0e>hgcRB@9
// ITEM Made by player(肯德鸡:kfc) /data/item/k/kfc-kkfc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 18 15:55:20 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m碧玉[1;33m盔[2;37;0m", ({ "kkfc" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：肯德鸡(kfc)
");
	set("value", 2100000);
	set("point", 195);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;34m碧玉[1;33m盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;34m碧玉[1;33m盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
