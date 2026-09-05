#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"飞马镖局"NOR);
	set("long", @LONG
这是一家镖局，上面一个牌匾草书，“飞马镖局”四字，年代比较久远了。
LONG
	);

  set("exits", ([                
      "north" : __DIR__"weststreet-3",
  ]));
  
  set("no_task",1);
  set("objects", ([
	    __DIR__"npc/biaojunpc" : 1,
  ]));
  
  set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        
	setup();
}



