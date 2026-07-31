// ITEM Made by player(ÂŞÂí:makepojson_1) /data/item/m/makepojson_1-bvvgv.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 17 21:46:26 2023
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("°×Áú[2;37;0m", ({ "bvvgv" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[37mÉÏ¹Åº®Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂŞÂí(makepojson_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»Ö§[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
