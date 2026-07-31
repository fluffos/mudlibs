// SN:f[h=^4hOJReiGDKe
// ITEM Made by player(风魔:skydevil) /data/item/s/skydevil-elf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 28 18:19:30 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m精灵的无知[2;37;0m", ({ "elf" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;32m一双翠玉无瑕的绿晶护手[2;37;0m
铁掌缘上刻着一行小字：风魔(skydevil)
");
	set("value", 2100000);
	set("point", 202);
	set("material", "magic stone");
	set("wear_msg", "[1;32m一阵清风吹过，[1;37m精灵的无知[1;32m已渐渐的在天魔手上成形。[2;37;0m\n");
	set("remove_msg", "[1;32m当天魔收起[1;37m精灵的无知[1;32m，那流动的空气似乎静止了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
