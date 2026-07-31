// SN:YJh^8ao8HHQ[fJEU
// ITEM Made by player(默默:wuy) /data/item/w/wuy-zhu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 19 21:46:06 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m蜘蛛网[2;37;0m", ({ "zhu" }));
	set_weight(1440);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一条腰带。
[1;35m一条用银丝和珍珠编制而成的腰带。如同蜘蛛编成的网。[2;37;0m
腰带缘上刻着一行小字：默默(wuy)
");
	set("value", 1500000);
	set("point", 51);
	set("material", "silk");
	set("wear_msg", "[1;35m蜘蛛编好网，等待着猎物靠近。[2;37;0m\n");
	set("remove_msg", "[1;35m当猎物落网，蜘蛛慢慢靠近，百发百中的吃掉猎物。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
