// SN:Yoj9A[=j[KAmRT>2
// ITEM Made by player(孤独的云:lting) /data/item/l/lting-hujia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 30 20:47:26 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m护甲[2;37;0m", ({ "hujia" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：孤独的云(lting)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "silk");
	set("wear_msg", "[33m$N穿上一件$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N把$n[33m脱了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
