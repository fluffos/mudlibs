// ITEM Made by player(¶ÉÒ¹:like_1) /data/item/l/like_1-nig.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 18:14:33 2023
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÄı¹â[2;37;0m", ({ "nig" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶ÉÒ¹(like_1)
");
	set("value", 200100000);
	set("point", 17600);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m×°±¸[1;33mÄı¹â[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;33mÄı¹â[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
