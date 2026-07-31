// SN:9Q2WSimAVVHe0;3;
// ITEM Made by player(勇哥:hanweiyong) /data/item/h/hanweiyong-hanwei.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 25 17:28:46 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m圣战宝甲[2;37;0m", ({ "hanwei" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：勇哥(hanweiyong)
");
	set("value", 2100000);
	set("point", 80);
	set("material", "magic stone");
	set("wear_msg", "[1;36m这看上去似乎是传奇年代失传多年的四十级男战士装备[2;37;0m\n");
	set("remove_msg", "[1;35m打你们这些小样要穿这么好的铠甲吗，说完便脱下来仍进秦淮河了[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
