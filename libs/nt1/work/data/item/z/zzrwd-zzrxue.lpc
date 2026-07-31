// SN:20ifg2WT\go<WR8@
// ITEM Made by player(渡空:zzrwd) /data/item/z/zzrwd-zzrxue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 25 08:52:51 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("凉靴[2;37;0m", ({ "zzrxue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
二一世纪最流行的凉靴[2;37;0m
靴子缘上刻着一行小字：渡空(zzrwd)
");
	set("value", 2100000);
	set("point", 96);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备凉靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了凉靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
