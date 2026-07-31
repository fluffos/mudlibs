// ITEM Made by player(Áú·É³½:w1045575408_1) /data/item/w/w1045575408_1-bxzx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:14:44 2023
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("±ùĞÄÕ½Ñ¥[2;37;0m", ({ "bxzx" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;37m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁú·É³½(w1045575408_1)
");
	set("value", 2100000);
	set("point", 88);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸±ùĞÄÕ½Ñ¥[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË±ùĞÄÕ½Ñ¥[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
