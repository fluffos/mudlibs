// ITEM Made by player(·ç·ç:fengfeng) /data/item/f/fengfeng-handa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 22 18:35:30 2014
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m[46mÇàÃ·ÕÆ[2;37;0m", ({ "handa" }));
	set_weight(450);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;35mÎŞÃûÖ®Îï[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
");
	set("makeinfo", "[1;31m
·ç·ç(fengfeng)[1;31m ³öÆ·
[2;37;0m");
	set("value", 6100000);
	set("point", 1500);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 6);
	set("wear_msg", "[33m$N[33m×°±¸[33m$n[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[33m$n[33m¡£[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/fatal_blow", 2.000000);
	set("armor_prop/add_blind", 2.000000);
	set("armor_prop/add_weak", 2.500000);
	set("armor_prop/add_freeze", 2.500000);
	set("armor_prop/add_forget", 2.500000);
	set("armor_prop/da_power", 2.000000);
	set("armor_prop/ap_power", 2.000000);
	set("armor_prop/add_damage", 2.500000);
	set("armor_prop/add_busy", 2.500000);
	set("armor_prop/double_damage", 2.000000);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
