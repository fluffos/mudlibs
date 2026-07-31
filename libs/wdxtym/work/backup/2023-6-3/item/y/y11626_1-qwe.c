// ITEM Made by player(·Ù¼Å:y11626_1) /data/item/y/y11626_1-qwe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 18:08:53 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("¹ÂÓ°[2;37;0m", ({ "qwe" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º·Ù¼Å(y11626_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "Ò»½£Ëªº®Ê®ËÄÖİ[2;37;0m\n");
	set("unwield_msg", "Ê®²½É±Ò»ÈË[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
