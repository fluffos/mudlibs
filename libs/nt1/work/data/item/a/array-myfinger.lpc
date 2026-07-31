// SN:@3\PAhhdm3UnZ:Hn
// ITEM Made by player(艾汀:array) /data/item/a/array-myfinger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 17 20:55:16 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m妒火[2;37;0m", ({ "myfinger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：艾汀(array)
");
	set("value", 2100000);
	set("point", 1151);
	set("material", "magic stone");
	set("wear_msg", "[1;31m$N握紧双拳，喃喃道：我决不放弃！[2;37;0m\n");
	set("remove_msg", "[1;33m$N长叹一声，为什么会这样！！！！！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
