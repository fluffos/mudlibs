// SN:n43o<A@?gZmjhSck
// ITEM Made by player(白蕊儿:bairr) /data/item/b/bairr-blq.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 16 11:15:07 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m白莲旗[2;37;0m", ({ "blq" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
白莲教的旗帜。[2;37;0m
铁掌缘上刻着一行小字：白蕊儿(bairr)
");
	set("value", 2100000);
	set("point", 528);
	set("material", "magic stone");
	set("wear_msg", "$N举手一挥，一杆图标模样的小旗帜握在手中。[2;37;0m\n");
	set("remove_msg", "$N将小旗帜小心翼翼地卷起来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
