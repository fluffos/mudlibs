// ITEM Made by player(Äş²»Èº:ningxiaobai_1) /data/item/n/ningxiaobai_1-junziyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 01:46:10 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("¾ı×ÓÒÂ[2;37;0m", ({ "junziyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[1;37m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄş²»Èº(ningxiaobai_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸¾ı×ÓÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË¾ı×ÓÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
