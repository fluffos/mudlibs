
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条上山的路。道路崎岖，非常难走。前面是一片树林。这
里冰雪已经很多了，一不小心，就会滑倒,北面传来一阵阵水鸣声。
LONG);

  set("exits", ([ 
 "northup":__DIR__"pubu",
 "up":__DIR__"shulin1",
 "westdown":__DIR__"shanlu1",
        ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

