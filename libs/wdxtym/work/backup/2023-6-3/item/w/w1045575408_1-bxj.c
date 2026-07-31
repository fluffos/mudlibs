// ITEM Made by player(Áú·É³½:w1045575408_1) /data/item/w/w1045575408_1-bxj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 04:48:52 2023
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("±ùĞÄ¼×[2;37;0m", ({ "bxj" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[1;37m±ù²ÏË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁú·É³½(w1045575408_1)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸±ùĞÄ¼×[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË±ùĞÄ¼×[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
