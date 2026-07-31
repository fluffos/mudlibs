// ITEM Made by player(ÁéÃÎ:bllm_1) /data/item/b/bllm_1-ren.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 23 10:49:24 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m¾å[1;31mÁ­[1;35mÆÆÈĞ[2;37;0m", ({ "ren" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
[1;32mËæ´¦¿É¼ûµÄ×¯Ô°¸î²İÁ­µ¶£¬[1;35mÓĞĞ©ÆÆËğ£¬»¹ÓĞ£¬[1;31mÑª×Õ£¿[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁéÃÎ(bllm_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
