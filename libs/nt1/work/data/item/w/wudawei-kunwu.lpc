// SN:l:OKZF?9Ge1b3WH@
// ITEM Made by player(吴大为:wudawei) /data/item/w/wudawei-kunwu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 27 20:53:10 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("昆吾剑[2;37;0m", ({ "kunwu" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
神铁产自昆吾，故宝剑名曰昆吾剑。剑长七尺，色如赤火，上刻“君不见昆吾铁冶飞炎烟，红光紫气俱赫然”。[2;37;0m
剑柄上刻着一行小字：吴大为(wudawei)
");
	set("value", 2100000);
	set("point", 151);
	set("material", "magic stone");
	set("wield_msg", "刹那间，只见$N的身边周围被一团红光笼罩，脸色由红转紫，神色凝重，眼神中透出逼人的杀气。[2;37;0m\n");
	set("unwield_msg", "只见$N一口把昆吾剑吞下，得意洋洋的转身就走，却不知股后透出一尺剑尖，妈的，把戏穿帮了。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
