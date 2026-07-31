// SN:C<XeLlJIh=k8NX<j
// ITEM Made by player(琴岛:qdao) /data/item/q/qdao-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 21 15:05:50 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m江南[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;36m风到这里就是粘，粘住过客的思念[2;37;0m
指套缘上刻着一行小字：琴岛(qdao)
");
	set("value", 2100000);
	set("point", 839);
	set("material", "magic stone");
	set("wear_msg", "[37m我在身边就是缘，缘分写在三生石上面[2;37;0m\n");
	set("remove_msg", "[36m爱有万分之一天，宁愿我就葬在这一天[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
