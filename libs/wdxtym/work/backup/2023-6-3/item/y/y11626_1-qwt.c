// ITEM Made by player(·Ù¼Å:y11626_1) /data/item/y/y11626_1-qwt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 22:24:22 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("ĞùÔ¯Õ½Á¦[2;37;0m", ({ "qwt" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º·Ù¼Å(y11626_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸ĞùÔ¯Õ½Á¦[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁËĞùÔ¯Õ½Á¦[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
