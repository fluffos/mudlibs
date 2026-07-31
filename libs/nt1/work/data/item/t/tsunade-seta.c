// SN:PhlF@`XQV1lS`7m9
// ITEM Made by player(纲手:tsunade) /data/item/t/tsunade-seta.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 24 15:00:19 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m金环锁子甲[2;37;0m", ({ "seta" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[2;37;0m[1;31m雷火寒晶[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：纲手(tsunade)
");
	set("value", 1);
	set("point", 504240);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m装备[1;33m金环锁子甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;33m金环锁子甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
