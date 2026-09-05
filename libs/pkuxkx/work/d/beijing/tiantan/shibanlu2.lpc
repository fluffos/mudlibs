
// Room: /d/beijing/west/shibanlu2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"石板路"NOR);
	set("long",
HIC"这是一条青石板路，两边种了不少柏树，显得庄严肃穆。
往西走是西天门，北面是个花园，一阵阵浓郁的花香扑鼻
而来。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  	"north" : __DIR__"penshuichi",
  	"west" : __DIR__"shibanlu1",
  	"eastup" : __DIR__"danbiqiao",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/shibanlu2",1);
      }

}