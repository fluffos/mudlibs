// ITEM Made by player(ÁÙ»ª:mmm9999_1) /data/item/m/mmm9999_1-zzz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May  2 07:08:51 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m×ÏÏ¼[2;37;0m", ({ "zzz" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[31mÎÒÕæÕæ°®µÄ×ÏÏ¼£¬²»ÖªµÀÔÚÄÄ£¿ÎÒÒ²²»ÖªºÎÈ¥ºÎ´Ó[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁÙ»ª(mmm9999_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[31mÈç¹ûÉÏÌìÔÙ¸øÎÒÒ»´Î»ú»á£¬ÎÒÒª´òÆÆÄ§Öä£¬»¹ÎÒ»¨¹ûÉ½Ò»¸öÇå¾»[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
