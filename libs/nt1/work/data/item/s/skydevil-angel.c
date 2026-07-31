// SN:kogS]M?D?^`3kSc3
// ITEM Made by player(风魔:skydevil) /data/item/s/skydevil-angel.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 30 15:41:22 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m天使的罪恶[2;37;0m", ({ "angel" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[37m一件轻柔脱俗的白色羽衣。[2;37;0m
战衣缘上刻着一行小字：风魔(skydevil)
");
	set("value", 2100000);
	set("point", 167);
	set("material", "silk");
	set("wear_msg", "[1;37m只见羽衣的双翼慢慢的张开，笼罩在天魔的背脊上。[2;37;0m\n");
	set("remove_msg", "[1;37m天魔背上的双翼慢慢的收了起来，恢复成一件平凡的战衣。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
