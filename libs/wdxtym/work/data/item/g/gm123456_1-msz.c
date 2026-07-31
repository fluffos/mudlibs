// ITEM Made by player(ÎŞÓû:gm123456_1) /data/item/g/gm123456_1-msz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr  9 18:41:35 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ä§ÊÖ[2;37;0m", ({ "msz" }));
	set_weight(0);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎŞÓû(gm123456_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸Ä§ÊÖ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁËÄ§ÊÖ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
