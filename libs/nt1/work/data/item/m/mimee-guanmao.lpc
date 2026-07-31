// SN:;CQg1=BGX=7?[]i2
// ITEM Made by player(小达子:mimee) /data/item/m/mimee-guanmao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 17 16:02:05 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m一品顶带[2;37;0m", ({ "guanmao" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
一品大员的官帽，权威无比。[2;37;0m
头盔缘上刻着一行小字：小达子(mimee)
");
	set("value", 2100000);
	set("point", 77);
	set("material", "magic stone");
	set("wear_msg", "[1;31m$N带上一品官帽，人顿时神气了不少。[2;37;0m\n");
	set("remove_msg", "[1;31m$N将官帽脱了下来，人轻松了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
