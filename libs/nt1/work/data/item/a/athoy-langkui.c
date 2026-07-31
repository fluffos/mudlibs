// SN:_je1^jTJMdgg=cPX
// ITEM Made by player(神游:athoy) /data/item/a/athoy-langkui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 23 14:17:07 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m雪[1;31m狼盔[2;37;0m", ({ "langkui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 202);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m雪[1;31m狼盔[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m雪[1;31m狼盔[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
