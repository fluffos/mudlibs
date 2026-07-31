// SN:_:fd53EYYQk\_l8K
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 24 21:44:37 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m一弦一柱思华年[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;34m一枚古意盎然的戒指，上面刻满了岁月的沧桑，历史的流逝被这枚戒指一一记在心上。[2;37;0m
指套缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 786);
	set("material", "magic stone");
	set("wear_msg", "[1;34m$N戴上一枚古色古香的戒指在无名指上，她轻轻地转动着这枚戒指，仿佛转动着时间的轮盘。\n随着戒指的转动，周围陷入了一种朦朦的境界里面，在这里面大家想起了遥远的往事，并清楚的感觉到时间是怎样无情的飞速流逝。[2;37;0m\n");
	set("remove_msg", "[1;34m$N反向转动着无名指上的戒指，周围朦朦的境界于是慢慢变得清晰起来，大家的心神也自遥远的回忆中回归到现下的状态。\n$N见大家都回来了便取下戒指。只是一个个都恍然若失，思忖着：年华如此易逝，实在不必如此执着。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
