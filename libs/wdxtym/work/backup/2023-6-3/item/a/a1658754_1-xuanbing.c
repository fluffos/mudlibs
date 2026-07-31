// ITEM Made by player(¶ÉÌÆ:a1658754_1) /data/item/a/a1658754_1-xuanbing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 15:19:41 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ğş±ù[2;37;0m", ({ "xuanbing" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[37mÉÏ¹Åº®Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
±ùº®[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶ÉÌÆ(a1658754_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wield_msg", "É¢·¢º®Æø[2;37;0m\n");
	set("unwield_msg", "ËæÊÖÒ»»Ó£¬±ãÈëÇÊÄÚ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
