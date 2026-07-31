// SN:@XQ2eW3@4bZAKS6I
// ITEM Made by player(独孤傲:shadowkwan) /data/item/s/shadowkwan-helmet.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun  4 13:17:45 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m光[1;33m之[1;36m神盔[2;37;0m", ({ "helmet" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;32m沐浴过[1;31m女神之血[1;32m的[1;36m终极头盔[1;32m。[2;37;0m
头盔缘上刻着一行小字：独孤傲(shadowkwan)
");
	set("value", 2100000);
	set("point", 290);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m光[1;33m之[1;36m神盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m光[1;33m之[1;36m神盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
