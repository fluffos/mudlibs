// ITEM Made by player(µÈµÈ:a15976738848_1) /data/item/a/a15976738848_1-lup.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 16 14:06:25 2023
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÏÈÌìÂ«Åî[2;37;0m", ({ "lup" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[33mµÀĞÄ²»Ãğ£¬[1;32mÂ«Åî²»»Ù¡£
[1;36mÖÜ¶ø¸´Ê¼£¬Ñ­»·Íù¸´
[1;31mÓîÖæÃğ¶øÎÒ²»Ãğ£¡å¾Óî¼Å¶øÎÒ²»Ï¢£¡[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµÈµÈ(a15976738848_1)
");
	set("value", 200100000);
	set("point", 17600);
	set("material", "silk");
	set("wear_msg", "[33mµÀĞÄ²»Ãğ£¬[1;32mÂ«Åî²»»Ù¡£\n[1;36mÖÜ¶ø¸´Ê¼£¬Ñ­»·Íù¸´\n[1;31mÓîÖæÃğ¶øÎÒ²»Ãğ£¡å¾Óî¼Å¶øÎÒ²»Ï¢£¡[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁËÏÈÌìÂ«Åî[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
