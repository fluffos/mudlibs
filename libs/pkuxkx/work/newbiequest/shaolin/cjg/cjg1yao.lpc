// cjgqian.c 普通丹药库房
// seagate@pkuxkx by 2011.02.17
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"丹药库房"NOR);
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。这个
房间里面放满了少林秘制的疗伤圣药。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"cjg1"
	]));

  set("level", 1);
  set("mark", "lyao");

	setup();
}

#include "cjgkufang.h"