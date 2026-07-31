// SN:0:B;C=UPKKc9Bn9^
// ITEM Made by player(渡甫:acer) /data/item/a/acer-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan 14 01:54:57 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m绵袄[2;37;0m", ({ "jia" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：渡甫(acer)
");
	set("value", 2100000);
	set("point", 206);
	set("material", "silk");
	set("wear_msg", "[35m$N懒洋洋地将$n[35m穿在身上，感到暖和了很多。[2;37;0m\n");
	set("remove_msg", "[1;32m$N很不情愿地将$n[1;32m脱了下来，好冷啊。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
