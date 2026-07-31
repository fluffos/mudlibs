// /u/beyond/hz/yaopu.c 药铺
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"万年春"NOR);
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个
小抽屉里散发出来的。药房先生坐在茶几旁，独自喝着茶，看也不看你一眼。
一名小伙计站在柜台后招呼着顾客。
LONG
	);
        set("objects",([
           __DIR__"npc/yplaoban" : 1,
           __DIR__"npc/huoji" : 1,
         ]));
	set("exits", ([
		"west" : __DIR__"qsddao5",
	]));
	set("coor/x",110);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}

