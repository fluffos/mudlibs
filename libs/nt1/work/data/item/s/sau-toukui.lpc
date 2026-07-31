// SN:8DhJ1noG2\niEAGL
// ITEM Made by player(白云:sau) /data/item/s/sau-toukui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 21 18:15:31 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m面具[2;37;0m", ({ "toukui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
头盔缘上刻着一行小字：白云(sau)
");
	set("value", 2100000);
	set("point", 231);
	set("material", "magic stone");
	set("wear_msg", "[1;36m$N戴上$n[1;36m，开始假扮千王之王。[2;37;0m\n");
	set("remove_msg", "[33m$N取下$n[33m，收入怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
