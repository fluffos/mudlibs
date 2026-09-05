//xiaowu.c -- 小屋
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"小屋"NOR);
  set("long", @LONG
看起来这里原先是堆放杂物的小屋，但现在屋子的中间已经被收拾干
净。一个小炉子放在地上，火还生着，上面架着口锅，还在呼呼地冒着热
气。一股酒肉之气，弥漫在空中。

LONG
  );

  set("exits", ([     
      "north" : __DIR__"xiaoyuan",   
  ]));
/*
	set("objects", ([
		__DIR__"npc/fanbang-wushi" : 2,
	]));
*/
  setup();
}

void init()
{
	add_action("do_nothing", "nothing");
}

int do_nothing()
{
	
	return 1;
}
