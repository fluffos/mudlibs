// SN:NAkOcSof9G>;hC3n
// ITEM Made by player(伯约:boyuezi) /data/item/b/boyuezi-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 19 00:13:39 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m乾坤袈裟[2;37;0m", ({ "cloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：伯约(boyuezi)
");
	set("value", 2100000);
	set("point", 185);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[34m乾坤袈裟[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[34m乾坤袈裟[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
