// ITEM Made by player(Áú·É³½:w1045575408_1) /data/item/w/w1045575408_1-bxht.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:12:14 2023
#include <ansi.h>
#include <armor.h>

inherit PANTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("±ùĞÄ»¤ÍÈ[2;37;0m", ({ "bxht" }));
	set_weight(700);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[1;37m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ìõ¿ã×Ó¡£
¿ã×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁú·É³½(w1045575408_1)
");
	set("value", 2100000);
	set("point", 110);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸±ùĞÄ»¤ÍÈ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË±ùĞÄ»¤ÍÈ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
