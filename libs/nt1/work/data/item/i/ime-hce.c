// SN:=5PK^QZ1`T2gokeh
// ITEM Made by player(闯越:ime) /data/item/i/ime-hce.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun  9 17:04:52 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("耗材[2;37;0m", ({ "hce" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：闯越(ime)
");
	set("value", 700000);
	set("point", 34);
	set("material", "iron");
	set("wear_msg", "[33m$N[33m装备耗材[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了耗材[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
