// SN:Z43I4^Re;gTgRGCG
// ITEM Made by player(红莲老祖:redl) /data/item/r/redl-lhy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan  6 18:00:01 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m莲花衣[2;37;0m", ({ "lhy" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：红莲老祖(redl)
");
	set("value", 2100000);
	set("point", 281);
	set("material", "silk");
	set("wear_msg", "$N掏出一些碧青色的药丸在莲花衣上涂涂抹抹。\n莲花衣准备完毕。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m莲花衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
