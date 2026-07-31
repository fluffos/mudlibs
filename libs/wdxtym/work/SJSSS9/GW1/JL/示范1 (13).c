// ITEM Made by player(·ç·ç:fengfeng) /data/item/f/fengfeng-cblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 22 18:13:41 2014
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("²Áµ¶[2;37;0m", ({ "cblade" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;35mÎŞÃûÖ®Îï[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
");
	set("makeinfo", "[1;31m
·ç·ç(fengfeng)[1;31m ³öÆ·
[2;37;0m");
	set("value", 6100000);
	set("point", 1500);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 2);
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if( !check_clone() ) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }
