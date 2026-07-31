// SN:=he]mQU0MKD<9b]g
// ITEM Made by player(日月侠:riyuex) /data/item/r/riyuex-rytoukui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug 31 17:10:49 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("日月头亏[2;37;0m", ({ "rytoukui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：日月侠(riyuex)
");
	set("value", 2100000);
	set("point", 110);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备日月头亏[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了日月头亏[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
