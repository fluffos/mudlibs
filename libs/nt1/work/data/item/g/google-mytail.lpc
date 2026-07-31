// SN:Mob]9P@K<Rb4Z8Hc
// ITEM Made by player(狗狗狗:google) /data/item/g/google-mytail.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 19 13:43:50 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m狗狗尾巴[2;37;0m", ({ "mytail" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：狗狗狗(google)
");
	set("value", 2100000);
	set("point", 368);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;36m狗狗尾巴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m狗狗尾巴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
