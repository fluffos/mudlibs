// SN:`O=;AHP^c6T@Q;ek
// ITEM Made by player(明段:duanyu) /data/item/d/duanyu-blq.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 10 03:07:43 2004
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
铁掌缘上刻着一行小字：明段(duanyu)
");
	set("value", 2100000);
	set("point", 520);
	set("material", "magic stone");
	set("wear_msg", "段誉举手一挥，一杆图标模样的小旗帜握在手中。[2;37;0m\n");
	set("remove_msg", "段誉将小旗帜小心翼翼地卷起来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
