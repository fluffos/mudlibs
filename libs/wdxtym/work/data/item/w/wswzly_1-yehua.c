// ITEM Made by player(ÂåÖñ:wswzly_1) /data/item/w/wswzly_1-yehua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr  8 20:46:16 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÍòÒ¶[1;35m·É»¨[2;37;0m", ({ "yehua" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;35m´Ë½£Ò»³ö£¬ÖÜÔâ¶ÙÊ±¸¡ÏÖ³öÒ»×ùÁÉÀ«µÄÖñÁÖ£¬ÀïÃæ·ÉÎè×ÅÖñÒ¶ºÍÂä»¨£¬É·ÊÇºÃ¿´[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂåÖñ(wswzly_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;35m$NËæÊÖÒ»ÕĞ£¬ÍòÒ¶·É»¨ÁìÓò¶ÙÊ±¸¡ÏÖ[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
