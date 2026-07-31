// SN:V2Ef4c970;W6Hd2A
// ITEM Made by player(白云:sau) /data/item/s/sau-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan 14 15:52:41 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m护甲[2;37;0m", ({ "jia" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：白云(sau)
");
	set("value", 2100000);
	set("point", 277);
	set("material", "silk");
	set("wear_msg", "[1;35m$N穿上一件$n[1;35m。[2;37;0m\n");
	set("remove_msg", "[1;35m$N将$n[1;35m脱下。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
