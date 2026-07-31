// ITEM Made by player(¹Ş×Ó:p357159_1) /data/item/p/p357159_1-yuxi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 21:57:52 2023
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÓñÏª[2;37;0m", ({ "yuxi" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[37mÉÏ¹Åº®Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹Ş×Ó(p357159_1)
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
