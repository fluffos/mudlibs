// cjgqian.c 武功秘籍库房
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"武功秘籍库房"NOR);
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。这个
房间里面放满了少林武僧从各地收集过来的武功秘籍。
LONG
	);

	set("exits", ([
		"east" : __DIR__"cjg1"
	]));

  set("level", 1);
	set("mark", "damagebook");

	setup();
}

#include "cjgkufang.h"