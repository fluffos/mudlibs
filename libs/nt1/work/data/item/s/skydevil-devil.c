// SN:`Lf5Bij92^JMDiF4
// ITEM Made by player(风魔:skydevil) /data/item/s/skydevil-devil.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Aug 27 02:10:32 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m恶魔的恐惧[2;37;0m", ({ "devil" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[1;34m一件轻便厚实的蓝色铠甲。[2;37;0m
护甲缘上刻着一行小字：风魔(skydevil)
");
	set("value", 2100000);
	set("point", 160);
	set("material", "magic stone");
	set("wear_msg", "[1;36m恶魔的恐惧[1;34m散发出深蓝色的冷光，笼罩天魔身上。[2;37;0m\n");
	set("remove_msg", "[1;34m蓝色的冷光渐渐散去，[1;36m恶魔的恐惧[1;34m又恢复成一般的铠甲。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
