// SN:N]=1IT6e5le_Z0<h
// ITEM Made by player(红痕:hongdou) /data/item/h/hongdou-kuib.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 26 20:50:31 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m紫金盔[2;37;0m", ({ "kuib" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：红痕(hongdou)
");
	set("value", 2100000);
	set("point", 204);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[35m紫金盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[35m紫金盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
