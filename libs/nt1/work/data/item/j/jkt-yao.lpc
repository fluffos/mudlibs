// SN:R_kjG<TIn8QP;Mld
// ITEM Made by player(渡独:jkt) /data/item/j/jkt-yao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May  9 05:26:11 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m碧磷[1;37m缠身[1;32m丝[2;37;0m", ({ "yao" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[1;37m一段由天山蚕丝制作的腰带。[2;37;0m
腰带缘上刻着一行小字：渡独(jkt)
");
	set("value", 2100000);
	set("point", 180);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;36m碧磷[1;37m缠身[1;32m丝[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m碧磷[1;37m缠身[1;32m丝[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
