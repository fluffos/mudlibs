// SN:dSgE9cE?DW\i[IW;
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-toukui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct  5 01:30:47 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m明月簪[2;37;0m", ({ "toukui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
这是胡小僧的发簪，色如[1;37m明月[2;37;0m，质地似玉非玉。[2;37;0m
头盔缘上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 87);
	set("material", "magic stone");
	set("wear_msg", "$N将$n轻轻插在头发上。[2;37;0m\n");
	set("remove_msg", "$N将$n取下，收入怀中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
