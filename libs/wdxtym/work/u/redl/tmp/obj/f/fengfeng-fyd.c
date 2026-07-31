// ITEM Made by player(·ç·ç:fengfeng) /data/item/f/fengfeng-fyd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:14:11 2014
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m¸£Ô´Í·¿ø[2;37;0m", ({ "fyd" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
");
	set("makeinfo", "[1;31m
·ç·ç(fengfeng)[1;31m ³öÆ·
[2;37;0m");
	set("value", 2100000);
	set("point", 250);
	set("max_consistence", 100);
	set("material", "magic stone");
	set("material_file", "/d/item/obj/butian");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m×°±¸[33m$n[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[33m$n[33m¡£[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/jing_recover", 40);
	set("armor_prop/kar", 6);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
