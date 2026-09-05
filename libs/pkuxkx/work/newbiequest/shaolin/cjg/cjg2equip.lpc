// cjgqian.c 器械库房
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"器械库房"NOR);
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。这个
房间里面放满了少林武僧从各地收集过来的神兵宝甲。
LONG
	);

	set("exits", ([
		"south" : __DIR__"cjg2"
	]));

  set("level", 2);
	set("mark", "equip");

	setup();
}

#include "cjgkufang.h"