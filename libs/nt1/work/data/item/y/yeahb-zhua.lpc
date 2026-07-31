// SN:DSL9C7Q3oanWc_N<
// ITEM Made by player(十龙:yeahb) /data/item/y/yeahb-zhua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 10 14:39:29 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m碌山之爪[2;37;0m", ({ "zhua" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;31m这是当年安碌山偷摸杨玉环咪咪的爪子，被郭子仪砍下收藏，历经千年而具魔性，端的是邪气冲天[2;37;0m
铁掌缘上刻着一行小字：十龙(yeahb)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;36m碌山之爪[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m碌山之爪[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
