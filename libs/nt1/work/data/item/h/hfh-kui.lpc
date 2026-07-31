// SN:KRCVk=Kk5Jb=`QU0
// ITEM Made by player(花非花:hfh) /data/item/h/hfh-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 27 22:09:06 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m白玉簪[2;37;0m", ({ "kui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：花非花(hfh)
");
	set("value", 2100000);
	set("point", 120);
	set("material", "magic stone");
	set("wear_msg", "[1;35m$N取出$n[1;35m，轻轻别在秀发上。[2;37;0m\n");
	set("remove_msg", "[1;36m$N从发上取下$n[1;36m，收入怀中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
