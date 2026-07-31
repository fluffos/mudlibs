// ITEM Made by player(¹Ş×Ó:p357159_1) /data/item/p/p357159_1-lxzy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 11 20:14:36 2023
#include <ansi.h>
#include <weapon.h>

inherit THROWING;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÁ÷ĞÇ×·ÔÂ[2;37;0m", ({ "lxzy" }));
	set_weight(2);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú°µÆ÷¡£
[1;33mĞÇ³½[1;31m°µÆ÷[1;33mÌ×Ö®Ò»¹²ÓĞÊ®Èı°Ñ[2;37;0m
°µÆ÷±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹Ş×Ó(p357159_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_throwing(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
