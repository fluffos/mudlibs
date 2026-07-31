// ITEM Made by player(·ç·ç:fengfeng) /data/item/f/fengfeng-fyh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:23:59 2014
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m¸£Ô´Ñ¥×Ó[2;37;0m", ({ "fyh" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;37m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
");
	set("makeinfo", "[1;31m
·ç·ç(fengfeng)[1;31m ³öÆ·
[2;37;0m");
	set("value", 2100000);
	set("point", 200);
	set("max_consistence", 100);
	set("material", "silk");
	set("material_file", "/d/item/obj/tiancs");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m×°±¸[33m$n[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[33m$n[33m¡£[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/defense", 30);
	set("armor_prop/jing_recover", 40);
	set("armor_prop/kar", 3);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
