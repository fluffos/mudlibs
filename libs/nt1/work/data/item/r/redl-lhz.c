// SN:VWZ09oMgYHk5[dVf
// ITEM Made by player(红莲老祖:redl) /data/item/r/redl-lhz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan  6 17:56:51 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m莲花掌[2;37;0m", ({ "lhz" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：红莲老祖(redl)
");
	set("value", 2100000);
	set("point", 281);
	set("material", "magic stone");
	set("wear_msg", "$N掏出一些碧青色的药丸在莲花掌上涂涂抹抹。\n莲花掌准备完毕。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m莲花掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
