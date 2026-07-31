// SN:GB3WKkhfFfVdJ]9T
// ITEM Made by player(红莲老祖:redl) /data/item/r/redl-lhk.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan  6 21:22:12 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m莲花盔[2;37;0m", ({ "lhk" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：红莲老祖(redl)
");
	set("value", 2100000);
	set("point", 140);
	set("material", "magic stone");
	set("wear_msg", "$N掏出一些碧青色的药丸在莲花盔上涂涂抹抹。\n莲花盔准备完毕。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m莲花盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
