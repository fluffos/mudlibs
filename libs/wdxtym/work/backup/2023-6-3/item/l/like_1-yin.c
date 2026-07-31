// ITEM Made by player(¶ÉÒ¹:like_1) /data/item/l/like_1-yin.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 10 19:29:40 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mÒõÑô[2;37;0m", ({ "yin" }));
	set_weight(225);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;37mÉñÔ´[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶ÉÒ¹(like_1)
");
	set("value", 70100000);
	set("point", 7700);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸[2;37;0m[35mÒõÑô[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[2;37;0m[35mÒõÑô[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
