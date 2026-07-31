// ITEM Made by player(ÓÀÒ¹:missed1_1) /data/item/m/missed1_1-missed.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 20:19:22 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÈÕÂÖµ¶[2;37;0m", ({ "missed" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓÀÒ¹(missed1_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "´«ËµÎ¨Ò»ÄÜÉËº¦ÎŞ²ÒµÄÎäÆ÷[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
