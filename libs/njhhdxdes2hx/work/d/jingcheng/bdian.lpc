#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"刘家绢帛店"NOR);
	set("long", @LONG
这里的东西都相当不错，城里的太太小姐多来这里买衣服。逢年过节
来光顾的人就更多了。屋中横放一张七尺多长的柜台，柜台后的架子
上是一匹匹的布料和成衣．
LONG         
	);

	set("exits", ([ 
 "south" :__DIR__"zhq1",
	]));
      set("objects", ([
                __DIR__"npc/liuerniang" : 1,
  ]));
	setup();
	replace_program(ROOM);
}

