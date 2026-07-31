// SN:O:\Bh]>XOhD_N=fN
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-zqyei.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 26 20:10:03 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m朱雀[1;33m头盔[2;37;0m", ({ "zqyei" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 657);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;31m朱雀[1;33m头盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m朱雀[1;33m头盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
