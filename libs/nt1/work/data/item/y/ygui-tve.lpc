// SN:D1Oia`Bd@2?]D8RU
// ITEM Made by player(夜鬼:ygui) /data/item/y/ygui-tve.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 30 16:41:00 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m手枭逆贱清旧京[2;37;0m", ({ "tve" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：夜鬼(ygui)
");
	set("value", 2100000);
	set("point", 482);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m手枭逆贱清旧京[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m手枭逆贱清旧京[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
